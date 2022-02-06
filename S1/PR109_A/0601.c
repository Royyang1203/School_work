#include <stdio.h>

int main(void)
{
    int max, min;
    int a;
    scanf("%d", &a);
    max = min = a;
    while (scanf("%d", &a) != EOF) {
        if (a > max)
            max = a;
        else if (a < min)
            min = a;
    }
    printf("%d %d", max, min);
    return 0;
}
