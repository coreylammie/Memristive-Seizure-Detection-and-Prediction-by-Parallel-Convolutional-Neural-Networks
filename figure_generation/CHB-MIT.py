import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from itertools import cycle, islice
import matplotlib.colors as mcolors

plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.sans-serif'] = ['Arial']
plt.rcParams["figure.figsize"] = (20, 10)
plt.rcParams.update({'font.size': 16})
plt.rcParams['axes.linewidth'] = 2

my_colors = ["#ef127b", "#0d9cd0", "#e87ab3",
             "#d6711f", "#1dc470", "#1C7874", "#050A30"]

lowLst = [2, 8, 14, 21, 33, 38, 44]
highLst = [7 + 1, 13 + 1, 20 + 1, 32 + 1, 37 + 1, 43 + 1, 46 + 1]
botLst = [10, 60, 50, 20, 80, 80, 80]
capLst = [5, 5, 5, 5, 5, 5, 5]
xTickLst = [['16', '12', '10', '8', '6', '4'], ['16', '12', '10', '8', '6', '4'], ['1', '2', '3', '4', '5', '10', '15'], ['0.5', '0.1', '0.2', '0.3',
                                                                                                                          '0.4', '0.5', '1.0', '1.5', '2.0', '2.5', '3.0', '5.0'], ['±3', '±5', '±10', '±15', '±20'], ['20', '25', '30', '35', '40', '45', '50'], ['3', '4', '5']]
xTickOffLst = [2.7, 2.7, 2.8, 2.9, 2.9, 2.6, 2.2]
rotationLst = [0, 0, 0, 0, 0, 0, 0]
xLabelLst = ['Weight Resolution (bits)', 'ACD and DAC Resolution (bits)', 'Weight Error (%)', 'Stuck $R_{ON}$ and $R_{OFF}$ Devices (%)',
             'Device Conductance Range (%)', 'Source Resistance ($\Omega$)', 'Line Resistance ($\Omega$)']
ignoreLst = [2, 3, 4, 7, 8, 10]
titleLst = ['Effect of Weight Resolution', 'Effect of ADC and DAC Resolution', 'Effect of Weight Write Error',
            'Effect of Stuck $R_{ON}$ and $R_{OFF}$ Devices', 'Effect of Device Conductance Range', 'Effect of Source Resistance', 'Effect of Line Resistance']
dataset = ['CHBMITPatient01', 'CHBMITPatient02',
           'CHBMITPatient03', 'CHBMITPatient05', 'CHBMITPatient08']
width = 0.15

plt.figure(1)
plt.subplot(2, 4, 1)
for i in range(len(lowLst)):
    offset = 0
    if i == 1 or i == 2:
        if i == 1:
            plt.subplot(2, 4, 3)
        if i == 2:
            plt.subplot(2, 4, 2)
    else:
        plt.subplot(2, 4, i + 1)

    plotdata = None
    for j in range(len(dataset)):
        dataArr = []
        meanDict = {}
        stdDict = {}
        data = pd.read_excel('SimulationSummary.xlsx', dataset[j])
        data = pd.DataFrame(data)
        for seed in range(5, 9 + 1):
            if i == 3:  # For removing some stuckon/off
                indices = [z for z in range(
                    highLst[i] - lowLst[i]) if z not in ignoreLst]
                dataArr.append([data['AC(' + str(seed) + ')']
                               [lowLst[i]:highLst[i]].tolist()[z] for z in indices])
            else:
                indices = range(highLst[i] - lowLst[i])
                dataArr.append(data['AC(' + str(seed) + ')']
                               [lowLst[i]:highLst[i]].tolist())

        dataArr = np.array(dataArr) * 100
        if j == 0:
            plotdata = dataArr
        else:
            plotdata = np.vstack((plotdata, dataArr))

    plotdata = pd.DataFrame(plotdata)
    mean = plotdata.mean()
    std = plotdata.std()
    plotdata = pd.DataFrame(columns=['mean', 'std'])
    plotdata['mean'] = mean
    plotdata['std'] = std
    # Clipping logic
    plotdata['std'][plotdata['mean'] + plotdata['std'] >
                    100] = plotdata['std'] - (plotdata['std'] + plotdata['mean'] - 100)
    plotdata.plot(kind="line", yerr='std', color=my_colors[i], zorder=2, legend=None,
                  linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
    plt.title(titleLst[i], y=1.02, fontsize=18, fontdict=dict(weight='bold'))
    plt.grid(axis='both')
    plt.ylabel("Accuracy (%)", fontsize=18, fontdict=dict(weight='bold'))
    plt.xticks(np.arange(plotdata.shape[0]), [
               xTickLst[i][z] for z in indices], color='black', rotation=rotationLst[i])
    plt.xlabel(xLabelLst[i], fontsize=18, fontdict=dict(weight='bold'))
    plt.ylim([botLst[i], 100])
    plt.gca().set_axisbelow(True)

plt.tight_layout()
plt.savefig('CHB-MIT.pdf')
plt.savefig('CHB-MIT.svg')
plt.show()
