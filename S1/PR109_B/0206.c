#include <stdio.h>

main()
{
    float a, b, c, d, e, n;
    scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
    if (a < b)
        n = a;
    else
        n = b;
    if (c < n)
        n = c;
    if (d < n)
        n = d;
    if (e < n)
        n = e;
    if (n == a)
        printf("1");
    if (n == b)
        printf("2");
    if (n == c)
        printf("3");
    if (n == d)
        printf("4");
    if (n == e)
        printf("5");
    return 0;
}

