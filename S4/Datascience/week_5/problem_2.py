import pandas as pd

csv = r'D:\OneDrive - 國立東華大學\code\5_School_Work\S4\Datascience\week_5\data.csv'
df = pd.read_csv(csv, encoding="utf8", header=0)


number1 = df[['High school system', 'Gender', 'Num of graduates']
             ].groupby(['High school system', 'Gender'])
number2 = df[['High school system', 'Gender', 'Num of enroll in police university']].groupby([
                                                                                             'High school system', 'Gender'])
number3 = df[['High school system', 'Gender', 'Num of enroll in police college']].groupby(
    ['High school system', 'Gender'])
number4 = df[['High school system', 'Gender', 'Num of enroll in military school']].groupby(
    ['High school system', 'Gender'])
number5 = df[['High school system', 'Gender', 'Num of graduates',
              'Num of enroll in police university']].groupby(['High school system', 'Gender'])
number6 = df[['High school system', 'Gender', 'Num of graduates',
              'Num of enroll in police college']].groupby(['High school system', 'Gender'])
number7 = df[['High school system', 'Gender', 'Num of graduates',
              'Num of enroll in military school']].groupby(['High school system', 'Gender'])

first = number1.sum()
second = number2.sum()
third = number3.sum()
fourth = pd.DataFrame(round(number4.mean(), 2))
fifth = pd.DataFrame((number5['Num of enroll in police university'].sum(
)/number5['Num of graduates'].sum()).mul(100).round(1).astype(str) + '%', columns=['Police university rate'])
sixth = pd.DataFrame(number6['Num of enroll in police college'].sum(
)/number6['Num of graduates'].sum(), columns=['Police college rate'])
sixth = sixth.mul(100).round(1).astype(str) + '%'
seventh = pd.DataFrame(number7['Num of enroll in military school'].sum(
)/number7['Num of graduates'].sum(), columns=['Military school enrollment rate '])
seventh = seventh.mul(100).round(1).astype(str) + '%'

result = pd.concat([first, second, third, fourth, fifth,
                   sixth, seventh], axis=1, join="inner")
result.rename(columns={"Num of enroll in military school":
              "average num of enroll in military school"}, inplace=True)
print(result)
