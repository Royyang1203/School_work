import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider
from mpl_toolkits.mplot3d import Axes3D
import pandas as pd
from pathlib import Path
import matplotlib
matplotlib.use('TkAgg')


data_dir = str(Path(fr"./data/train.csv"))
data = pd.read_csv(data_dir)

# 創建一個3D圖形
fig = plt.figure()
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')

# 繪製散點圖
ax.scatter(data['x1'].to_numpy(), data['x2'].to_numpy(
), data['y'].to_numpy(), c=data['y'].to_numpy(), cmap='viridis', marker='o')

# 設置標籤
ax.set_xlabel('X1')
ax.set_ylabel('X2')
ax.set_zlabel('Y')

# 為拉桿創建軸
slider_ax = plt.axes([0.25, 0.05, 0.5, 0.03], facecolor='lightgoldenrodyellow')

# 創建拉桿
slider = Slider(slider_ax, 'Azimuth', 0, 360, valinit=0)

# 更新函數


def update(val):
    azimuth = slider.val
    ax.view_init(elev=None, azim=azimuth)
    fig.canvas.draw_idle()


# 連接拉桿和更新函數
slider.on_changed(update)

# 顯示圖形
plt.show()
