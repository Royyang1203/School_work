#include <stdio.h>

int main(void)
{
    long long a, b, c, i, t;
    while (scanf("%lld%lld%lld", &a, &b, &c) != EOF) {
        if (a < b)
            t = b;
        else
            t = a;
        if (c > t)
            t = c;
        for (i = t; i >= 1; i--) {
            if(a % i == 0 && b % i == 0 && c % i == 0)
                break;
        }
        printf("%lld\n", i);
    }
    return 0;
}
