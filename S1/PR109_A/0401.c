#include <stdio.h>
#include <stdlib.h>

main()
{
    int a;
    scanf("%d", &a);
    if (a % 2 == 0)
        printf("even");
    else
        printf("odd");
    return 0;
}
