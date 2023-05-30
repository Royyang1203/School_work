from collections import OrderedDict
from typing import Any, Tuple, Callable, List, Optional, Type, Union

import torch
import torch.nn as nn
import torch.nn.functional as F
from torch import Tensor

import math


# 定義ResBlock類，這是ResNet的基本結構塊
class ResBlock(nn.Module):
    # 初始化函數
    def __init__(self, in_channel, out_channel, stride=1):
        # 調用父類的初始化函數
        super().__init__()
        # 左側的卷積結構
        self.left = nn.Sequential(
            # 卷積層
            nn.Conv2d(in_channel, out_channel, kernel_size=3,
                      stride=stride, padding=1, bias=False),
            # 批量標準化層
            nn.BatchNorm2d(out_channel),
            # 激活函數層
            nn.ReLU(inplace=True),
            # 再一次的卷積層
            nn.Conv2d(out_channel, out_channel, kernel_size=3,
                      stride=1, padding=1, bias=False),
            # 再一次的批量標準化層
            nn.BatchNorm2d(out_channel)
        )
        # shortcut結構，當輸入和輸出的通道數不同或者步長不為1時，需要進行調整
        self.shortcut = nn.Sequential()
        if stride != 1 or in_channel != out_channel:
            self.shortcut = nn.Sequential(
                # 1x1卷積層，用來改變通道數和調整特徵圖的尺寸
                nn.Conv2d(in_channel, out_channel, kernel_size=1,
                          stride=stride, bias=False),
                # 批量標準化層
                nn.BatchNorm2d(out_channel)
            )

    # 定義前向傳播函數
    def forward(self, x):
        # 獲取左側結構的輸出
        out = self.left(x)
        # 將左側結構的輸出和shortcut結構的輸出進行相加
        out = out + self.shortcut(x)
        # 將相加後的結果通過ReLU激活函數
        out = F.relu(out)
        # 返回輸出結果
        return out



class InvertedResidualBlock(nn.Module):
    def __init__(self, in_channel, out_channel, stride, expand_ratio):
        super().__init__()
        # 步長
        self.stride = stride

        # 通道擴展，得到隱藏層的通道數
        hidden_dim = int(in_channel * expand_ratio)
        # 卷積操作序列
        self.conv = nn.Sequential(
            # pw, 1x1 卷積，通道數從 in_channel 擴展到 hidden_dim
            nn.Conv2d(in_channel, hidden_dim, 1, 1, 0, bias=False),
            nn.BatchNorm2d(hidden_dim),
            nn.ReLU(inplace=True),
            # dw, 3x3 深度卷積，步長為 stride，保持通道數為 hidden_dim
            nn.Conv2d(hidden_dim, hidden_dim, 3, stride, 1, groups=hidden_dim, bias=False),
            nn.BatchNorm2d(hidden_dim),
            nn.ReLU(inplace=True),
            # pw-linear, 1x1 卷積，通道數從 hidden_dim 減少到 out_channel
            nn.Conv2d(hidden_dim, out_channel, 1, 1, 0, bias=False),
            nn.BatchNorm2d(out_channel),
        )

        # shortcut 結構，如果步長不為 1 或輸入和輸出的通道數不同，則需要調整特徵圖的尺寸和通道數
        self.shortcut = nn.Sequential()
        if self.stride != 1 or in_channel != out_channel:
            self.shortcut = nn.Sequential(
                # 1x1 卷積，用來調整特徵圖的尺寸和通道數
                nn.Conv2d(in_channel, out_channel, 1, stride, bias=False),
                nn.BatchNorm2d(out_channel)
            )

    # 前向傳播函數
    def forward(self, x):
        # 返回卷積操作和 shortcut 結構的輸出之和
        return self.conv(x) + self.shortcut(x)







# 定義一個基本的conv block，順序為 conv -> norm -> relu
class CONV_BN_RELU(nn.Sequential):
    def __init__(self, num_input_features: int, num_output_features: int, kernel_size, padding, stride=1):
        super().__init__()
        self.add_module("conv", nn.Conv2d(
            num_input_features, num_output_features, kernel_size=kernel_size, stride=stride, padding=padding, bias=False))
        self.add_module("norm", nn.BatchNorm2d(num_output_features))
        self.add_module("relu", nn.ReLU(inplace=True))

