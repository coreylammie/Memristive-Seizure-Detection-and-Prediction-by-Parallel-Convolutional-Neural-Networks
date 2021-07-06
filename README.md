# Memristive-Seizure-Detection-and-Prediction-by-Parallel-Convolutional-Neural-Networks
Code for *Memristive Seizure Detection and Prediction by Parallel Convolutional Neural Networks*.

## File Overview
1. `extract_interval_data_CHBMIT.py` is used to extract preictal, ictal, and interictal samples from the [CHB-MIT](https://physionet.org/content/chbmit/1.0.0/) dataset.
2. `extract_interval_data_SWEC_ETHZ.py` is used to extract preictal, ictal, and interictal samples from the [SWEC-ETHZ](http://ieeg-swez.ethz.ch/) dataset.
3. `gen_features.py` is used to generate time-series-based features from extracted samples to be fed into ML/DL architectures for classification.
4. `gen_spectograms.py` is used to generate spectograms from extracted samples to be fed into Machine Learning (ML)/Deep Learning (DL) architectures for classification.

`extract_interval_data_SWEC_ETHZ.py` is currently undergoing development.
