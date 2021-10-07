import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from itertools import cycle, groupby, islice
import matplotlib.colors as mcolors

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
plotdata.plot(kind="line", yerr='std', color=my_colors[0], zorder=2, legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
plt.grid(axis='both')
plt.title("Effect of Weight Resolution",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Weight Resolution (bits)", fontsize=labelSize,
           fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.ylim((94, 100))
plt.xticks([4, 6, 8, 10, 12, 16])
plt.xticks(rotation=0)

plt.subplot(2, 4, 2)
plotdata = pd.DataFrame(
    weightErrDict, index=data['Weight Error'][14:20 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[1], zorder=2, legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
plt.grid(axis='both')
plt.title("Effect of Weight Write Error",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Weight Error (%)", fontsize=labelSize,
           fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylim((55, 100))
plt.xticks([0.01, 0.02, 0.03, 0.04, 0.05, 0.1, 0.15])
plt.xticks(rotation=90)


plt.subplot(2, 4, 3)
plotdata = pd.DataFrame(inoutResDict, index=data['inputres'][8:13 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[2], zorder=2, legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
plt.grid(axis='both')
plt.title("Effect of ADC and DAC Resolution",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("ACD and DAC Resolution (bits)", fontsize=labelSize,
           fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.ylim((60, 100))
plt.xticks([4, 6, 8, 10, 12, 16])
plt.xticks(rotation=0)

ax = plt.subplot(2, 4, 4)
plotdata = pd.DataFrame(stuckDict, index=[
                        data['Stuck On/Off'][21:32 + 1].tolist()[z] * 100 for z in indices]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[3], zorder=2, legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
plt.grid(axis='both')
plt.title(
    "Effect of Stuck $R_{ON}$ and $R_{OFF}$ Devices", fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Stuck $R_{ON}$ and $R_{OFF}$ Devices (%)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.ylim((40, 100))
plt.xscale('log')
plt.xticks(rotation=0)

plt.subplot(2, 4, 5)
plotdata = pd.DataFrame(minmaxdict, index=data['Rmaxrange'][33:37 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[4], zorder=2, legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
plt.grid(axis='both')
plt.title("Effect of Device Conductance Range",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Device Conductance Range (%)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.ylim((99.1, 99.4))
plt.xticks([1.03, 1.05, 1.1, 1.15, 1.2])
plt.xticks(rotation=90)

plt.subplot(2, 4, 6)
plotdata = pd.DataFrame(rsourcedict, index=data['R_source'][38:43 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[5], zorder=2, legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
plt.grid(axis='both')
plt.title("Effect of Source Resistance",
          fontsize=titleSize, fontdict=dict(weight='bold'))
plt.xlabel("Source Resistance ($\Omega$)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=6)
plt.ylim((98.4, 99.2))
plt.xticks([25, 30, 45, 40, 45, 50])
plt.xticks(rotation=0)

plt.subplot(2, 4, 7)
plotdata = pd.DataFrame(rlinedict, index=data['R_line'][44:46 + 1]) * 100
plotdata = plotdata.transpose().agg([np.mean, np.std]).transpose()
plotdata.plot(kind="line", yerr='std', color=my_colors[6], zorder=2, legend=None,
              linewidth=5, ax=plt.gca(), capsize=7.5, marker='o', markersize=7.5, markeredgewidth=5)
plt.grid(axis='both')
plt.title("Effect of Line Resistance", fontsize=titleSize,
          fontdict=dict(weight='bold'))
plt.xlabel("Line Resistance ($\Omega$)",
           fontsize=labelSize, fontdict=dict(weight='bold'))
plt.ylabel("Accuracy (%)", fontsize=labelSize, fontdict=dict(weight='bold'))
plt.locator_params(axis='y', nbins=4)
plt.ylim((97, 98.8))
plt.xticks([3, 4, 5])
plt.xticks(rotation=0)
plt.yticks([97.0, 97.5, 98.0, 98.5, 99.0])


plt.tight_layout()
plt.savefig('Bonn.pdf')
plt.savefig('Bonn.svg')
plt.show()
