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
    for i in range(1, 6):
        print(getFibonacci(i), 'factorial->', getFactorial(getFibonacci(i)))


if __name__ == "__main__":
    main()
