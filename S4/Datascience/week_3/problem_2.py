import math


def getPrimeList(n):

    res = [True for i in range(n)]
    res[0] = False
    res[1] = False

    for i in range(2, math.floor(n / 2)):
        if res[i]:
            for j in range(2 * i, n, i):
                res[j] = False
    return res


def main():

    list_char = []

    for i in range(14):
        list_char += [str(input())]

    prime_list = getPrimeList(14)

    print([list_char[i] for i in range(13) if prime_list[i]])


if __name__ == "__main__":
    main()
