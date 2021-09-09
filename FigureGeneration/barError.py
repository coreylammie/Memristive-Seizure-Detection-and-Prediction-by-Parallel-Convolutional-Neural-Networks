import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


plt.rcParams["figure.figsize"] = (12,9)
plt.rcParams.update({'font.size': 25})
plt.rcParams['axes.linewidth'] = 5

raw = pd.read_excel('SeizurePredictionResult.xlsx','Summary')
data=raw.iloc[0:5,1:12]
labels=raw.iloc[0:5,0]
step = 6
width = 0.35
yLimLowLst = [0,0,0,0,0]
yLimHighLst = [100,100,100,1,16]
scale = [1,1,1,0,0]
titleLst = ['Accuracy (%)','Sensitivity (%)','Specitivity (%)','AUROC','FP Per Hour']
xGroup = ['CHBMIT\n01','CHBMIT\n05','SWEC\n03','SWEC\n05','SWEC\n06']

for i in range(len(labels)):
    lowres = list(data.iloc[:,i])
    qat = list(data.iloc[:,i+step])
    if scale[i]:
        lowres = [z*100 for z in lowres]
        qat = [z*100 for z in qat]
    plt.bar(np.arange(len(list(lowres))), lowres, width, zorder=2, label='Without QAT', edgecolor = "black", linewidth=3, color=(242/255,172/255,142/255)) #color=(161/255,191/255,255/255)
    plt.bar(np.arange(len(list(qat)))+width, qat, width, zorder=2, label='With QAT', edgecolor = "black", linewidth=3, color=(161/255,191/255,255/255)) #color=(242/255,172/255,142/255)
    plt.ylim((yLimLowLst[i],yLimHighLst[i]))
    plt.ylabel(titleLst[i],fontsize=40)
    plt.xticks(np.arange(len(list(lowres)))+width*0.5, xGroup, color='black', rotation=0,fontsize='30', horizontalalignment='center')
    plt.yticks(fontsize='35')
    plt.grid(axis='y',zorder=0,linewidth=1.5,color='grey')

    #plt.xticks(np.arange(len(list(lowres)))+width*1.6, xGroup, color='black', rotation=0, fontweight='bold', fontsize='17', horizontalalignment='right')
    plt.subplots_adjust(bottom=0.15)
    plt.tight_layout()
    plt.savefig(titleLst[i]+'.pdf')
    plt.show()





# men_means = [0.831503842,0.796520424,0.927179963,0.713821892,0.763493167]
# women_means = [0.888035126,0.883509834,0.997217069,0.92393321,0.850359046]
#
# N=5
# ind = np.arange(N)
# width = 0.35
# plt.bar(ind, men_means, width, label='Men')
# plt.bar(ind + width, women_means, width,
#     label='Women')
#
# plt.ylabel('Scores')
# plt.title('Scores by group and gender')
#
# plt.xticks(ind + width / 2, ('G1', 'G2', 'G3', 'G4', 'G5'))
# plt.legend(loc='best')
# plt.show()