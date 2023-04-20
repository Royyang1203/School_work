import pandas as pd

df = pd.read_csv(
    r"5_School_Work\S4\compiler\HW2data.csv")


df['Score'] = df.loc[:, 'HW1'] * 0.1 + df.loc[:, 'HW2'] * 0.1 \
    + df.loc[:, 'HW3'] * 0.1 + df.loc[:, 'Midterm'] * \
    0.3 + df.loc[:, 'Final'] * 0.4
df['Score'] = round(df['Score'])
for i in range(len(df)):
    if 0 <= df.loc[df.index[i], 'Score'] < 50:
        df.loc[df.index[i], 'Grade'] = 'E'
    elif 50 <= df.loc[df.index[i], 'Score'] < 60:
        df.loc[df.index[i], 'Grade'] = 'D'
    elif 60 <= df.loc[df.index[i], 'Score'] < 63:
        df.loc[df.index[i], 'Grade'] = 'C-'
    elif 63 <= df.loc[df.index[i], 'Score'] < 67:
        df.loc[df.index[i], 'Grade'] = 'C'
    elif 67 <= df.loc[df.index[i], 'Score'] < 70:
        df.loc[df.index[i], 'Grade'] = 'C+'
    elif 70 <= df.loc[df.index[i], 'Score'] < 73:
        df.loc[df.index[i], 'Grade'] = 'B-'
    elif 73 <= df.loc[df.index[i], 'Score'] < 77:
        df.loc[df.index[i], 'Grade'] = 'B'
    elif 77 <= df.loc[df.index[i], 'Score'] < 80:
        df.loc[df.index[i], 'Grade'] = 'B+'
    elif 80 <= df.loc[df.index[i], 'Score'] < 85:
        df.loc[df.index[i], 'Grade'] = 'A-'
    elif 85 <= df.loc[df.index[i], 'Score'] < 90:
        df.loc[df.index[i], 'Grade'] = 'A'
    elif 90 <= df.loc[df.index[i], 'Score'] <= 100:
        df.loc[df.index[i], 'Grade'] = 'A+'
df.to_csv(r"5_School_Work\S4\compiler\result_Python.csv", index=False)
