import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from itertools import cycle, groupby, islice
import matplotlib.colors as mcolors
import seaborn as sns

plt.rcParams['font.family'] = 'sans-serif'
plt.rcParams['font.sans-serif'] = ['Arial']
plt.rcParams["figure.figsize"] = (20, 10)
plt.rcParams.update({'font.size': 16})
plt.rcParams['axes.linewidth'] = 2

my_colors = ["#ef127b", "#e87ab3", "#0d9cd0",
             "#d6711f", "#1dc470", "#1C7874", "#050A30"]


data = pd.read_excel('SimulationSummary.xlsx', 'Bonn')
data = pd.DataFrame(data)


weightResDict = {}
for seed in range(5, 9 + 1):
    weightResDict["Seed%s" %
                  seed] = data['AC(' + str(seed) + ')'][2:7 + 1].tolist()

inoutResDict = {}
for seed in range(5, 9 + 1):
    inoutResDict["Seed%s" %
                 seed] = data['AC(' + str(seed) + ')'][8:13 + 1].tolist()

weightErrDict = {}
for seed in range(5, 9 + 1):
    weightErrDict["Seed%s" %
                  seed] = data['AC(' + str(seed) + ')'][14:20 + 1].tolist()

stuckDict = {}
ignoreLst = [2, 3, 4, 7, 8, 10]
for seed in range(5, 9 + 1):
    indices = [z for z in range(32 + 1 - 21) if z not in ignoreLst]
    print(indices)
    print(data['AC(' + str(seed) + ')'][21:32 + 1].tolist())
    stuckDict["Seed%s" % seed] = [
        data['AC(' + str(seed) + ')'][21:32 + 1].tolist()[z] for z in indices]

minmaxdict = {}
for seed in range(5, 9 + 1):
    minmaxdict["Seed%s" %
               seed] = data['AC(' + str(seed) + ')'][33:37 + 1].tolist()

rsourcedict = {}
for seed in range(5, 9 + 1):
    rsourcedict["Seed%s" %
                seed] = data['AC(' + str(seed) + ')'][38:43 + 1].tolist()

rlinedict = {}
for seed in range(5, 9 + 1):
    rlinedict["Seed%s" %
              seed] = data['AC(' + str(seed) + ')'][44:46 + 1].tolist()

titleSize = 18
labelSize = 18
figureSize = (12, 10)

