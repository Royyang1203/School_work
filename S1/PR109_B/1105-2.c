#include <stdio.h>


int carr(int a, int b)
{
    int car = 0, count = 0;
    while (a != 0 && b!= 0 && car != 0) {
        car = (car + a % 10 + b % 10) / 10;
        a /= 10;
        b /= 10;
        if (car > 0)
            count++;
    }
    return count;
}
int main(void)
{
    int a, b;
    while (scanf("%d%d", &a, &b)) {
        if (a == 0 && b == 0)
            break;
        printf("%d", carr(a, b));
    }

    return 0;
}
