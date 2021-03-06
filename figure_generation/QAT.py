import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.sans-serif'] = ['Arial']
plt.rcParams["figure.figsize"] = (25, 6.5)
plt.rcParams.update({'font.size': 16})
plt.rcParams['axes.linewidth'] = 2
raw = pd.read_excel('SeizurePredictionResult.xlsx', 'Summary')
data = np.array(raw.iloc[0:10, 1:11] * 100)
data[:, 3] = data[:, 3] / 100
data[:, 8] = data[:, 8] / 100
# labels = list(raw.iloc[0:5, 0])
labels = ['CHB-MIT 1', 'CHB-MIT 5',
          'SWEC-ETHZ 3', 'SWEC-ETHZ 5', 'SWEC-ETHZ 6']
# print(labels)
step = 6
width = 0.35
yLimLowLst = [0, 0, 0, 0, 0]
yLimHighLst = [100, 100, 100, 1, 16]
titleLst = ['Accuracy (%)', 'Sensitivity (%)',
            'Specitivity (%)', 'AUROC', 'FP (/hr)']
nominal_bar_color = "#12b0e9"
nominal_edge_color = "#000000"
QAT_bar_color = "#ef127b"
QAT_egde_color = "#000000"

plt.subplot(1, 5, 1)
for i in range(5):
    nominal_patient_data = list(data[:, i])
    QAT_patient_data = list(data[:, i + 5])
    plt.subplot(1, 5, i + 1)
    plt.bar(np.arange(5), nominal_patient_data[0:5],
            width, zorder=2, label='Without QAT', color=nominal_bar_color, edgecolor=nominal_edge_color, linewidth=2)
    plt.bar(np.arange(5) + width, QAT_patient_data[0:5],
            width, zorder=2, label='With QAT', color=QAT_bar_color, edgecolor=QAT_egde_color, linewidth=2)
    plt.ylim((yLimLowLst[i], yLimHighLst[i]))
    plt.xlabel('Patient', fontdict=dict(weight='bold'), fontsize=20)
    plt.ylabel(titleLst[i], fontdict=dict(weight='bold'), fontsize=20)
    plt.xticks(np.arange(5) + 0.5 * width, labels[0:5])
    plt.xticks(rotation=45)
    plt.grid(axis='both')
    plt.locator_params(axis='y', nbins=12)

plt.tight_layout()
plt.savefig('QAT.pdf')
plt.savefig('QAT.svg')
plt.show()
