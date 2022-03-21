import pandas as pd
import numpy as np

data = [[100, 200, 300], [300, 150, 200], [400, 360, 230], [104, 140, 444]]

df = pd.DataFrame(data)
print(df)
df.iloc[1, 1] = np.nan
print(df)
print(df.dtypes)
