aduates'] = target.loc[:,
                                                           'Num of graduates'].sum()
    res.loc[res.index[i], 'enroll in police university'] = \
        target.iloc[:, 'Num of enroll in National university'].sum()