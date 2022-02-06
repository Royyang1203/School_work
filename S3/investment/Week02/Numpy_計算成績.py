# 1. 今有一班級共4n個人(n>0)，老師按修課序號將全班分成n組。

# 2. 規定每一組的第一人是組長，總成績會額外加5分，超出100以100計。

# 3. 每組的平均成績大於80時，整組的總成績會額外加2分，超出100以100計。

# 4. 全班按照n*4的陣列且照組別依下表安排教室座位。

# 第1組第1人(組長)	第1組第2人	第1組第3人	第1組第4人
# 第2組第1人(組長)	第2組第2人	第2組第3人	第2組第4人
# ...	...	...	...
# 第n組第1人(組長)	第n組第2人	第n組第3人	第n組第4人

# 請寫一個程式，要求使用者輸入考試的4n筆成績（整數），使用者輸入一個-1表示完成這次考試成績的輸入。

# 程式中請按教室座位先輸出考試全班的成績（以整數輸出），然後再輸出加分過後的成績，最後再輸出等第成績。

# 成績換算:

#     90分以上為A

#     80分以上為B，類推...

#     60分以下為E

# 範例輸入1：

# 70

# 99

# 80

# 85

# 96

# 50

# 46

# 61

# -1
# 範例輸出1：

# [[70 99 80 85]

#  [96 50 46 61]]


# [[ 77. 100.  82.  87.]

#  [100.  50.  46.  61.]]


# [['C' 'A' 'B' 'B']

#  ['A' 'E' 'E' 'D']]

# Python 3.9.6
import numpy as np

score = []
count = 0

while (s := input()) != "-1":
    if not s:
        continue
    if count % 4 == 0:
        score += [[]]

    score[count // 4] += [int(s)]
    count += 1


arr = np.array(score)
print(arr)
arr[:, 0] += 5

for i, t in enumerate(arr):
    if t.mean() > 80:
        for j, q in enumerate(t):
            arr[i, j] += 2

    for j, q in enumerate(t):
        if q > 100:
            arr[i, j] = 100

print(arr)
# print(type(arr))
rank = []
for i, t in enumerate(arr):
    rank += [[]]
    for j, q in enumerate(t):
        if q > 90:
            rank[i] += ['A']
        elif q > 80:
            rank[i] += ['B']
        elif q > 70:
            rank[i] += ['C']
        elif q > 60:
            rank[i] += ['D']
        else:
            rank[i] += ['E']

np_rank = np.array(rank)
print(np_rank)
