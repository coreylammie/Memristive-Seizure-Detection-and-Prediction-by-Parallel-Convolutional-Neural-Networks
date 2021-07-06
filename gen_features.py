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

# ------------------------------------------------------------------------------
n_channels = 22
# Data directory path
# data_dir = "/scratch/jcu/cl/CHBMIT/chb-mit-scalp-eeg-database-1.0.0/"
data_dir = "E:\chbmit-1.0.0.physionet.org/"
processed_data_dir = "processed_data"  # Processed data output directory path
# Feature output directory path
feature_output_dir = "processed_data/features"
# patients = np.arange(1, 24)
# Remove patients 4, 6, 7, 12, and 20, as their records contain anomalous data
# patients = np.delete(patients, [3, 5, 6, 11, 19])
patients = [1]
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
        features = np.append(features, np.mean(np.absolute(data - np.mean(data))))
        features = np.append(features, np.sqrt(np.mean(channel_data ** 2)))
        # Shanon Entropy
        features = np.append(features, det_entropy(channel_data))

    return features.flatten()


def save_features(patient, features, is_ictal, is_synthetic, feature_output_dir):
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
            feature_output_dir,
            "patient_%02d%s_%s" % (patient, synthetic_label, class_label),
        ),
        features,
    )


if __name__ == "__main__":
    for patient in patients:
        # try:
        print("Patient: %02d" % patient)
        patient_data = [
            os.path.join(processed_data_dir, "patient_%02d_ictal.npy" % patient),
            os.path.join(
                processed_data_dir, "patient_%02d_synthetic_ictal.npy" % patient
            ),
            os.path.join(processed_data_dir, "patient_%02d_interictal.npy" % patient),
        ]

        for idx, file in enumerate(patient_data):
            data = np.load(file)
            features = None
            for sample in range(data.shape[1]):
                sample_features = np.expand_dims(
                    gen_time_domain_features(data[:, sample, :]), axis=0
                )
                if features is None:
                    features = sample_features
                else:
                    features = np.concatenate((features, sample_features), axis=0)

            print(features.shape)
            save_features(
                patient,
                features,
                is_ictal=idx < 2,
                is_synthetic=idx == 1,
                feature_output_dir=feature_output_dir,
            )
        # except Exception as e:
        #     print("Patient: %02d Failed" % patient)
        #     print(e)

    # data = np.load("processed_data/patient_05_ictal.npy")[:, 0, :]
    # print(data.shape)
    # features = gen_time_domain_features(data)
    # print(len(features))
    # print(features)
