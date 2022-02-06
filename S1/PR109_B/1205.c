#include <stdio.h>

int main(void)
{
    int n, m = 1;
    int a = 50, b = 50;
    int d[6] = {0, 1, 0, -1, 0, 1};
    while (scanf("%d", &n)) {
        if (n == 0) {
            printf("(%d,%d)", a, b);
            break;
        }
        else if (n == -1)
            m += 3;
        else if (n == -2)
            m += 1;
        else if (n == -3)
            m += 2;
        m %= 4;
        if (n > 0)
            for (int i = 0; i < n; i ++) {
                a += d[m];
                b += d[m + 1];
            }
        if (a > 100)
            a = 100;
        if (a < 0)
            a = 0;
        if (b > 100)
            b = 100;
        if (b < 0)
            b = 0;
    }
    return 0;
}
