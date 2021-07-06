import pyedflib
import numpy as np
import pandas as pd
from scipy import signal
from scipy.signal import butter, lfilter
import matplotlib.pyplot as plt
from datetime import datetime, timedelta
import os
from utils import create_dir


# ------------------------------------------------------------------------------
n_channels = 22
sample_rate = 256  # Sample rate (Hz)
window_size = 64  # Window size (seconds)
# Data directory path
data_dir = "/scratch/jcu/cl/CHBMIT/chb-mit-scalp-eeg-database-1.0.0/"
processed_data_dir = "processed_data"  # Processed data output directory path
# Spectogram output directory path
spectogram_output_dir = "processed_data/spectograms"
patients = np.arange(1, 24)
# Remove patients 4, 6, 7, 12, and 20, as their records contain anomalous data
patients = np.delete(patients, [3, 5, 6, 11, 19])
# ------------------------------------------------------------------------------


def bandstop_filter(data, f_l, f_h, sample_rate, order=5):
    """Method to emulate a bandstop filter."""
    nyquist_rate = 0.5 * sample_rate
    b, a = butter(order, [f_l / nyquist_rate, f_h / nyquist_rate], btype="bandstop")
    return lfilter(b, a, data)


def highpass_filter(data, f_h, sample_rate, order=5):
    """Method to emulate a highpass filter."""
    nyquist_rate = 0.5 * sample_rate
    b, a = butter(order, f_h / nyquist_rate, btype="high", analog=False)
    return lfilter(b, a, data)


def save_spectograms(
    patient, spectograms, is_ictal, is_synthetic, spectogram_output_dir
):
    """Method to save spectrograms to disk."""
    if is_ictal:
        class_label = "ictal"
    else:
        class_label = "interictal"

    if is_synthetic:
        synthetic_label = "_synthetic"
    else:
        synthetic_label = ""

    np.save(
        os.path.join(
            spectogram_output_dir,
            "patient_%02d%s_%s" % (patient, synthetic_label, class_label),
        ),
        spectograms,
    )


def gen_spectograms(
    data, sample_rate, window_size, n_channels, spectogram_index=0, debug_plots=False
):
    """Method to segment data into windows and to create spectograms."""
    spectograms = []
    start = 0
    stop = window_size * sample_rate
    while stop <= data.shape[1]:
        spectograms.append([])
        for i in range(0, n_channels):
            spectograms[spectogram_index].append(
                gen_spectogram(
                    data[i, start:stop], sample_rate, window_size, debug_plots
                )
            )

        start = stop + 1
        stop = start + window_size * sample_rate
        spectogram_index += 1

    spectograms = np.array(spectograms)
    return spectograms, spectogram_index


def gen_spectogram(data, sample_rate, window_size, debug_plot):
    """Method to create a spectogram."""
    y = bandstop_filter(data, 117, 123, sample_rate, order=6)
    y = bandstop_filter(y, 57, 63, sample_rate, order=6)
    y = highpass_filter(y, 1, sample_rate, order=6)
    frequencies, bins, Pxx = signal.spectrogram(
        y, nfft=sample_rate, fs=sample_rate, return_onesided=True, noverlap=128
    )
    Pxx = np.delete(Pxx, np.s_[117 : 123 + 1], axis=0)
    Pxx = np.delete(Pxx, np.s_[57 : 63 + 1], axis=0)
    Pxx = np.delete(Pxx, 0, axis=0)
    result = (
        10 * np.log10(np.transpose(Pxx)) - (10 * np.log10(np.transpose(Pxx))).min()
    ) / (10 * np.log10(np.transpose(Pxx))).ptp()
    if debug_plot:
        plt.figure(1)
        frequencies = np.arange(result.shape[1])
        plt.pcolormesh(frequencies, bins, result, cmap=plt.cm.jet)
        plt.colorbar()
        plt.ylabel("Time (s)")
        plt.xlabel("Frequency (Hz)")
        plt.show()

    return result


if __name__ == "__main__":
    for patient in patients:
        try:
            print("Patient: %02d" % patient)
            spectogram_index = 0
            patient_data = [
                os.path.join(processed_data_dir, "patient_%02d_ictal.npy" % patient),
                os.path.join(
                    processed_data_dir, "patient_%02d_synthetic_ictal.npy" % patient
                ),
                os.path.join(
                    processed_data_dir, "patient_%02d_interictal.npy" % patient
                ),
            ]

            for idx, file in enumerate(patient_data):
                data = np.load(file)
                spectrograms = None
                for sample in range(data.shape[1]):
                    sample_spectograms, spectogram_index = gen_spectograms(
                        data[:, sample, :],
                        sample_rate,
                        window_size,
                        n_channels,
                        debug_plots=False,
                    )
                    if spectrograms is None:
                        spectrograms = sample_spectograms
                    else:
                        spectrograms = np.concatenate(
                            (spectrograms, sample_spectograms), axis=0
                        )

                print(spectrograms.shape)
                save_spectograms(
                    patient,
                    sample_rate,
                    is_ictal=idx < 2,
                    is_synthetic=idx == 1,
                    spectogram_output_dir=spectogram_output_dir,
                )
        except Exception as e:
            print("Patient: %02d Failed" % patient)
            print(e)
