# Using loop get factorial number from 5 first fibonacci number if first number is 1 and second number is 2.

# Fibonacci example x1=1, x2=2, x3=x1+x2=3, x4=x2+x3=5

# input 1
# 4

# output 1

# 1  factorial -> 1
# 2  factorial -> 2
# 3  factorial -> 6
# 5  factorial -> 120

# input 2
# 6

# output 2
# 1 factorial-> 1
# 2 factorial-> 2
# 3 factorial-> 6
# 5 factorial-> 120
# 8 factorial-> 40320
# 13 factorial-> 6227020800

def getFactorial(n):
    if n == 1:
        return 1
    else:
        return n * getFactorial(n - 1)


def getFibonacci(n):
    if n == 1:
        return 1
    elif n == 2:
        return 2
    else:
        return getFibonacci(n - 1) + getFibonacci(n - 2)


def main():
    a = int(input())
    for i in range(1, a + 1):
        print(getFibonacci(i), 'factorial->', getFactorial(getFibonacci(i)))


if __name__ == "__main__":
    main()
