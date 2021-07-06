import os
import sys
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from utils import create_dir, round_down, get_time
import copy
from math import floor
from datetime import datetime, timedelta
import matplotlib.pyplot as plt
from scipy.signal import butter, lfilter
from scipy import signal
import pandas as pd
import numpy as np
import pyedflib
import scipy
from scipy.io import loadmat
import os


# ------------------------------------------------------------------------------
# Generic Parameters
# ------------------------------------------------------------------------------
n_channels = 22
sample_rate = 256  # Sample rate (Hz)
window_size = 64  # Window size (seconds)
# # Stride length (seconds) used to generate synthetic preictal and ictal samples ------------- To be implemented
# stride_len = 1
# Data directory path
data_dir = "E:/ieeg-swez.ethz.ch/"
processed_data_dir = "processed_data"  # Processed data output directory path
patients = np.arange(1, 19)
# ------------------------------------------------------------------------------
# Detection-specific Parameters
# ------------------------------------------------------------------------------
ictal_interval_padding_duration = 32
# ------------------------------------------------------------------------------
# Prediction-specific Parameters
# ------------------------------------------------------------------------------
seizure_occurance_period = 30  # Seizure occurrence period (minutes)
seizure_prediction_horizon = 5  # Seizure prediction horizon (minutes)
# ------------------------------------------------------------------------------
extract_ictal_samples = True
extract_preictal_samples = True
# ------------------------------------------------------------------------------

print(patients)
exit(0)


def extract_interval_data(
    patient,
    data_dir,
    extract_ictal_samples=False,
    extract_preictal_samples=True,
    ictal_interval_padding_duration=32,
    seizure_occurance_period=30,
    seizure_prediction_horizon=5,
    n_interictal_files=10,
):
    """Method to extract interval patient data."""
    patient_summary = loadmat(
        os.path.join(data_dir, "ID%02d" % patient, "ID%02d_info.mat" % patient)
    )
    interictal_intervals = []
    interictal_files = []
    ictal_intervals = []
    ictal_files = []
    preictal_intervals = []
    preictal_files = []
    seizure_begin_timestamps = np.array(
        patient_summary["seizure_begin"]).flatten()
    seizure_end_timestamps = np.array(patient_summary["seizure_end"]).flatten()
    assert len(seizure_begin_timestamps) == len(seizure_end_timestamps)
    n_seizures = len(seizure_begin_timestamps)
    active_files = []
    # Extract ictal and preictal interval data
    for seizure_idx in range(n_seizures):
        seizure_begin = seizure_begin_timestamps[seizure_idx]
        seizure_end = seizure_end_timestamps[seizure_idx]
        files_idx = [int(seizure_begin / 3600 + 1)]
        active_files.append(files_idx)
        if extract_ictal_samples:
            # Extract ictal interval data
            interval_start = int(seizure_begin)
            interval_end = int(seizure_end)
            if (len(ictal_intervals) == 0 or interval_start >= 0) and timedelta(
                seconds=interval_start
            ) > timedelta(minutes=20):
                ictal_intervals.append(
                    [
                        int(
                            (
                                timedelta(seconds=interval_start)
                                - timedelta(seconds=ictal_interval_padding_duration)
                            ).total_seconds()
                        ),
                        int(
                            (
                                timedelta(seconds=interval_end)
                                + timedelta(seconds=ictal_interval_padding_duration)
                            ).total_seconds()
                        ),
                    ]
                )
                files = []
                for file_idx in files_idx:
                    files.append(
                        [
                            (file_idx - 1) * 3600,
                            file_idx * 3600 - 1,
                            "ID%02d_%dh.mat" % (patient, file_idx),
                        ]
                    )

                ictal_files.append(files)

        if extract_preictal_samples:
            # Extract preictal interval data
            interval_start = int(
                seizure_begin
                - timedelta(
                    minutes=seizure_prediction_horizon + seizure_occurance_period
                ).total_seconds()
            )
            interval_end = int(
                interval_start
                + timedelta(minutes=seizure_occurance_period).total_seconds()
            )
            while interval_start < (files_idx[0] - 1) * 3600:
                files_idx.append(files_idx[0] - 1)
                active_files.append(files_idx)
                files_idx.sort(reverse=False)

            while interval_end > files_idx[-1] * 3600:
                files_idx.append(files_idx[-1] + 1)
                active_files.append(files_idx)
                files_idx.sort(reverse=False)

            if (len(ictal_intervals) == 0 or interval_start >= 0) and timedelta(
                seconds=interval_start
            ) > timedelta(minutes=20):
                preictal_intervals.append([interval_start, interval_end])
                files = []
                for file_idx in files_idx:
                    files.append(
                        [
                            (file_idx - 1) * 3600,
                            file_idx * 3600 - 1,
                            "ID%02d_%dh.mat" % (patient, file_idx),
                        ]
                    )

                preictal_files.append(files)

        # Extract interictal interval data
        active_files = np.unique(np.array(active_files).flatten())
        interictal_file_idx = 1
        interictal_files_used = 0
        while interictal_files_used < n_interictal_files:
            if interictal_file_idx not in active_files:
                interictal_intervals.append(
                    [(file_idx - 1) * 3600, file_idx * 3600])
                interictal_files.append(
                    [
                        (file_idx - 1) * 3600,
                        file_idx * 3600,
                        "ID%02d_%dh.mat" % (patient, interictal_file_idx),
                    ]
                )

            interictal_file_idx += 1

    return (
        interictal_intervals,
        interictal_files,
        ictal_intervals,
        ictal_files,
        preictal_intervals,
        preictal_files,
    )


