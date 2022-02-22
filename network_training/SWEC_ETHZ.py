import os
import numpy as np
import torch
from torch import nn
from torch.utils.data import DataLoader, Dataset
from torchvision import datasets, transforms
from torchsummary import summary
import torch.nn.functional as F
from sklearn.model_selection import KFold
from sklearn import preprocessing
import matplotlib.pyplot as plt
import math
from sklearn.decomposition import PCA
import sklearn
import brevitas.nn as qnn
import pandas as pd

from Network import ParallelConvolution
from utils import foldretrieve


# -----------------------------------------------------------
rootPath = '/scratch/jcu/cl/TBioCAS/processed_data/'
device = 'cuda' if torch.cuda.is_available() else 'cpu'
seed = 8
patients = ['01', '02', '03', '05', '06']
dataset = 'SWEC_ETHZ'
dataType = 'features'
numFold = 5
bS = 32
num_epoch = 100
network_size = 32
# -----------------------------------------------------------

print('Using {} device'.format(device),'\n')
### Data Loading (preictal 0, interictal 1)
torch.manual_seed(seed)
np.random.seed(seed)
torch.backends.cudnn.benchmark = False
torch.use_deterministic_algorithms(True)
torch.backends.cudnn.deterministic = True
os.environ['PYTHONHASHSEED'] = str(seed)

