# 410921208_楊右宇
# Python 3.9.7

import pandas as pd
import numpy as np

df = pd.read_csv(
    r'D:\OneDrive - 國立東華大學\code\5_School_Work\S4\Datascience\week_5\data.csv')


res = pd.DataFrame(0, index=range(0, 6), columns=['High school system', 'Gender', 'Num of graduates', 'enroll in police university', 'enroll in police college',
                   'average enroll in military', 'Police university enrollment rate', 'Police college enrollment rate', 'Military school enrollment rate'])

res.iloc[:, 0] = ['National', 'National', 'county & city',
                  'county & city', 'private', 'private']
res.iloc[:, 1] = ['male', 'female', 'male', 'female', 'male', 'female']

for i in range(6):

    target = df[(df.loc[:, 'High school system'] == res.loc[res.index[i], 'High school system']) &
                (df.loc[:, 'Gender'] == res.loc[res.index[i], 'Gender'])]

    res.loc[res.index[i], 'Num of graduates'] = \
        target.loc[:, 'Num of graduates'].sum()

    res.loc[res.index[i], 'enroll in police university'] = \
        target.loc[:, 'Num of enroll in police university'].sum()
    res.loc[res.index[i], 'enroll in police college'] = \
        target.loc[:, 'Num of enroll in police college'].sum()

    res.loc[res.index[i], 'average enroll in military'] = \
        round(target.loc[:, 'Num of enroll in military school'].mean(), 2)

    res.loc[res.index[i], 'Police university enrollment rate'] = \
        '{:.2f}'.format(round(res.loc[res.index[i], 'enroll in police university'] /
                              res.loc[res.index[i], 'Num of graduates'], 4) * 100) + '%'
    res.loc[res.index[i], 'Police college enrollment rate'] = \
        '{:.2f}'.format(round(res.loc[res.index[i], 'enroll in police college'] /
                              res.loc[res.index[i], 'Num of graduates'], 4) * 100) + '%'
    res.loc[res.index[i], 'Military school enrollment rate'] = \
        '{:.2f}'.format(round(target.loc[:, 'Num of enroll in military school'].max() /
                              res.loc[res.index[i], 'Num of graduates'], 4) * 100) + '%'


print(res)
# res.to_csv('result.csv')
