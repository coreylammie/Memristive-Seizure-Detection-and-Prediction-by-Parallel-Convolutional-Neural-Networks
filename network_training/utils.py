import torch
import numpy as np


def foldretrieve(fold,foldsData,foldsLabel):
    testData = foldsData[fold]
    testLabel = foldsLabel[fold]
    allData = foldsData[0:fold]+foldsData[fold:-1]
    allLabel = foldsLabel[0:fold]+foldsLabel[fold:-1]
    try:
        trainData = np.concatenate([*allData])
    except:
        trainData = allData

    try:
        trainLabel = np.concatenate([*allLabel])
    except:
        trainLabel = allLabel

    trainData = np.expand_dims(trainData,1)
    testData = np.expand_dims(testData,1)

    trainData = torch.tensor(trainData)
    testData = torch.tensor(testData)
    trainLabel = torch.tensor(trainLabel)
    testLabel = torch.tensor(testLabel)
    return trainData,testData,trainLabel,testLabel