df = pd.DataFrame(columns=['Patient', 'Fold', 'Epoch', 'Loss', 'Train Accuracy', 'Test Accuracy'])
for patient in patients:
    allData = np.empty((0, 176))
    rawLabel = np.empty((0,), dtype=int)

    newData = np.load(rootPath+dataType+'/'+dataset+'_'+'patient'+'_'+patient+'_'+'synthetic_preictal.npy')
    allData = np.append(allData,newData,axis=0)
    rawLabel = np.append(rawLabel,np.zeros((newData.shape[0],),dtype=int),axis=0)
    newData = np.load(rootPath+dataType+'/'+dataset+'_'+'patient'+'_'+patient+'_'+'preictal.npy')
    allData = np.append(allData,newData,axis=0)
    rawLabel = np.append(rawLabel,np.zeros((newData.shape[0],),dtype=int),axis=0)
    newData = np.load(rootPath+dataType+'/'+dataset+'_'+'patient'+'_'+patient+'_'+'interictal.npy')
    allData = np.append(allData,newData,axis=0)
    rawLabel = np.append(rawLabel,np.ones((newData.shape[0],),dtype=int),axis=0)

    allLabel = np.zeros((rawLabel.size, rawLabel.max()+1))
    allLabel[np.arange(rawLabel.size),rawLabel] = 1

    pca = PCA(n_components=64)
    allData = pca.fit_transform(allData)

    inputbits=6
    inputstep=(np.amax(allData) - np.amin(allData))/(2**inputbits-1)
    allData = np.round(allData/inputstep)
    allData *= inputstep

    randInd = np.arange(0,len(allData))
    np.random.shuffle(randInd)
    allData = allData[randInd]
    allLabel = allLabel[randInd]
    allData = allData[:math.floor(allData.shape[0]/5)*5]
    allLabel = allLabel[:math.floor(allLabel.shape[0]/5)*5]

    foldsData = np.split(allData,numFold)
    foldsLabel = np.split(allLabel,numFold)

    loss_function = nn.BCEWithLogitsLoss()
    print('--------------------------------')
    print(f'Patient {patient}')
    for fold in range(0,numFold):
        trainData, testData, trainLabel, testLabel = foldretrieve(fold, foldsData, foldsLabel)
        print(f'Fold Number {fold}')
        network = ParallelConvolution(size=network_size).to(device)
        optimizer = torch.optim.Adam(network.parameters())
        lossHist = []
        testAccHist = []
        trainAccHist = []
        bestAcc = 0
        bestSen = 0
        bestSpe = 0
        bestFPC = 1e10
        bestAUR = 0
        bestEpoch = [0] * 5
        for epoch in range(num_epoch):
            trainCorrect = 0
            trainTotal = 0
            testCorrect = 0
            testTotal = 0
            trainOutputs = np.empty((0,1))
            trainLabels = np.empty((0,1))
            trainCM = np.zeros((2, 2))
            testOutputs = np.empty((0,1))
            testLabels = np.empty((0,1))
            testCM = np.zeros((2, 2))
            for i in range(0,len(trainData),bS):
                data = trainData[i:i+bS].to(device,dtype=torch.float)
                label = trainLabel[i:i+bS].to(device,dtype=torch.float)
                # Zero the gradients
                optimizer.zero_grad()
                network.eval()
                # Perform forward pass
                outputs = network(data)
                network.train()
                # Compute loss
                loss = loss_function(outputs, label)
                # Perform backward pass
                loss.backward()
                # Perform optimization
                optimizer.step()
                network.eval()

                outputs = outputs.cpu().detach().numpy()
                label = label.cpu().detach().numpy()
                outputs = np.argmax(outputs,axis=1)
                label = np.argmax(label,axis=1)
                trainCM = np.add(trainCM, sklearn.metrics.confusion_matrix(outputs, label, labels=[0, 1]))
                trainCorrect += np.sum(outputs==label)
                trainTotal += len(outputs)
                trainOutputs = np.append(trainOutputs,outputs.reshape((-1,1)),axis=0)
                trainLabels = np.append(trainLabels,label.reshape((-1,1)),axis=0)

            for i in range(0,len(testData),bS):
                data = testData[i:i+bS].to(device,dtype=torch.float)
                label = testLabel[i:i+bS].to(device,dtype=torch.float)
                network.eval()
                # Perform forward pass
                outputs = network(data)
                # Caclulate statistics
                testCorrect += np.sum(np.argmax(outputs.cpu().detach().numpy(),axis=1)==np.argmax(label.cpu().detach().numpy(),axis=1))
                testTotal += len(outputs)
                outputs = outputs.cpu().detach().numpy()
                label = label.cpu().detach().numpy()
                outputs = np.argmax(outputs,axis=1)
                label = np.argmax(label,axis=1)
                testCM = np.add(testCM, sklearn.metrics.confusion_matrix(outputs, label, labels=[0, 1]))
                testCorrect += np.sum(outputs==label)
                testTotal += len(outputs)
                testOutputs = np.append(testOutputs,outputs.reshape((-1,1)),axis=0)
                testLabels = np.append(testLabels,label.reshape((-1,1)),axis=0)

            if testCorrect/testTotal > bestAcc:
                torch.save(network.state_dict(),'SWEC_ETHZ_P{}F{}.pt'.format(patient,fold))

            trainF1 = sklearn.metrics.f1_score(trainLabels,trainOutputs)
            trainAccuracy = trainCorrect/trainTotal
            trainTN, trainFP, trainFN, trainTP = trainCM.ravel()
            trainSensitivity = trainTP / (trainTP+trainFN)
            trainSpecitivity = trainTN / (trainTN+trainFP)
            try:
                trainAUROC = sklearn.metrics.roc_auc_score(trainLabels, trainOutputs)
            except:
                trainAUROC = 0.

            testF1 = sklearn.metrics.f1_score(testLabels,testOutputs)
            testAccuracy = testCorrect/testTotal
            testTN, testFP, testFN, testTP = testCM.ravel()
            testSensitivity = testTP / (testTP+testFN)
            testSpecitivity = testTN / (testTN+testFP)
            try:
                testAUROC = sklearn.metrics.roc_auc_score(testLabels, testOutputs)
            except:
                testAUROC = 0.

            if testAccuracy > bestAcc:
                bestAcc = testAccuracy
                bestEpoch[0] = epoch
            if testSensitivity > bestSen:
                bestSen = testSensitivity
                bestEpoch[1] = epoch
            if testSpecitivity > bestSpe:
                bestSpe = testSpecitivity
                bestEpoch[2] = epoch
            if testFP < bestFPC:
                bestFPC = testFP
                bestEpoch[3] = epoch
            if testAUROC > bestAUR:
                bestAUR = testAUROC
                bestEpoch[4] = epoch

            print('Epoch:', epoch, 'Train Loss:', loss.item())
            print('Train Accuracy:', trainAccuracy, 'Train Sensitivity:', trainSensitivity, 'Train Specitivity:', trainSpecitivity, 'Train FP Count:', trainFP, 'Train AUROC:', trainAUROC)
            print('Test Accuracy:', testAccuracy, 'Test Sensitivity:', testSensitivity, 'Test Specitivity:', testSpecitivity, 'Test FP Count:', testFP, 'Test AUROC:', testAUROC,)
            print('\n')
            lossHist.append(loss)
            trainAccHist.append(trainCorrect/trainTotal)
            testAccHist.append(testCorrect/testTotal)
            df = df.append({'Patient': patient, 'Fold': fold, 'Epoch': epoch, 'Loss': loss.cpu().item(), 'Train Accuracy': trainAccuracy * 100., 'Test Accuracy': testAccuracy * 100.}, ignore_index=True)
            df.to_csv('SWEC_ETHZ.csv', index=False)