#include <stdio.h>
#include <math.h>


int main(void)
{
    unsigned long long p, q, s, x, k = 0;
    scanf("%lld%lld%lld", &p, &q, &s);
    unsigned long long n = p * q;
    x = s * s % n;
    for (int i = 7; i >= 0; i --) {
        x = x * x % n;
        k += (x % 2) * pow(2, i);
        printf("%lld", x % 2);
    }
    printf(" = %X", k);
    return 0;
}
