import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from itertools import cycle, islice
import matplotlib.colors as mcolors

plt.rcParams["figure.figsize"] = (12,9)
plt.rcParams.update({'font.size': 35})
plt.rcParams['axes.linewidth'] = 5

#my_colors = [tuple(ti/255 for ti in (122,202,199)), tuple(ti/255 for ti in (43,178,202)), tuple(ti/255 for ti in (10,143,184)), tuple(ti/255 for ti in (13,105,158)), tuple(ti/255 for ti in (10,70,133))]*5 #['g', 'b', 'r', 'c','y']
#my_colors = [tuple(ti/255 for ti in (158,170,251)), tuple(ti/255 for ti in (181, 159, 232)), tuple(ti/255 for ti in (122,220,197)), tuple(ti/255 for ti in (109,167,209)), tuple(ti/255 for ti in (191,135,238))]*5 #['g', 'b', 'r', 'c','y']
#my_colors = [tuple(ti/255 for ti in (141,180,247)), tuple(ti/255 for ti in (181, 159, 232)), tuple(ti/255 for ti in (122,220,197)), tuple(ti/255 for ti in (137,142,147)), tuple(ti/255 for ti in (191,135,238))]*5 #['g', 'b', 'r', 'c','y']
#my_colors = [tuple(ti/255 for ti in (218,79,79)), tuple(ti/255 for ti in (235, 103, 89)), tuple(ti/255 for ti in (241,151,105)), tuple(ti/255 for ti in (242,166,109)), tuple(ti/255 for ti in (247,215,143))]*5 #['g', 'b', 'r', 'c','y']
#my_colors = [tuple(ti/255 for ti in (247,218,123)), tuple(ti/255 for ti in (131, 205, 186)), tuple(ti/255 for ti in (240,141,78)), tuple(ti/255 for ti in (64,145,190)), tuple(ti/255 for ti in (221,38,57))]*5 #['g', 'b', 'r', 'c','y']
#my_colors = [tuple(ti/255 for ti in (158,170,250)), tuple(ti/255 for ti in (131,205,186)), tuple(ti/255 for ti in (194,224,200)), tuple(ti/255 for ti in (237,155,190)), tuple(ti/255 for ti in (191,135,238))]*5 #['g', 'b', 'r', 'c','y']
#my_colors = [tuple(ti/255 for ti in (189,219,236)), tuple(ti/255 for ti in (142,189,219)), tuple(ti/255 for ti in (91,160,204)), tuple(ti/255 for ti in (49,128,181)), tuple(ti/255 for ti in (36,88,138))]*5 #['g', 'b', 'r', 'c','y']
#my_colors = [tuple(ti/255 for ti in (194,224,200)), tuple(ti/255 for ti in (141,197,151)), tuple(ti/255 for ti in (91,174,106)), tuple(ti/255 for ti in (53,161,73)), tuple(ti/255 for ti in (35,123,45))]*5 #['g', 'b', 'r', 'c','y']

'''
my_colors = [tuple(ti/255 for ti in (181,125,238)),
             tuple(ti/255 for ti in (168,212,225)),
             tuple(ti/255 for ti in (229,245,224)),
             tuple(ti/255 for ti in (211,155,255)),
             tuple(ti/255 for ti in (117,194,214))] #['g', 'b', 'r', 'c','y']
'''


lowLst = [2,8,14,21,33,38,44]
highLst = [7+1,13+1,20+1,32+1,37+1,43+1,46+1]
botLst = [0.0,0.0,0.0,0.0,0.0,0.0,0.0]
topLst = [102,102,102,102,102,102,102]
capLst = [5,5,5,5,5,5,5]
xTickLst = [['16','12','10','08','06','04'],['16','12','10','08','06','04'],['01','02','03','04','05','10','15'],['0.5','0.1','0.2','0.3','0.4','0.5','1.0','1.5','2.0','2.5','3.0','5.0'],['±03','±05','±10','±15','±20'],['20','25','30','35','40','45','50'],['3','4','5']]
xTickOffLst = [2.7,2.7,2.8,2.9,2.9,2.6,2.2]
rotationLst = [0,0,0,0,0,0,0]
xLabelLst = ['Weight Resolution (bits)','I/O Resolution (bits)','Weight Error (%)','Stuck On/Off (%)','Conductance Range (%)','Source Resistance (Ohms)','Line Resistance (Ohms)']
ignoreLst = [2,3,4,7,8,10]
titleLst = ['Effect of Weight Resolution','Effect of I/O Resolution','Effect of Weight Error','Effect of Stuck On/Off','Effect of Conductance Range','Effect of Source Resistance','Effect of Line Resistance']
dataset = ['CHBMITPatient01','CHBMITPatient02','CHBMITPatient03','CHBMITPatient05','CHBMITPatient08']
#dataset = ['SWEC_ETHZPatient01','SWEC_ETHZPatient02','SWEC_ETHZPatient03','SWEC_ETHZPatient05','SWEC_ETHZPatient06'] #,'CHBMITPatient01','CHBMITPatient02','CHBMITPatient03','CHBMITPatient05','CHBMITPatient08']
#dataset = ['Bonn']
width = 0.15

