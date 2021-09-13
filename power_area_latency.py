from voltage_deg_model_sparse_conductance import voltage_deg_model_sparse_conductance
import numpy as np
import pandas as pd
import torch
import copy
from voltage_deg_model_sparse_conductance import voltage_deg_model_sparse_conductance

# A 31-μW, 148-fs Step, 9-bit Capacitor-DAC-Based Constant-Slope Digital-to-Time Converter in 28-nm CMOS

RRAM_cell_area = 1e-14
RRAM_cell_read_voltage = 0.3
RRAM_cell_read_latency = 6e-9
DAC_area = 0.05e-6
DAC_power = 2e-4
DAC_frequency = 100e6
ADC_area = (1.1e-3) * (0.6e-3)
ADC_power = 10e-3
ADC_frequency = 10e6
DAC_ADC_bit_resolution = 6
R_source = 20
R_line = 2
RRAM_R_ON = 10e3
RRAM_R_OFF = 100e3
tiles = np.zeros((7, 64, 64))
tiles[0, 0, :] = 1  # First convolutional layer biases
tiles[0, 1:32, :] = 1  # First convolutional layer weights
tiles[0, 33:40, 0:3] = 1  # Second fully connected layer weights
tiles[1, 0, :] = 1  # Second convolutional layer biases
tiles[1, 1:30, :] = 1  # Second convolutional layer weights
tiles[2:5, :, :] = 1  # First fully connected layer weights
tiles[6, :, 0:15] = 1  # First fully connected layer weights

df = pd.DataFrame(columns=['Implementation', 'Scenario', 'Power (W)',
                  'Area (mm2)', 'Latency (us)', 'Energy (uJ)', 'EDP (uJ * s)'])

# TDM R_ON
tiles_ = copy.deepcopy(tiles)
tiles_[tiles_ == 0] = RRAM_R_OFF
tiles_[tiles_ == 1] = RRAM_R_ON
V_applied = np.zeros_like(tiles_)
for tile_idx, tile_ in enumerate(tiles_):
    V_applied[tile_idx] = voltage_deg_model_sparse_conductance(1 / torch.tensor(
        tile_), torch.ones((tiles.shape[1])) * RRAM_cell_read_voltage, torch.zeros(tiles.shape[2]), R_source, R_line)

crossbar_power = np.sum(
    np.divide(np.power(V_applied, 2), tiles_)) / tiles.shape[0]
peripheral_power = ADC_power * tiles.shape[0]
total_power = crossbar_power + peripheral_power
crossbar_area = tiles.size * RRAM_cell_area
peripheral_area = tiles.shape[0] * ADC_area
total_area = crossbar_area + peripheral_area
crossbar_latency = RRAM_cell_read_latency * \
    tiles.shape[0] * tiles.shape[1] * tiles.shape[2]
peripheral_latency = (1 / ADC_frequency) * DAC_ADC_bit_resolution * \
    tiles.shape[0] * tiles.shape[2]
total_latency = crossbar_latency + peripheral_latency
total_energy = total_power * total_latency
total_energy_delay_product = total_energy * total_latency
df = df.append({'Implementation': 'TDM', 'Scenario': 'R_ON', 'Power (W)': total_power, 'Area (mm2)': total_area * 1e6,
               'Latency (us)': total_latency * 1e6, 'Energy (uJ)': total_energy * 1e6, 'EDP (uJ * s)': total_energy_delay_product * 1e6}, ignore_index=True)

# TDM (R_ON + R_OFF) / 2
tiles_ = copy.deepcopy(tiles)
tiles_[tiles_ == 0] = RRAM_R_OFF
tiles_[tiles_ == 1] = (RRAM_R_ON + RRAM_R_OFF) / 2
V_applied = np.zeros_like(tiles_)
for tile_idx, tile_ in enumerate(tiles_):
    V_applied[tile_idx] = voltage_deg_model_sparse_conductance(1 / torch.tensor(
        tile_), torch.ones((tiles.shape[1])) * RRAM_cell_read_voltage, torch.zeros(tiles.shape[2]), R_source, R_line)

crossbar_power = np.sum(
    np.divide(np.power(V_applied, 2), tiles_)) / tiles.shape[0]
