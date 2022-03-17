# 410921208_楊右宇
# Python 3.9.7
import numpy as np

score = []

for i in range(2):
    count = 0
    score += [[]]

    while (s := input()) != "-1":

        if not s:
            continue
        if count % 3 == 0:
            score[i] += [[]]

        score[i][count // 3] += [int(s)]
        count += 1


arr = np.array(score)
res = (arr[0] + arr[1]) / 2
res[:, 0] += 10
res[res > 100] = 100
res[res < 60] = -1
print(arr[0], arr[1], res, sep='\n\n')


# input
# 65
# 70
# 85
# 90
# 100
# 70
# 70
# 50
# 20
# -1
# 80
# 90
# 60
# 30
# 95
# 60
# 75
# 20
# 80
# -1
