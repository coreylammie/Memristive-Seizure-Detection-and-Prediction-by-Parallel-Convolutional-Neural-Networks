import torch
from torch import nn
import torch.nn.functional as F
import brevitas.nn as qnn


### Network Definition
class ParallelConvolution(nn.Module):
    def __init__(self, size=32):
        super(ParallelConvolution, self).__init__()
        self.conv1 = qnn.QuantConv1d(1,32,size,weight_bit_width=6)
        self.conv2 = qnn.QuantConv1d(1,32,62-size,weight_bit_width=6)
        self.avgpool = nn.AvgPool1d(2)
        self.flatten = nn.Flatten()
        self.dropout = nn.Dropout(0.5)
        self.linear = qnn.QuantLinear(1088,8,bias=True,weight_bit_width=4)
        self.classification = qnn.QuantLinear(8,2,bias=True,weight_bit_width=4)

    def forward(self,x):
        out1 = F.relu(self.conv1(x))
        out2 = F.relu(self.conv2(x))
        x = torch.cat((out1, out2),dim=2)
        x = self.avgpool(x)
        x = self.flatten(x)
        x = self.dropout(x)
        x = self.linear(x)
        out = self.classification(x)
        return out