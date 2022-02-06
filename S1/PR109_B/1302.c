#include <stdio.h>

int main (void)
{
    int n, a, b;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%d%d", &a, &b);
        b += 30;
        if (b / 60) {
            b %= 60;
            a += 1;
        }
        if (a == 24)
            a = 0;
        printf("%d %d\n", a, b);
    }
    return 0;
}