class SqnxtBlock(nn.Module):
    def __init__(self, in_channel, out_channel, stride):
        super().__init__()
        # 建立一個卷積層序列，包含五個卷積
        self.block = nn.Sequential(
            # 1x1 卷積，輸入通道縮小一半
            CONV_BN_RELU(in_channel, in_channel // 2, kernel_size=1, stride=stride, padding=0),
            # 1x1 卷積，輸入通道縮小一半
            CONV_BN_RELU(in_channel // 2, in_channel // 4, kernel_size=1, padding=0),
            # 1x3 卷積，輸入通道放大一倍
            CONV_BN_RELU(in_channel // 4, in_channel // 2, kernel_size=(1, 3), padding=(0, 1)),
            # 3x1 卷積，輸入通道不動
            CONV_BN_RELU(in_channel // 2, in_channel // 2, kernel_size=(3, 1), padding=(1, 0)),
            # 1x1 卷積，輸出通道數量為 out_channel(放大一倍)
            nn.Conv2d(in_channel // 2, out_channel, kernel_size=1, padding=0, bias=False),
            # 批次正規化
            nn.BatchNorm2d(out_channel)
        )
        # shortcut 結構，如果步長為 2 或輸出通道與輸入通道不同，則需要進行調整
        self.shortcut = nn.Sequential()
        if stride == 2 or out_channel != in_channel:
            self.shortcut = nn.Sequential(
                # 1x1 卷積，調整特徵圖的尺寸與通道數
                nn.Conv2d(in_channel, out_channel, kernel_size=1, stride=stride, padding=0, bias=False),
                # 批次正規化
                nn.BatchNorm2d(out_channel)
            )

    # 前向傳播函數
    def forward(self, x):
        out = self.block(x)
        # 將卷積層序列的輸出與 shortcut 結構的輸出進行相加
        out = out + self.shortcut(x)
        # 通過 ReLU 激活函數
        out = F.relu(out)
        return out




class MusicScaleNet(nn.Module):
    def __init__(
            self,
            block,
            block_config,
            num_init_features: int = 16,
            num_classes: int = 1000,
    ):

        super().__init__()

        # building first layer
        self.features = nn.Sequential(
            OrderedDict(
                [
                    ("conv0", nn.Conv2d(3, num_init_features,
                     kernel_size=5, stride=2, padding=1, bias=False)),
                    ("norm0", nn.BatchNorm2d(num_init_features)),
                    ("relu0", nn.ReLU(inplace=True)),
                    ("pool0", nn.MaxPool2d(kernel_size=3, stride=2, padding=1)),
                ]
            )
        )

        # bottlenect layer
        # 會依照block的名稱使用對應的block建構
        num_features = num_init_features
        if block == 'ResBlock':
            for i, [n, c, s] in enumerate(block_config):
                for j in range(n):
                    if j == 0:
                        self.features.add_module(f"{block}{i}_{j}", ResBlock(num_features, c, s))
                        num_features = c
                    else:
                        self.features.add_module(f"{block}{i}_{j}", ResBlock(num_features, num_features, 1))

        elif block == 'SqnxtBlock':
            for i, [n, c, s] in enumerate(block_config):
                for j in range(n):
                    if j == 0:
                        self.features.add_module(f"{block}{i}_{j}", SqnxtBlock(num_features, c, s))
                        num_features = c
                    else:
                        self.features.add_module(f"{block}{i}_{j}", SqnxtBlock(num_features, num_features, 1))

        elif block == 'InvertedResidualBlock':
            # building inverted residual blocks
            for i, [n, t, c, s] in enumerate(block_config):
                for j in range(n):
                    if j == 0:
                        self.features.add_module(f"{block}{i}_{j}", InvertedResidualBlock(num_features, c, s, expand_ratio=t))
                        num_features = c
                    else:
                        self.features.add_module(f"{block}{i}_{j}", InvertedResidualBlock(num_features, num_features, 1, expand_ratio=t))

        # building classifier
        self.classifier = nn.Linear(num_features, num_classes)

        # initializing weights
        for m in self.modules():
            if isinstance(m, nn.Conv2d):
                nn.init.kaiming_normal_(m.weight)
            elif isinstance(m, nn.BatchNorm2d):
                nn.init.constant_(m.weight, 1)
                nn.init.constant_(m.bias, 0)
            elif isinstance(m, nn.Linear):
                nn.init.constant_(m.bias, 0)

    def forward(self, x):
        features = self.features(x)
        out = F.adaptive_avg_pool2d(features, (1, 1))
        out = torch.flatten(out, 1)
        out = self.classifier(out)
        return out