def load_patient_data(patient, files, data_dir, n_channels=22, sample_rate=256):
    """Method to load patient data."""
    data = None
    for file in files:
        data_ = loadmat("%sID%02d/%s" % (data_dir, patient, file[2]))["EEG"][
            0:n_channels
        ][:]
        data_ = scipy.signal.resample(data_, 3600 * sample_rate, axis=1)
        if data is None:
            data = data_
        else:
            data = np.concatenate((data, data_), axis=1)

    return data


def extract_batches_from_interval(
    patient,
    data_dir,
    files,
    files_start,
    files_end,
    interval_start,
    interval_end,
    segment_index,
    sample_rate,
    window_size,
    n_channels,
):
    """Method to extract batch samples from specified intervals."""
    start = (interval_start - files_start) * sample_rate
    if files_end <= interval_end:
        end = -1
        data = load_patient_data(patient, files, data_dir)[:, start:]
    else:
        end = ((interval_end - files_start) * sample_rate) + 1
        data = load_patient_data(patient, files, data_dir)[:, start: end + 1]

    if (data.shape[0] >= n_channels) and (
        data.shape[1] >= sample_rate * window_size * len(files)
    ):
        truncated_len = round_down(data.shape[1], sample_rate * window_size)
        return (
            np.array(
                np.split(
                    data[0:n_channels, 0:truncated_len],
                    truncated_len / (sample_rate * window_size),
                    axis=1,
                )
            ).swapaxes(0, 1),
            segment_index,
        )
    else:
        return np.array([]), segment_index


def extract_batches(
    patient,
    files,
    data_dir,
    segment_index,
    intervals,
    sample_rate,
    window_size,
    n_channels,
):
    """Method to extract batches."""
    files_start = files[0][0]
    files_end = files[-1][1]
    interval_start = intervals[segment_index][0]
    interval_end = intervals[segment_index][1]
    while files_start > interval_end and segment_index < len(intervals) - 1:
        segment_index += 1
        interval_start = intervals[segment_index][0]
        interval_end = intervals[segment_index][1]

    if (interval_end - interval_start) >= window_size:
        return extract_batches_from_interval(
            patient,
            data_dir,
            files,
            files_start,
            files_end,
            interval_start,
            interval_end,
            segment_index,
            sample_rate,
            window_size,
            n_channels,
        )
    else:
        return np.array([]), segment_index


n_channels = 22
(
    interictal_intervals,
    interictal_files,
    ictal_intervals,
    ictal_files,
    preictal_intervals,
    preictal_files,
) = extract_interval_data(1, "E:/ieeg-swez.ethz.ch/", True, True)

# data, idx = extract_batches(
#     1, ictal_files[0], "E:/ieeg-swez.ethz.ch/", 0, ictal_intervals, 256, 64, 22)
# print(data.shape)
# print(idx)

# data, idx = extract_batches(
#     1, preictal_files[0], "E:/ieeg-swez.ethz.ch/", 0, preictal_intervals, 256, 64, 22)
# print(data.shape)
# print(idx)

# data, idx = extract_batches(
#     1,
#     interictal_files[0],
#     "E:/ieeg-swez.ethz.ch/",
#     0,
#     interictal_intervals,
#     256,
#     64,
#     22,
# )
# print(data.shape)
# print(idx)
