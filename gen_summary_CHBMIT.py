import pyedflib
import numpy as np
import pandas as pd
from scipy import signal
from scipy.signal import butter, lfilter
import matplotlib.pyplot as plt
from datetime import datetime, timedelta
import os
from math import floor
import copy
from utils import create_dir, round_down, get_time


# ------------------------------------------------------------------------------
# Generic Parameters
# ------------------------------------------------------------------------------
n_channels = 22
sample_rate = 256  # Sample rate (Hz)
window_size = 64  # Window size (seconds)
# Stride length (seconds) used to generate synthetic preictal and ictal samples
stride_len = 32
# Data directory path
# data_dir = "/scratch/jcu/cl/CHBMIT/chb-mit-scalp-eeg-database-1.0.0/"
data_dir = "E:/chbmit-1.0.0.physionet.org/"
patients = [1, 2, 3, 5, 8]
# ------------------------------------------------------------------------------
# Prediction-specific Parameters
# ------------------------------------------------------------------------------
seizure_occurance_period = 30  # Seizure occurrence period (minutes)
seizure_prediction_horizon = 5  # Seizure prediction horizon (minutes)
# ------------------------------------------------------------------------------
extract_ictal_samples = False
extract_preictal_samples = True
generate_synthetic_samples = True
# ------------------------------------------------------------------------------


def extract_interval_data(
    patient,
    data_dir,
    ictal_interval_padding_duration=32,
    seizure_occurance_period=30,
    seizure_prediction_horizon=5,
):
    """Method to extract interval patient data."""
    patient_summary = open(
        os.path.join(data_dir, "chb%02d" %
                     patient, "chb%02d-summary.txt" % patient),
        "r",
    )
    interictal_intervals = []
    interictal_files = []
    ictal_intervals = []
    ictal_files = []
    preictal_intervals = []
    preictal_files = []
    line = patient_summary.readline()
    start_time = datetime.min
    old_time = datetime.min
    line_number = 0
    while line:
        line_data = line.split(":")
        if line_data[0] == "File Name":
            file_name = line_data[1].strip()
            s = get_time(patient_summary.readline().split(": ")[1].strip())
            if line_number == 0:
                start_time = s

            while s < old_time:
                s += timedelta(hours=24)

            old_time = s
            end_time_file = get_time(
                patient_summary.readline().split(": ")[1].strip())
            while end_time_file < old_time:
                end_time_file = end_time_file + timedelta(hours=24)

            old_time = end_time_file
            n_seizures = int(patient_summary.readline().split(": ")[1])
            if n_seizures == 0:
                # Extract interictal interval data
                interictal_intervals.append([s, end_time_file])
                interictal_files.append([s, end_time_file, file_name])
            else:
                # Extract ictal and preictal interval data
                for i in range(0, n_seizures):
                    seconds_start = int(
                        patient_summary.readline().split(": ")[1].split(" ")[0]
                    )
                    seconds_end = int(
                        patient_summary.readline().split(": ")[1].split(" ")[0]
                    )
                    if extract_ictal_samples:
                        # Extract ictal interval data
                        interval_start = s + timedelta(seconds=seconds_start)
                        if (
                            len(ictal_intervals) == 0 or interval_start > datetime.min
                        ) and interval_start - start_time > timedelta(minutes=20):
                            interval_end = s + timedelta(seconds=seconds_end)
                            ictal_intervals.append(
                                [
                                    interval_start
                                    - timedelta(
                                        seconds=ictal_interval_padding_duration
                                    ),
                                    interval_end
                                    + timedelta(
                                        seconds=ictal_interval_padding_duration
                                    ),
                                ]
                            )
                            ictal_files.append([s, end_time_file, file_name])
                    if extract_preictal_samples:
                        # Extract preictal interval data
                        interval_start = (
                            s
                            + timedelta(seconds=seconds_start)
                            - timedelta(
                                minutes=seizure_prediction_horizon
                                + seizure_occurance_period
                            )
                        )
                        if (
                            len(preictal_intervals) == 0
                            or interval_start > datetime.min
                        ) and interval_start - start_time > timedelta(minutes=20):
                            interval_end = interval_start + timedelta(
                                minutes=seizure_occurance_period
                            )
                            preictal_intervals.append(
                                [interval_start, interval_end])
                            preictal_files.append(
                                [s, end_time_file, file_name])

        line = patient_summary.readline()
        line_number += 1

    patient_summary.close()
    return (
        interictal_intervals,
        interictal_files,
        ictal_intervals,
        ictal_files,
        preictal_intervals,
        preictal_files,
    )


def load_patient_data(patient, file, data_dir):
    """Method to load patient data."""
    f = pyedflib.EdfReader("%schb%02d/%s" % (data_dir, patient, file))
    n = f.signals_in_file
    signals = np.zeros((n, f.getNSamples()[0]))
    for i in np.arange(n):
        signals[i, :] = f.readSignal(i)

    return signals


