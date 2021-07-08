import pyedflib
import numpy as np
import pandas as pd
from scipy import signal
from scipy.signal import butter, lfilter
import matplotlib.pyplot as plt
from datetime import datetime, timedelta
import os
from utils import create_dir
import glob


# ------------------------------------------------------------------------------
n_channels = 22
sample_rate = 256  # Sample rate (Hz)
window_size = 64  # Window size (seconds)
processed_data_dir = "processed_data"  # Processed data output directory path
# Spectogram output directory path
spectogram_output_dir = "processed_data/spectograms"
# ------------------------------------------------------------------------------


def bandstop_filter(data, f_l, f_h, sample_rate, order=5):
    """Method to emulate a bandstop filter."""
    nyquist_rate = 0.5 * sample_rate
    b, a = butter(order, [f_l / nyquist_rate, f_h /
                  nyquist_rate], btype="bandstop")
    return lfilter(b, a, data)


def highpass_filter(data, f_h, sample_rate, order=5):
    """Method to emulate a highpass filter."""
    nyquist_rate = 0.5 * sample_rate
    b, a = butter(order, f_h / nyquist_rate, btype="high", analog=False)
    return lfilter(b, a, data)


def save_spectograms(
    spectograms, file, spectogram_output_dir
):
    """Method to save spectrograms to disk."""
    np.save(
        os.path.join(
            spectogram_output_dir, os.path.basename(file),
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
    Pxx = np.delete(Pxx, np.s_[117: 123 + 1], axis=0)
    Pxx = np.delete(Pxx, np.s_[57: 63 + 1], axis=0)
    Pxx = np.delete(Pxx, 0, axis=0)
    result = (
        10 * np.log10(np.transpose(Pxx)) -
        (10 * np.log10(np.transpose(Pxx))).min()
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
    files = glob.glob(os.path.join(processed_data_dir, "*.npy"))
    for file in files:
        print(file)
        try:
            spectogram_index = 0
            data = np.load(file)
            spectograms = None
            for sample in range(data.shape[1]):
                sample_spectograms, spectogram_index = gen_spectograms(
                    data[:, sample, :],
                    sample_rate,
                    window_size,
                    n_channels,
                    debug_plots=False,
                )
                if spectograms is None:
                    spectograms = sample_spectograms
                else:
                    spectograms = np.concatenate(
                        (spectograms, sample_spectograms), axis=0
                    )

            print(spectograms.shape)
            save_spectograms(
                spectograms,
                file,
                spectogram_output_dir=spectogram_output_dir,
            )
            del spectograms
        except Exception as e:
            print("File: %s Failed" % file)
            print(e)
