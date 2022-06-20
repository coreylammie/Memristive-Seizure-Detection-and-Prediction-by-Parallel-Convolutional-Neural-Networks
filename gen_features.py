import numpy as np
import pandas as pd
import itertools
from scipy.signal import hilbert
from scipy.stats import kurtosis
from scipy.stats import skew
from scipy.fftpack import fft
import os
from utils import create_dir
import math
import glob

# ------------------------------------------------------------------------------
n_channels = 22
sample_rate = 256  # Sample rate (Hz)
window_size = 64  # Window size (seconds)
processed_data_dir = "processed_data"  # Processed data output directory path
# Spectogram output directory path
feature_output_dir = "processed_data/features"
# ------------------------------------------------------------------------------


def det_entropy(channel_data):
    z = np.absolute(channel_data)
    entropy = 0
    for i in range(len(channel_data)):
        entropy = entropy + (z[i] * (math.log(z[i], 2)))
    return -1 * entropy


def gen_time_domain_features(data):
    features = np.array([])
    for channel in range(data.shape[0]):
        channel_data = np.absolute(data[channel])
        # Stastical moments: Mean, Variance, Skewness, Kurtosis, Coefficient of variation of EEG Signal
        features = np.append(features, np.mean(channel_data))
        features = np.append(features, np.var(channel_data))
        features = np.append(features, skew(channel_data))
        features = np.append(features, kurtosis(channel_data))
        features = np.append(features, (math.sqrt(features[1]) // features[0]))
        # Median absolute deviation of EEG Amplitude and Root Mean Square Amplitude
        features = np.append(features, np.mean(
            np.absolute(data - np.mean(data))))
        features = np.append(features, np.sqrt(np.mean(channel_data ** 2)))
        # Shanon Entropy
        features = np.append(features, det_entropy(channel_data))

    return features.flatten()


def save_features(features, file, feature_output_dir):
    """Method to save features to disk."""
    np.save(
        os.path.join(
            feature_output_dir, os.path.basename(file),
        ),
        features,
    )


if __name__ == "__main__":
    files = glob.glob(os.path.join(processed_data_dir, "*.npy"))
    for file in files:
        print(file)
        try:
            data = np.load(file)
            features = None
            for sample in range(data.shape[1]):
                sample_features = np.expand_dims(
                    gen_time_domain_features(data[:, sample, :]), axis=0
                )
                if features is None:
                    features = sample_features
                else:
                    features = np.concatenate(
                        (features, sample_features), axis=0)

            print(features.shape)
            save_features(
                features, file, feature_output_dir=feature_output_dir,
            )
            del features
        except Exception as e:
            print("File: %s Failed" % file)
            print(e)
