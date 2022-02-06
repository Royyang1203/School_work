#include <stdio.h>
#include <stdlib.h>

main ()
{
    int n, a, b, c;
    scanf("%d", &n);
    printf("1 \n");
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i + 1; j++) {
            a = 1;
            b = 1;
            c = 1;
            for (int k = 1; k <= i; k++)
                a *= k;
            for (int k = 1; k <= i - j + 1; k++)
                b *= k;
            for (int k = 1; k < j; k++)
                c *= k;
            printf("%d ", a / b / c);
        }
        printf("\n");
    }
    return 0;
}