for i in range(len(lowLst)):
    offset = 0
    plt.figure(figsize=(12, 10))
    for j in range(len(dataset)):
        dataArr = []
        meanDict = {}
        stdDict = {}

        data = pd.read_excel('SimulationSummary.xlsx',dataset[j])
        data = pd.DataFrame(data)

        for seed in range(5,9+1):
            if i == 3: #For removing some stuckon/off
                indices = [z for z in range(highLst[i]-lowLst[i]) if z not in ignoreLst]
                dataArr.append([data['AC(' + str(seed) + ')'][lowLst[i]:highLst[i]].tolist()[z] for z in indices])
            else:
                indices = range(highLst[i]-lowLst[i])
                dataArr.append(data['AC(' + str(seed) + ')'][lowLst[i]:highLst[i]].tolist())

        dataArr = np.array(dataArr)
        meanArr = (np.mean(dataArr, axis=0)*100).tolist()
        stdArr = (np.std(dataArr, axis=0)*100).tolist()

        #Make sure error bar does not get above 100%
        tempArr = []
        for l in range(len(meanArr)):
            if 100-meanArr[l] < stdArr[l]:
                tempArr.append(100-meanArr[l])
            else:
                tempArr.append(stdArr[l])
        stdArr = [stdArr,tempArr]

        plt.bar(np.arange(len(list(meanArr)))+offset,
                meanArr,
                width,
                label=dataset[j],
                edgecolor="black",
                linewidth=2,
                color=my_colors[j],
                yerr=stdArr,
                error_kw=dict(lw=2.5, capsize=capLst[i], capthick=1.5),
                zorder=1,                )
        # plt.gca().errorbar(np.arange(len(list(meanArr)))+offset,
        #                    meanArr,
        #                    yerr=stdArr,
        #                    uplims=[100,100,100,100,100,100])
        offset += width
    plt.ylim((botLst[i],topLst[i]))
    plt.title(titleLst[i], y=1.02,fontsize=50)
    plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')
    plt.ylabel("Accuracy (%)",fontsize=45)
    plt.xticks(np.arange(len(list(meanArr)))+xTickOffLst[i]*width, [xTickLst[i][z] for z in indices], color='black', rotation=rotationLst[i],fontsize='35', horizontalalignment='right')
    plt.xlabel(xLabelLst[i],fontsize=45)
    plt.gca().set_axisbelow(True)
    plt.tight_layout()
    plt.savefig(str(i)+'.pdf')
    plt.show()