def extract_batches_from_interval(
    patient,
    data_dir,
    file,
    file_start,
    file_end,
    interval_start,
    interval_end,
    segment_index,
    n_channels,
):
    """Method to extract batch samples from specified intervals."""
    start = (interval_start - file_start).seconds * sample_rate
    if file_end <= interval_end:
        end = -1
        data = load_patient_data(patient, file[2], data_dir)[:, start:]
    else:
        end = ((interval_end - file_start).seconds * sample_rate) + 1
        data = load_patient_data(patient, file[2], data_dir)[:, start: end + 1]

    if (data.shape[0] >= n_channels) and (data.shape[1] >= sample_rate * window_size):
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
    file,
    data_dir,
    segment_index,
    intervals,
    sample_rate,
    window_size,
    n_channels,
):
    """Method to extract batches."""
    file_start = file[0]
    file_end = file[1]
    interval_start = intervals[segment_index][0]
    interval_end = intervals[segment_index][1]
    while file_start > interval_end and segment_index < len(intervals) - 1:
        segment_index += 1
        interval_start = intervals[segment_index][0]
        interval_end = intervals[segment_index][1]

    if (interval_end - interval_start).seconds >= window_size:
        return extract_batches_from_interval(
            patient,
            data_dir,
            file,
            file_start,
            file_end,
            interval_start,
            interval_end,
            segment_index,
            n_channels,
        )
    else:
        return np.array([]), segment_index


def gen_synthetic_batches(
    patient,
    file,
    data_dir,
    segment_index,
    intervals,
    sample_rate,
    window_size,
    stride_len,
    n_channels,
):
    """Method to generate synthetic batches."""
    file_start = file[0]
    file_end = file[1]
    interval_start = intervals[segment_index][0]
    interval_end = intervals[segment_index][1]
    while file_start > interval_end and segment_index < len(intervals) - 1:
        segment_index += 1
        interval_start = intervals[segment_index][0]
        interval_end = intervals[segment_index][1]

    if (interval_end - interval_start).seconds > window_size:
        synthetic_batches = np.array([]).reshape(
            n_channels, 0, sample_rate * window_size
        )
        synthetic_interval_start = interval_start + \
            timedelta(seconds=stride_len)
        synthetic_interval_end = synthetic_interval_start + timedelta(
            seconds=window_size
        )
        while synthetic_interval_end < interval_end:
            extracted_batches = extract_batches_from_interval(
                patient,
                data_dir,
                file,
                file_start,
                file_end,
                synthetic_interval_start,
                synthetic_interval_end,
                segment_index,
                n_channels,
            )[0]
            if extracted_batches.size > 0:
                synthetic_batches = np.concatenate(
                    (synthetic_batches, extracted_batches), axis=1
                )
            synthetic_interval_start += timedelta(seconds=stride_len)
            synthetic_interval_end += timedelta(seconds=stride_len)

        return synthetic_batches, segment_index
    else:
        return np.array([]), segment_index


if __name__ == "__main__":
    df = pd.DataFrame(columns=['patient', 'n_seizures', 'interictal_hours', 'preictal_hours',
                      'interictal_samples', 'preictal_samples', 'synthetic_preictal_samples'])
    for patient in patients:
        print("Patient: %02d" % patient)
        (
            interictal_intervals,
            interictal_files,
            ictal_intervals,
            ictal_files,
            preictal_intervals,
            preictal_files,
        ) = extract_interval_data(
            patient,
            data_dir,
            seizure_occurance_period,
            seizure_prediction_horizon,
        )
        if patient == 19:
            # Disregard the first seizure of patient 19 because it is not considered
            preictal_intervals.pop(0)

        interictal_segment_index = 0
        preictal_segment_index = 0
        synthetic_preictal_segment_index = 0
        n_interictal_samples = 0
        n_preictal_samples = 0
        n_synthetic_preictal_samples = 0
        # Extract interictal samples (batches)
        for file in interictal_files:
            data, interictal_segment_index = extract_batches(
                patient,
                file,
                data_dir,
                interictal_segment_index,
                interictal_intervals,
                sample_rate,
                window_size,
                n_channels,
            )
            if data.size > 0:
                n_interictal_samples += data.shape[1]

        # Extract preictal samples (batches)
        for file in preictal_files:
            data, preictal_segment_index = extract_batches(
                patient,
                file,
                data_dir,
                preictal_segment_index,
                preictal_intervals,
                sample_rate,
                window_size,
                n_channels,
            )
            if data.size > 0:
                n_preictal_samples += data.shape[1]

        n_seizures = len(preictal_intervals)

        # Generate synthetic preictal samples (batches)
        for file in preictal_files:
            data, synthetic_preictal_segment_index = gen_synthetic_batches(
                patient,
                file,
                data_dir,
                synthetic_preictal_segment_index,
                preictal_intervals,
                sample_rate,
                window_size,
                stride_len,
                n_channels,
            )
            if data.size > 0:
                n_synthetic_preictal_samples += data.shape[1]

        df = df.append({'patient': patient, 'n_seizures': n_seizures, 'interictal_hours': n_interictal_samples * window_size / 3600, 'preictal_hours': n_preictal_samples * window_size / 3600, 'interictal_samples': n_interictal_samples,
                       'preictal_samples': n_preictal_samples, 'synthetic_preictal_samples': n_synthetic_preictal_samples}, ignore_index=True)

        df.to_csv('summary_CHBMIT.csv', index=False)
