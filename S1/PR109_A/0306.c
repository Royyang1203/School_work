#include <stdio.h>
#include <stdlib.h>

main()
{
    int a;
    scanf("%d", &a);
    if (a % 2 == 0)
        printf("%d", a);
    else
        printf("%d", a - 1);
    return 0;
}
