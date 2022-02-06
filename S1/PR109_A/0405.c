#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a + b <= c)
        printf("can not construct");
    else if (a * a + b * b == c * c)
        printf("right triangle");
    else if (a * a + b * b > c * c)
        printf("acute triangle");
    else if (a * a + b * b < c * c)
        printf("obtuse triangle");
    return 0;
}

