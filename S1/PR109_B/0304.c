#include <stdio.h>

main()
{
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            if (j < a - i - 1)
                printf(" ");
            else
                if (j < a - 1)
                    printf("* ");
                else
                    printf("*");
        }
        if (i < a - 1)
            printf("\n");
    }
    return 0;
}