peripheral_power = ADC_power * tiles.shape[0]
total_power = crossbar_power + peripheral_power
crossbar_area = tiles.size * RRAM_cell_area
peripheral_area = tiles.shape[0] * ADC_area
total_area = crossbar_area + peripheral_area
crossbar_latency = RRAM_cell_read_latency * \
    tiles.shape[0] * tiles.shape[1] * tiles.shape[2]
peripheral_latency = (1 / ADC_frequency) * \
    DAC_ADC_bit_resolution * tiles.shape[0] * tiles.shape[2]
total_latency = crossbar_latency + peripheral_latency
total_energy = total_power * total_latency
total_energy_delay_product = total_energy * total_latency
df = df.append({'Implementation': 'TDM', 'Scenario': '(R_ON + R_OFF) / 2', 'Power (W)': total_power, 'Area (mm2)': total_area * 1e6,
               'Latency (us)': total_latency * 1e6, 'Energy (uJ)': total_energy * 1e6, 'EDP (uJ * s)': total_energy_delay_product * 1e6}, ignore_index=True)

# Parallelized R_ON
tiles_ = copy.deepcopy(tiles)
tiles_[tiles_ == 0] = RRAM_R_OFF
tiles_[tiles_ == 1] = RRAM_R_ON
V_applied = np.zeros_like(tiles_)
for tile_idx, tile_ in enumerate(tiles_):
    V_applied[tile_idx] = voltage_deg_model_sparse_conductance(1 / torch.tensor(
        tile_), torch.ones((tiles.shape[1])) * RRAM_cell_read_voltage, torch.zeros(tiles.shape[2]), R_source, R_line)

crossbar_power = np.sum(
    np.divide(np.power(V_applied, 2), tiles_)) / tiles.shape[0]
peripheral_power = ADC_power * tiles.shape[0] * tiles.shape[2]
total_power = crossbar_power + peripheral_power
crossbar_area = tiles.size * RRAM_cell_area
peripheral_area = tiles.shape[0] * ADC_area * tiles.shape[2]
total_area = crossbar_area + peripheral_area
crossbar_latency = RRAM_cell_read_latency * tiles.shape[1]
peripheral_latency = (1 / ADC_frequency) * DAC_ADC_bit_resolution
total_latency = crossbar_latency + peripheral_latency
total_energy = total_power * total_latency
total_energy_delay_product = total_energy * total_latency
df = df.append({'Implementation': 'Parallelized', 'Scenario': 'R_ON', 'Power (W)': total_power, 'Area (mm2)': total_area * 1e6,
               'Latency (us)': total_latency * 1e6, 'Energy (uJ)': total_energy * 1e6, 'EDP (uJ * s)': total_energy_delay_product * 1e6}, ignore_index=True)

# Parallelized (R_ON + R_OFF) / 2
tiles_ = copy.deepcopy(tiles)
tiles_[tiles_ == 0] = RRAM_R_OFF
tiles_[tiles_ == 1] = (RRAM_R_ON + RRAM_R_OFF) / 2
V_applied = np.zeros_like(tiles_)
for tile_idx, tile_ in enumerate(tiles_):
    V_applied[tile_idx] = voltage_deg_model_sparse_conductance(1 / torch.tensor(
        tile_), torch.ones((tiles.shape[1])) * RRAM_cell_read_voltage, torch.zeros(tiles.shape[2]), R_source, R_line)

crossbar_power = np.sum(
    np.divide(np.power(V_applied, 2), tiles_)) / tiles.shape[0]
peripheral_power = ADC_power * tiles.shape[0] * tiles.shape[2]
total_power = crossbar_power + peripheral_power
crossbar_area = tiles.size * RRAM_cell_area
peripheral_area = tiles.shape[0] * ADC_area * tiles.shape[2]
total_area = crossbar_area + peripheral_area
crossbar_latency = RRAM_cell_read_latency * tiles.shape[1]
peripheral_latency = (1 / ADC_frequency) * DAC_ADC_bit_resolution
total_latency = crossbar_latency + peripheral_latency
total_energy = total_power * total_latency
total_energy_delay_product = total_energy * total_latency
df = df.append({'Implementation': 'Parallelized', 'Scenario': '(R_ON + R_OFF) / 2', 'Power (W)': total_power, 'Area (mm2)': total_area * 1e6,
               'Latency (us)': total_latency * 1e6, 'Energy (uJ)': total_energy * 1e6, 'EDP (uJ * s)': total_energy_delay_product * 1e6}, ignore_index=True)

print(df)
