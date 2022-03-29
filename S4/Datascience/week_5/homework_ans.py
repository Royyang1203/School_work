from tkinter.tix import DisplayStyle
import pandas as pd

data1 = r'D:\OneDrive - 國立東華大學\code\5_School_Work\S4\Datascience\week_5\data.csv'
df = pd.read_csv(data1)
# print(df)

c_df2 = df.groupby(['High school system', 'Gender']).agg(
    Num_of_graduates=pd.NamedAgg(column="Num of graduates", aggfunc="sum"),
    Num_of_enroll_in_police_university=pd.NamedAgg(
        column="Num of enroll in police university", aggfunc="sum"),
    Num_of_enroll_in_police_college=pd.NamedAgg(
        column="Num of enroll in police college", aggfunc="sum"),
    Num_of_enroll_in_military_school=pd.NamedAgg(
        column="Num of enroll in military school", aggfunc="sum"),
    count=pd.NamedAgg(column="High school system", aggfunc="count")).reset_index()

c_df2['Military school enrollment average'] = c_df2['Num_of_enroll_in_military_school']/c_df2['count']
c_df2['police university enrollment rate'] = c_df2['Num_of_enroll_in_police_university'] / \
    c_df2['Num_of_graduates']
c_df2['Police college enrollment rate'] = c_df2['Num_of_enroll_in_police_college'] / \
    c_df2['Num_of_graduates']
c_df2['Military school enrollment rate'] = c_df2['Num_of_enroll_in_military_school'] / \
    c_df2['Num_of_graduates']

c_df2 = c_df2.drop(['count', 'Num_of_enroll_in_military_school'], axis=1)
print(c_df2)
