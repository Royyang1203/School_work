#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main()
{
    int a, b, c, d, t;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (b < a){
        t = b;
        b = a;
        a = t;
    }
    if (d < c){
        t = d;
        d = c;
        c = t;
    }
    if (b > c && d > a)
        printf("overlay");
    else
        printf("no overlay");
    return 0;
}
