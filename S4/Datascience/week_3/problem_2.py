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

    list_char = ['AA', 'BB', 'CC', 'DD', 'EE',
                 'FF', 'GG', 'HH', 'II', 'JJ', 'KK']
    prime_list = getPrimeList(12)

    print([list_char[i] for i in range(11) if prime_list[i]])


if __name__ == "__main__":
    main()
