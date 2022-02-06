#include <stdio.h>
#include <stdlib.h>

main()
{
    int a, b, c, n;
    scanf("%d%d%d", &a, &b, &c);
    n = (a < b)? a : b;
    if (c < n)
        n = c;
    printf("%d", n);
    return 0;

}
