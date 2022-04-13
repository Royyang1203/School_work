from copy import deepcopy
import numpy as np
import copy


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

a = [1, [6, 6, 6], 3]
b = copy.deepcopy(a)
b[1][0] = 5
print(a, b, sep="\n")
