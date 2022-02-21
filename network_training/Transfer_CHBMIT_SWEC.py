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

import pprint


# -----------------------------------------------------------
rootPath = '/scratch/jcu/cl/TBioCAS/processed_data/'
device = 'cuda' if torch.cuda.is_available() else 'cpu'
seed = 42
patients = ['01']
datasets = ['CHBMIT', 'SWEC_ETHZ']
dataType = 'features'
numFold = 5
bS = 1 # 32
num_epoch_retrain = 10 # To investigate further- this has been chosen arbitrarily
network_size = 32
# -----------------------------------------------------------

print('Using {} device'.format(device),'\n')
### Data Loading (preictal 0, interictal 1)
# torch.manual_seed(seed)
# np.random.seed(seed)
# torch.backends.cudnn.benchmark = False
# torch.use_deterministic_algorithms(True)
# torch.backends.cudnn.deterministic = True
# os.environ['PYTHONHASHSEED'] = str(seed)

# if dataType == 'features':
#     allData = np.empty((0, 176))
#     rawLabel = np.empty((0,), dtype=int)

# for patient in patients:
#     newData = np.load(rootPath+dataType+'/'+dataset+'_'+'patient'+'_'+patient+'_'+'synthetic_preictal.npy')
#     allData = np.append(allData,newData,axis=0)
#     rawLabel = np.append(rawLabel,np.zeros((newData.shape[0],),dtype=int),axis=0)
#     newData = np.load(rootPath+dataType+'/'+dataset+'_'+'patient'+'_'+patient+'_'+'preictal.npy')
#     allData = np.append(allData,newData,axis=0)
#     rawLabel = np.append(rawLabel,np.zeros((newData.shape[0],),dtype=int),axis=0)
#     newData = np.load(rootPath+dataType+'/'+dataset+'_'+'patient'+'_'+patient+'_'+'interictal.npy')
#     allData = np.append(allData,newData,axis=0)
#     rawLabel = np.append(rawLabel,np.ones((newData.shape[0],),dtype=int),axis=0)

# allLabel = np.zeros((rawLabel.size, rawLabel.max()+1))
# allLabel[np.arange(rawLabel.size),rawLabel] = 1

# pca = PCA(n_components=64)
# allData = pca.fit_transform(allData)

# inputbits = 6
# inputstep = (np.amax(allData) - np.amin(allData)) / (2**inputbits-1)
# allData = np.round(allData/inputstep)
# allData *= inputstep

# randInd = np.arange(0,len(allData))
# np.random.shuffle(randInd)
# allData = allData[randInd]
# allLabel = allLabel[randInd]
# allData = allData[:math.floor(allData.shape[0]/5)*5]
# allLabel = allLabel[:math.floor(allLabel.shape[0]/5)*5]

# foldsData = np.split(allData,numFold)
# foldsLabel = np.split(allLabel,numFold)

loss_function = nn.BCEWithLogitsLoss()

df = pd.DataFrame(columns=['Patient', 'Fold', 'Epoch', 'Loss', 'Train Accuracy', 'Test Accuracy'])
for patient in patients:
    print('--------------------------------')
    print(f'Patient {patient}')
    for fold in range(0,numFold):
        # trainData, testData, trainLabel, testLabel = foldretrieve(fold, foldsData, foldsLabel)
        print(f'Fold Number {fold}')
        network = ParallelConvolution(size=network_size).to(device)
        # Freeze the weights of all layers
        for name, param in network.named_parameters():
            print(name)
            param.requires_grad = False

        # # Unfreeze the weights of the linear layers
        # network.linear.weight.requires_grad = True
        # network.linear.bias.requires_grad = True
        network.classification.weight.requires_grad = True
        network.classification.bias.requires_grad = True
        print(network.conv1.weight[0][0])
        print(network.classification.weight[0])

        optimizer = torch.optim.Adam(network.parameters())
        for i in range(10):
            data = torch.rand(bS, 1, 64).to(device)
            label = torch.rand(bS, 2).int().to(device)
            optimizer.zero_grad()
            output = network(data)
            loss = loss_function(output, label.float())
            loss.backward()
            optimizer.step()

        print(network.conv1.weight[0][0])
        print(network.classification.weight[0])
        exit(0)