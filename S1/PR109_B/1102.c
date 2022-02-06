#include<stdio.h>

int main(void)
{
    int nr, nc;
    scanf("%d%d", &nr, &nc);
    if (nr <= 0 ||nc <= 0) {
        printf("No result\n");
        return 0;
    }
    int arr[nr][nc];
    for (int i = 0; i < nr; i ++)
        for (int j = 0; j < nc; j ++)
            scanf("%d", &arr[i][j]);
    int mr, mc;
    scanf("%d%d", &mr, &mc);
    if (mr <= 0 ||mc <= 0) {
        printf("No result\n");
        return 0;
    }
    int arre[mr][mc];
    for (int i = 0; i < mr; i ++)
        for (int j = 0; j < mc; j ++)
            scanf("%d", &arre[i][j]);
    if (nc != mr) {
        printf("No result\n");
        return 0;
    }
    for (int i = 0; i < nr; i ++) {
        for (int j = 0; j < mc; j ++) {
            int sum = 0;
            for (int k = 0; k < nc; k ++) {
                sum += arr[i][k] * arre[k][j];
            }
            printf("%d ", sum);
        }
        printf("\n");
    }

    return 0;
}
