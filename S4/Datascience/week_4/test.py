import numpy as np

data = [['CITYA1', 128], ['CITYA2', 32], ['CITYA3', 11], ['CITYA4', 20]]

res = np.zeros(len(data), dtype={'names': ('size', 'name', 'employee'),
                                 'formats': ('U10', 'U10', 'U10')})
print(res.dtype)
print(res)
res[0][1] = data[0][0]
print(res)

nd = np.array(data, dtype=('U10'))
print(nd)
res['name'] = nd[:, 0]
print(res)

# =====================================

a = 4
print(type(a))
a = (1, 2, 3)
print(type(a))
a = [1, 2, 3]
print(type(a))
a[0] = 0
print(type(a))
