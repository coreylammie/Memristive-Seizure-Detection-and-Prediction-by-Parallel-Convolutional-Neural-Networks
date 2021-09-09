import pandas as pd
import matplotlib.pyplot as plt
from itertools import cycle, islice
import matplotlib.colors as mcolors

plt.rcParams["figure.figsize"] = (12,9)
plt.rcParams.update({'font.size': 35})
plt.rcParams['axes.linewidth'] = 5

my_colors = [tuple(ti/255 for ti in (122,202,199)), tuple(ti/255 for ti in (43,178,202)), tuple(ti/255 for ti in (10,143,184)), tuple(ti/255 for ti in (13,105,158)), tuple(ti/255 for ti in (10,70,133))]*5 #['g', 'b', 'r', 'c','y']
my_colors = [tuple(ti/255 for ti in (148,160,241)), tuple(ti/255 for ti in (181, 159, 232)), tuple(ti/255 for ti in (122,220,197)), tuple(ti/255 for ti in (109,167,209)), tuple(ti/255 for ti in (191,135,238))]*5 #['g', 'b', 'r', 'c','y']
my_colors = [tuple(ti/255 for ti in (122,202,199)), tuple(ti/255 for ti in (43,178,202)), tuple(ti/255 for ti in (10,143,184)), tuple(ti/255 for ti in (13,105,158)), tuple(ti/255 for ti in (10,70,133))]*5 #['g', 'b', 'r', 'c','y']




data = pd.read_excel('SimulationSummary.xlsx','Bonn')
data = pd.DataFrame(data)


weightResDict = {}
for seed in range(5,9+1):
    weightResDict["Seed%s" %seed] = data['AC('+str(seed)+')'][2:7+1].tolist()

inoutResDict = {}
for seed in range(5,9+1):
    inoutResDict["Seed%s" %seed] = data['AC('+str(seed)+')'][8:13+1].tolist()

weightErrDict = {}
for seed in range(5,9+1):
    weightErrDict["Seed%s" %seed] = data['AC('+str(seed)+')'][14:20+1].tolist()

stuckDict = {}
ignoreLst = [2,3,4,7,8,10]
for seed in range(5,9+1):
    indices = [z for z in range(32+1 - 21) if z not in ignoreLst]
    print(indices)
    print(data['AC(' + str(seed) + ')'][21:32+1].tolist())
    stuckDict["Seed%s" %seed] = [data['AC(' + str(seed) + ')'][21:32+1].tolist()[z] for z in indices]

minmaxdict = {}
for seed in range(5,9+1):
    minmaxdict["Seed%s" %seed] = data['AC('+str(seed)+')'][33:37+1].tolist()

rsourcedict = {}
for seed in range(5,9+1):
    rsourcedict["Seed%s" %seed] = data['AC('+str(seed)+')'][38:43+1].tolist()

rlinedict = {}
for seed in range(5,9+1):
    rlinedict["Seed%s" %seed] = data['AC('+str(seed)+')'][44:46+1].tolist()


titleSize = 50
labelSize = 45
figureSize = (12,10)

plotdata = pd.DataFrame(weightErrDict, index=data['Weight Error'][14:20+1])
plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3,figsize=figureSize)
plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
plt.title("Effect of Weight Error", fontsize=titleSize, y=1.03)
plt.xlabel("Weight Error (%)", fontsize=labelSize)
plt.ylabel("Accuracy (%)", fontsize=labelSize)
plt.ylim((0,1.02))
plt.xticks(rotation=0)
plt.tight_layout()
plt.savefig('0.pdf')
plt.show()


plotdata = pd.DataFrame(weightResDict, index=data['Weight Res'][2:7+1])
plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3,figsize=figureSize)
plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
plt.title("Effect of Weight Resolution",fontsize=titleSize, y=1.03)
plt.xlabel("Weight Resolution (bits)", fontsize=labelSize)
plt.ylabel("Accuracy (%)", fontsize=labelSize)
plt.ylim((0,1.02))
plt.xticks(rotation=0)
plt.tight_layout()
plt.savefig('1.pdf')
plt.show()


plotdata = pd.DataFrame(inoutResDict, index=data['inputres'][8:13+1])
plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3,figsize=figureSize)
plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
plt.title("Effect of I/O Resolution",fontsize=titleSize, y=1.03)
plt.xlabel("I/O Resolution (bits)", fontsize=labelSize)
plt.ylabel("Accuracy (%)", fontsize=labelSize)
plt.ylim((0,1.02))
plt.xticks(rotation=0)
plt.tight_layout()
plt.savefig('2.pdf')
plt.show()


# plotdata = pd.DataFrame(stuckDict, index=data['Stuck On/Off'][21:32+1]*100)
# plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# plt.grid(True,zorder=0,linewidth=3)
# plt.title("Effect of Stuck On/Off",fontsize=titleSize, y=1.03)
# plt.xlabel("Stuck On/Off (%)", fontsize=32)
# plt.ylabel("Accuracy (%)", fontsize=32)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
plotdata = pd.DataFrame(stuckDict, index=[data['Stuck On/Off'][21:32+1].tolist()[z]*100 for z in indices])
plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3,figsize=figureSize)
plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
plt.title("Effect of Stuck On/Off",fontsize=titleSize, y=1.03)
plt.xlabel("Stuck On/Off (%)", fontsize=labelSize)
plt.ylabel("Accuracy (%)", fontsize=labelSize)
plt.ylim((0,1.02))
plt.xticks(rotation=0)
plt.tight_layout()
plt.savefig('3.pdf')
plt.show()


plotdata = pd.DataFrame(minmaxdict, index=data['Rmaxrange'][33:37+1])
plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3,figsize=figureSize)
plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
plt.title("Effect of Conductance Range",fontsize=titleSize, y=1.03)
plt.xlabel("Conductance Range (%)", fontsize=labelSize)
plt.ylabel("Accuracy (%)", fontsize=labelSize)
plt.ylim((0,1.02))
plt.xticks(rotation=0)
plt.tight_layout()
plt.savefig('4.pdf')
plt.show()


plotdata = pd.DataFrame(rsourcedict, index=data['R_source'][38:43+1])
plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3,figsize=figureSize)
plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
plt.title("Effect of Source Resistance",fontsize=titleSize, y=1.03)
plt.xlabel("Source Resistance (Ohms)", fontsize=labelSize)
plt.ylabel("Accuracy (%)", fontsize=labelSize)
plt.ylim((0,1.02))
plt.xticks(rotation=0)
plt.tight_layout()
plt.savefig('5.pdf')
plt.show()


plotdata = pd.DataFrame(rlinedict, index=data['R_line'][44:46+1])
plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3,figsize=figureSize)
plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
plt.title("Effect of Line Resistance",fontsize=titleSize, y=1.03)
plt.xlabel("Line Resistance (Ohms)", fontsize=labelSize)
plt.ylabel("Accuracy (%)", fontsize=labelSize)
plt.ylim((0,1.02))
plt.xticks(rotation=0)
plt.tight_layout()
plt.savefig('6.pdf')
plt.show()
