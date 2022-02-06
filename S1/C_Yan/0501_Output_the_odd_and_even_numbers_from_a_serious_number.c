#include <stdio.h>

main()
{
    int n, m, k, i;
    int a[100];
    int o[100];
    int e[100];
    int bo[100];
    int be[100];
    scanf("%d", &n);
    m = 0;
    k = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0) {
            be[m] = 0;
            e[m] = a[i];
            m++;
        }
        else {
            bo[k] = 1;
            o[k] = a[i];
            k++;
        }
    }
    for (i = 0; i < k; i++)
        if (bo[i] && i < k - 1)
            printf("%d ", o[i]);
        else
            printf("%d", o[i]);
    printf("\n");
    for (i = 0; i < m; i++)
        if (!be[i] && i < m - 1)
            printf("%d ", e[i]);
        else
            printf("%d", e[i]);
    return 0;
}
