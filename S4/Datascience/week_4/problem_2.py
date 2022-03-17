# 410921208_楊右宇
# Python 3.9.7

import numpy as np

data = [['CITYA1', 128], ['CITYA2', 32], ['CITYA3', 11], ['CITYA4', 20],
        ['CITYA5', 30], ['CITYA6', 22], ['CITYA7', 30], ['CITYA8', 19],
        ['CITYA9', 19], ['CITYB1', 145], ['CITYB2', 27], ['CITYB3', 36],
        ['CITYB4', 25], ['CITYB5', 19], ['CITYB6', 38], ['CITYB7', 26],
        ['CITYB8', 12], ['CITYD1', 20], ['CITYD2', 35], ['CITYD3', 75],
        ['CITYD4', 42], ['CITYD5', 98], ['CITYD6', 52], ['CITYD7', 132],
        ['CITYE1', 122], ['CITYE2', 87], ['CITYE3', 136], ['CITYE4', 23]]

data = [['large' if d[1] > 50 else 'small', *d] for d in data]
# print(data)

nd = np.array(data, dtype=('U10'))
print(nd)
num1 = 0
num2 = 0
num3 = 0
num4 = 0

for i in nd:
    if '8' in i[1]:
        num1 += int(i[2])

    num2 += int(i[2])

    if 'D' in i[1]:
        num3 += int(i[2])
        num4 += 1

print('total number of employee at 8th city : ', num1)
print('Employee in last city : ', nd[-1, 2])
print('total number of employee : ', num2)
print('average number of employee : ', int(num2 / len(nd)))
print('total number of employee at city code D :  {}  for  {}  city then average was  {}'.format(
    num3, num4, round(num3 / num4, 2)))

# total number of employee at 8th city :  31
# Employee in last city :  23
# total number of employee :  1461
# average number of employee :  52
# total number of employee at city code D :  454  for  7  city then average was  64.86

# ndata = np.zeros(len(data), dtype={'names': ('size', 'name', 'employee'),
#                                    'formats': ('U10', 'U10', 'U10')})
# print(ndata.dtype)
# ndata['name'] = nd[:, 0]
# ndata['employee'] = nd[:, 1]
# print(ndata.dtype)

# for i in ndata:
#     if int(i[2]) > 50:
#         i[0] = 'large'
#     else:
#         i[0] = 'small'
# print(ndata)

# for i in ndata:
#     print(i)
# for d in nd:
#     if int(d[1]) > 50:
#         d += ['large']
#     print(d)