# weightResDict = []
# for seed in range(5,9+1):
#     weightResDict.append(data['AC('+str(seed)+')'][2:7+1].tolist())
#     #weightResDict["Seed%s" %seed] = data['AC('+str(seed)+')'][2:7+1].tolist()
#
# inoutResDict = {}
# for seed in range(5,9+1):
#     inoutResDict["Seed%s" %seed] = data['AC('+str(seed)+')'][8:13+1].tolist()
#
# weightErrDict = {}
# for seed in range(5,9+1):
#     weightErrDict["Seed%s" %seed] = data['AC('+str(seed)+')'][14:20+1].tolist()
#
# stuckDict = {}
# for seed in range(5,9+1):
#     stuckDict["Seed%s" %seed] = data['AC('+str(seed)+')'][21:32+1].tolist()
#
# minmaxdict = {}
# for seed in range(5,9+1):
#     minmaxdict["Seed%s" %seed] = data['AC('+str(seed)+')'][33:37+1].tolist()
#
# rsourcedict = {}
# for seed in range(5,9+1):
#     rsourcedict["Seed%s" %seed] = data['AC('+str(seed)+')'][38:43+1].tolist()
#
# rlinedict = {}
# for seed in range(5,9+1):
#     rlinedict["Seed%s" %seed] = data['AC('+str(seed)+')'][44:46+1].tolist()
#
# weightResDict = np.array(weightResDict)
# print(np.mean(weightResDict,axis=0))
# print(np.std(weightResDict,axis=0))
#
# meanDict = {}
# stdDict = {}
# meanDict['SWEC_ETHZPatient05']=np.mean(weightResDict,axis=0).tolist()
# stdDict['SWEC_ETHZPatient05']=np.std(weightResDict,axis=0).tolist()
# print(meanDict,stdDict)
#
#
# plotdata = pd.DataFrame(weightErrDict, index=data['Weight Error'][14:20+1])
# plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# plt.grid(True,zorder=0,linewidth=3)
# plt.suptitle("Effect of Weight Error", fontsize=45, y=0.97)
# plt.xlabel("Weight Error (%)", fontsize=35)
# plt.ylabel("Accuracy (%)", fontsize=35)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
#
#
# plotdata = pd.DataFrame(weightResDict, index=data['Weight Res'][2:7+1])
# plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# plt.grid(True,zorder=0,linewidth=3)
# plt.title("Effect of Weight Resolution",fontsize=45, y=1.03)
# plt.xlabel("Weight Resolution (bits)", fontsize=32)
# plt.ylabel("Accuracy (%)", fontsize=32)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
#
#
# plotdata = pd.DataFrame(inoutResDict, index=data['inputres'][8:13+1])
# plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# plt.grid(True,zorder=0,linewidth=3)
# plt.title("Effect of I/O Resolution",fontsize=45, y=1.03)
# plt.xlabel("I/O Resolution (bits)", fontsize=32)
# plt.ylabel("Accuracy (%)", fontsize=32)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
#
#
# # plotdata = pd.DataFrame(stuckDict, index=data['Stuck On/Off'][21:32+1]*100)
# # plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# # plt.grid(True,zorder=0,linewidth=3)
# # plt.title("Effect of Stuck On/Off",fontsize=45, y=1.03)
# # plt.xlabel("Stuck On/Off (%)", fontsize=32)
# # plt.ylabel("Accuracy (%)", fontsize=32)
# # plt.ylim((0.45,1))
# # plt.xticks(rotation=0)
# # plt.show()
# plotdata = pd.DataFrame(stuckDict, index=data['Stuck On/Off'][21:32+1]*100)
# plotdata.plot(kind="bar",color=my_colors,zorder=2,width=0.75,edgecolor = "black",linewidth=3)
# plt.title("Effect of Stuck On/Off",fontsize=45, y=1.03)
# plt.xlabel("Stuck On/Off (%)", fontsize=32)
# plt.ylabel("Accuracy (%)", fontsize=32)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
#
#
# plotdata = pd.DataFrame(minmaxdict, index=data['Rmaxrange'][33:37+1])
# plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# plt.grid(True,zorder=0,linewidth=3)
# plt.title("Effect of Conductance Range",fontsize=45, y=1.03)
# plt.xlabel("Conductance Range (%)", fontsize=32)
# plt.ylabel("Accuracy (%)", fontsize=32)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
#
#
# plotdata = pd.DataFrame(rsourcedict, index=data['R_source'][38:43+1])
# plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# plt.grid(True,zorder=0,linewidth=3)
# plt.title("Effect of Source Resistance",fontsize=45, y=1.03)
# plt.xlabel("Source Resistance (Ohms)", fontsize=32)
# plt.ylabel("Accuracy (%)", fontsize=32)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
#
#
# plotdata = pd.DataFrame(rlinedict, index=data['R_line'][44:46+1])
# plotdata.plot(kind="bar",color=my_colors,zorder=2,legend=None,width=0.75,edgecolor = "black",linewidth=3)
# plt.grid(True,zorder=0,linewidth=3)
# plt.title("Effect of Line Resistance",fontsize=45, y=1.03)
# plt.xlabel("Line Resistance (Ohms)", fontsize=32)
# plt.ylabel("Accuracy (%)", fontsize=32)
# plt.ylim((0.45,1))
# plt.xticks(rotation=0)
# plt.show()
