#include <stdio.h>
#include <stdlib.h>

main()
{
    int i;
    scanf("%d", &i);
    int t = i / 1000;
    i %= 1000;
    int h = i / 100;
    i %= 100;
    int d = i / 10;
    i %= 10;
    printf("%d%d%d%d", i, d, h, t);
    return 0;
}
