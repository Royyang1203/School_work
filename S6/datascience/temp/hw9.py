
import numpy as np

first_exam = []
while True:
    input_str = input()
    if input_str == "-1":
        break
    first_exam.extend([int(x) for x in input_str.split()])
first_exam = np.array(first_exam).reshape((-1, 3))

second_exam = []
while True:
    input_str = input()
    if input_str == "-1":
        break
    second_exam.extend([int(x) for x in input_str.split()])
second_exam = np.array(second_exam).reshape((-1, 3))

final_score = (first_exam + second_exam)/2
final_score[:, 0] += 10
final_score[final_score < 60] = -1
final_score[final_score > 100] = 100

print(first_exam)
print(second_exam)
print(final_score)
