#include <stdio.h>

int main(void)
{
    int n, m, b;
    while (scanf("%d%d", &n, &m) && n != 0 && m != 0) {
        int k = b = 0;
        do {
            if (n % 10 + m % 10 + b >= 10) {
                k ++;
                b = 1;
            }
            n /= 10;
            m /= 10;
        } while (m || n);
        printf("%d\n", k);
    }
    return 0;
}
