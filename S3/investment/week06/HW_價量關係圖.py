import matplotlib.pyplot as plt
import pandas as pd

df = pd.read_csv(r"C:\Coding\43_School_S3\investment\week06\2330.csv",
                 index_col=0, parse_dates=True)

print(df)

high = df.High.max()
low = df.Low.min()
# print(high, low)
pic = plt.figure(figsize=(8, 4))  # 設定圖形大小
close = pic.add_axes([0, 0.2, 1, 0.9])  # 最上方的圖
volume = pic.add_axes([0, 0, 1, 0.2])  # 中間的圖
close.plot(df.Close)
close.axhline(y=high, xmin=0, xmax=1, color="Red", label=high)
close.axhline(y=low, xmin=0, xmax=1, color="Red", label=low)

# volume.plot(df.Volume)
plt.title("2002")
plt.xlabel("day")
plt.ylabel("price")
# plt.gca().xaxis.set_major_locator(x.MonthLocator())
plt.legend()

plt.show()