plt.figure(1)
plt.subplot(2, 4, 1)
plotdata = pd.DataFrame(weightResDict, index=data['Weight Res'][2:7 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[0], legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5, zorder=1, alpha=0.9)
plt.grid(axis='both')
plt.title("Effect of Weight Resolution",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Weight Resolution (bits)", fontsize=labelSize,
           fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.xticks([4, 6, 8, 10, 12, 16])
plt.xticks(rotation=0)

plt.subplot(2, 4, 2)
plotdata = pd.DataFrame(
    weightErrDict, index=data['Weight Error'][14:20 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
print(plotdata)
plt.errorbar(plotdata.index * 100,
             plotdata['mean'].values, yerr=plotdata['std'].values, color=my_colors[0], legend=None,
             linewidth=5, capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5, zorder=1, alpha=0.9
             )
plt.grid(axis='both')
plt.title("Effect of Weight Write Error",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Weight Error (%)", fontsize=labelSize,
           fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.xticks([1, 2, 3, 4, 5, 10, 15])
plt.xticks(rotation=90)


plt.subplot(2, 4, 3)
plotdata = pd.DataFrame(inoutResDict, index=data['inputres'][8:13 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[0], legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5, zorder=1, alpha=0.9)
plt.grid(axis='both')
plt.title("Effect of ADC and DAC Resolution",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("ADC and DAC Resolution (bits)", fontsize=labelSize,
           fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.xticks([4, 6, 8, 10, 12, 16])
plt.xticks(rotation=0)

ax = plt.subplot(2, 4, 4)
plotdata = pd.DataFrame(stuckDict, index=[
                        data['Stuck On/Off'][21:32 + 1].tolist()[z] * 100 for z in indices]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[0], legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5, zorder=1, alpha=0.9)
plt.grid(axis='both')
plt.title(
    "Effect of Stuck $R_{ON}$ and $R_{OFF}$ Devices", fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Stuck $R_{ON}$ and $R_{OFF}$ Devices (%)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.xscale('log')
plt.xticks(rotation=0)

plt.subplot(2, 4, 5)
plotdata = pd.DataFrame(minmaxdict, index=data['Rmaxrange'][33:37 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plt.errorbar([3, 5, 10, 15, 20],
             plotdata['mean'].values, yerr=plotdata['std'].values, color=my_colors[0], legend=None,
             linewidth=5, capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5, zorder=1, alpha=0.9
             )
plt.grid(axis='both')
plt.title("Effect of Device Conductance Range",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Device Conductance Range ($\pm$%)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.xticks([3, 5, 10, 15, 20])
plt.xticks(rotation=90)

plt.subplot(2, 4, 6)
plotdata = pd.DataFrame(rsourcedict, index=data['R_source'][38:43 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plt.errorbar([20, 25, 30, 35, 40, 45],
             plotdata['mean'].values, yerr=plotdata['std'].values, color=my_colors[0], legend=None,
             linewidth=5, capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5, zorder=1, alpha=0.9
             )
plt.grid(axis='both')
plt.title("Effect of Source Resistance",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Source Resistance ($\Omega$)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.xticks([20, 25, 30, 35, 40, 45])
plt.xticks(rotation=0)

plt.subplot(2, 4, 7)
plotdata = pd.DataFrame(rlinedict, index=data['R_line'][44:46 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[0], legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5, alpha=0.9)
plt.grid(axis='both')
plt.title("Effect of Line Resistance", fontsize=titleSize,
          fontdict=dict(weight='bold'))
plt.xlabel("Line Resistance ($\Omega$)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=4)
plt.xticks([3, 4, 5])
plt.xticks(rotation=0)

lowLst = [2, 8, 14, 21, 33, 38, 44]
highLst = [7 + 1, 13 + 1, 20 + 1, 32 + 1, 37 + 1, 43 + 1, 46 + 1]
botLst = [10, 60, 50, 20, 80, 80, 80]
capLst = [5, 5, 5, 5, 5, 5, 5]
xTickLst = [['16', '12', '10', '8', '6', '4'], ['16', '12', '10', '8', '6', '4'], ['1', '2', '3', '4', '5', '10', '15'], ['0.5', '0.1', '0.2', '0.3',
                                                                                                                          '0.4', '0.5', '1.0', '1.5', '2.0', '2.5', '3.0', '5.0'], ['3', '5', '10', '15', '20'], ['20', '25', '30', '35', '40', '45', '50'], ['3', '4', '5']]
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
    if i == 3:
        print(plotdata)
        print([float(xTickLst[i][z]) for z in indices])
        x = [0.05, 0.1, 0.5, 1.0, 2.5, 5.0]
    else:
        x = [float(xTickLst[i][z]) for z in indices]

    plt.errorbar(x,
                 plotdata['mean'].values, yerr=plotdata['std'].values, color=my_colors[2], legend=None,
                 linewidth=5, capsize=7.5, marker='^', markersize=7.5, markeredgewidth=5, linestyle='--', zorder=2, alpha=0.9
                 )


lowLst = [2, 8, 14, 21, 33, 38, 44]
highLst = [7 + 1, 13 + 1, 20 + 1, 32 + 1, 37 + 1, 43 + 1, 46 + 1]
botLst = [60, 50, 60, 40, 90, 80, 80]
capLst = [5, 5, 5, 5, 5, 5, 5]
xTickLst = [['16', '12', '10', '8', '6', '4'], ['16', '12', '10', '8', '6', '4'], ['1', '2', '3', '4', '5', '10', '15'], ['0.5', '0.1', '0.2', '0.3',
                                                                                                                          '0.4', '0.5', '1.0', '1.5', '2.0', '2.5', '3.0', '5.0'], ['3', '5', '10', '15', '20'], ['20', '25', '30', '35', '40', '45', '50'], ['3', '4', '5']]
xTickOffLst = [2.7, 2.7, 2.8, 2.9, 2.9, 2.6, 2.2]
rotationLst = [0, 0, 0, 0, 0, 0, 0]
xLabelLst = ['Weight Resolution (bits)', 'ACD and DAC Resolution (bits)', 'Weight Error (%)', 'Stuck $R_{ON}$ and $R_{OFF}$ Devices (%)',
             'Device Conductance Range (%)', 'Source Resistance ($\Omega$)', 'Line Resistance ($\Omega$)']
ignoreLst = [2, 3, 4, 7, 8, 10]
titleLst = ['Effect of Weight Resolution', 'Effect of ADC and DAC Resolution', 'Effect of Weight Write Error',
            'Effect of Stuck $R_{ON}$ and $R_{OFF}$ Devices', 'Effect of Device Conductance Range', 'Effect of Source Resistance', 'Effect of Line Resistance']
dataset = ['SWEC_ETHZPatient01', 'SWEC_ETHZPatient02',
           'SWEC_ETHZPatient03', 'SWEC_ETHZPatient05', 'SWEC_ETHZPatient06']
width = 0.15


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
    if i == 3:
        print(plotdata)
        print([float(xTickLst[i][z]) for z in indices])
        x = [0.05, 0.1, 0.5, 1.0, 2.5, 5.0]
    else:
        x = [float(xTickLst[i][z]) for z in indices]

    plt.errorbar(x,
                 plotdata['mean'].values, yerr=plotdata['std'].values, color=my_colors[3], legend=None,
                 linewidth=5, capsize=7.5, marker='s', markersize=7.5, markeredgewidth=5, linestyle='-.', zorder=3, alpha=0.9
                 )


plt.tight_layout()
# plt.savefig('CHB-MIT.pdf')
# plt.savefig('CHB-MIT.svg')
plt.show()
