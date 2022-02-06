import matplotlib.pyplot as plt
from datetime import datetime

SData = open(r'C:\Coding\43_School_S3\investment\week06\2002.csv').readlines()
SData1 = [line.strip('\n').split(',') for line in SData[1:]]

s_date = [datetime.strptime(line[0], r'%Y/%m/%d') for line in SData1]
s_close = [float(line[4]) for line in SData1]
plt.plot(s_date, s_close)
plt.gcf().autofmt_xdate()  # 自動旋轉日期標記
plt.show()
