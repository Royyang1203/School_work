#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main()
{
    int a, i, j;
    scanf("%d", &a);
    for (i = 1; i <= a; i++)
    {
        for (j = 1; j <= i; j++)
        {
            if (j < i)
                printf("%d ", j);
            else
                printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}
