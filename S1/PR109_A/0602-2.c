#include <stdio.h>

int main(void)
{
    int a, b, c, i;
    while (scanf("%d%d%d", &a, &b, &c) != EOF) {
        int t = a > b ? a : b;
        t = t > c ? t : c;
        for (i = t; i >= 1; i--) {
            if(a % i == 0 && b % i == 0 && c % i == 0)
                break;
        }
        printf("%d\n", i);
    }
    return 0;
}
