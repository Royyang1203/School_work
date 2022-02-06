# 請設計一程式分析 2330 在 7月與8月 的表現，讀取 2330.csv 檔後計算出 每月平均股價(收盤價)、當月的最高價 及 成交量(月總和)

# CSV資料(滑鼠右鍵，另存連結為....)

# 範例輸出:

#     7 月的平均股價為: 370.74  元

#     當月的最高價為:   466.5  元

#     本月成交量為:  1468402  張


#     8 月的平均股價為: 429.67  元

#     當月的最高價為:   453.5  元

#     本月成交量為:  1001180  張

import pandas as pd
from pandas.core.frame import DataFrame


def info_of_month(_df, _year, _month):
    """Selection values by DateTime then print the informations of the table"""

    # Selecting values
    _df = _df.loc[str(_year) + "-" + str(_month).zfill(2)]

    # print informations
    print(int(_month), "月的", end="")
    print("平均股價為:", round(_df["Close"].mean(), 2), "元")
    print("當月的最高價為:  ", _df["High"].max(), "元")
    # print("  最低價為:", _df["Low"].min(), "元")
    print("本月成交量為:", _df["Volume"].sum(), "張")


def read_stock_data(ticker):
    """read the full data of the file as a dataframe"""
    file_position = r"C:\Coding\43_School_S3\投資\Week02" + "\\" + ticker + ".csv"
    _df = pd.read_csv(file_position,
                      index_col=0, parse_dates=True)
    return _df


def main():
    ticker = "2330"
    year = 2020

    for i in range(7, 9):
        info_of_month(read_stock_data(ticker), year, i)


if __name__ == "__main__":
    main()
