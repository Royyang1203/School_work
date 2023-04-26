from pathlib import Path
import pandas as pd
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.widgets import Slider
import matplotlib.pyplot as plt
import numpy as np
import matplotlib

# matplotlib.use('TkAgg')


data_dir = str(Path(fr"./data/train.csv"))
data = pd.read_csv(data_dir)

# 創建一個3D圖形
fig = plt.figure()
fig = plt.figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')

# 繪製散點圖
ax.scatter(data['x1'].to_numpy(), data['x2'].to_numpy(),
           data['y'].to_numpy(), c=data['y'].to_numpy(), cmap='viridis', marker='o')

# 設置標籤
ax.set_xlabel('X1')
ax.set_ylabel('X2')
ax.set_zlabel('Y')

# 為拉桿創建軸
slider_ax_azimuth = plt.axes(
    [0.25, 0.05, 0.5, 0.03], facecolor='lightgoldenrodyellow')
slider_ax_elevation = plt.axes(
    [0.25, 0.10, 0.5, 0.03], facecolor='lightgoldenrodyellow')
slider_ax_zoom = plt.axes([0.25, 0.15, 0.5, 0.03],
                          facecolor='lightgoldenrodyellow')

# 創建拉桿
slider_azimuth = Slider(slider_ax_azimuth, 'Azimuth', 0, 360, valinit=0)
slider_elevation = Slider(
    slider_ax_elevation, 'Elevation', -90, 90, valinit=30)
slider_zoom = Slider(slider_ax_zoom, 'Zoom', 1, 20, valinit=10)

# 更新函數


def update(val):
    azimuth = slider_azimuth.val
    elevation = slider_elevation.val
    zoom = slider_zoom.val
    ax.view_init(elev=elevation, azim=azimuth)
    ax.dist = zoom
    fig.canvas.draw_idle()


# 連接拉桿和更新函數
slider_azimuth.on_changed(update)
slider_elevation.on_changed(update)
slider_zoom.on_changed(update)

# 顯示圖形
plt.show()
