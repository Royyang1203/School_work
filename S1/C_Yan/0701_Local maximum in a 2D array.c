#include <stdio.h>

int main(void)
{
    int n, i, j;
    scanf("%d", &n);
    int arr1[n][n], arr2[n][n];
    for (i = 0; i < n; i ++)
        for (j = 0; j < n ; j ++)
            scanf("%d", &arr1[i][j]);
    for (i = 0; i < n; i ++)
        for (j = 0; j < n ; j ++) {
            scanf("%d", &arr2[i][j]);
            arr1[i][j] += arr2[i][j];
        }

    for(i = 0; i < n;i ++) {
        for (j = 0; j <n; j ++)
            if (j == n - 1)
                printf("%d", arr1[i][j]);
            else
                printf("%d ", arr1[i][j]);
        printf("\n");
    }
    return 0;
}
