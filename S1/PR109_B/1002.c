#include <stdio.h>

int stop(int arr[5][5])
{
    return (arr[0][0] == -1 && arr[0][1] == -1 && arr[0][2] == -1 && arr[0][3] == -1 && arr[0][4] == -1 ||
             arr[1][0] == -1 && arr[1][1] == -1 && arr[1][2] == -1 && arr[1][3] == -1 && arr[1][4] == -1 ||
             arr[2][0] == -1 && arr[2][1] == -1 && arr[2][2] == -1 && arr[2][3] == -1 && arr[2][4] == -1 ||
             arr[3][0] == -1 && arr[3][1] == -1 && arr[3][2] == -1 && arr[3][3] == -1 && arr[3][4] == -1 ||
             arr[4][0] == -1 && arr[4][1] == -1 && arr[4][2] == -1 && arr[4][3] == -1 && arr[4][4] == -1 ||

             arr[0][0] == -1 && arr[1][0] == -1 && arr[2][0] == -1 && arr[3][0] == -1 && arr[4][0] == -1 ||
             arr[0][1] == -1 && arr[1][1] == -1 && arr[2][1] == -1 && arr[3][1] == -1 && arr[4][1] == -1 ||
             arr[0][2] == -1 && arr[1][2] == -1 && arr[2][2] == -1 && arr[3][2] == -1 && arr[4][2] == -1 ||
             arr[0][3] == -1 && arr[1][3] == -1 && arr[2][3] == -1 && arr[3][3] == -1 && arr[4][3] == -1 ||
             arr[0][4] == -1 && arr[1][4] == -1 && arr[2][4] == -1 && arr[3][4] == -1 && arr[4][4] == -1 ||

             arr[0][0] == -1 && arr[1][1] == -1 && arr[2][2] == -1 && arr[3][3] == -1 && arr[4][4] == -1 ||
             arr[0][4] == -1 && arr[1][3] == -1 && arr[2][2] == -1 && arr[3][1] == -1 && arr[4][0] == -1);
}

int main(void)
{
    int n, m, continu, continu2;
    scanf("%d", &n);
    int arr[n][5][5], ans[25], score[30] = {0};
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < 5; j ++)
            for (int k = 0; k < 5; k ++)
                scanf("%d", &arr[i][j][k]);
    for (int i = 0; i < 25; i ++)
        scanf("%d", &ans[i]);
    for (int i = 0; i < n; i ++)  {
        continu2 = 0;
        for (int j = 0; j < 25; j ++) {
            if (continu2)
                continue;
            if (stop(arr[i]))
                continu2 = 1;
            continu = 0;
            for (int k = 0; k < 5; k ++) {
                if (continu)
                    continue;
                for (int l = 0; l < 5; l ++) {
                    if (continu)
                        continue;
                    if (arr[i][k][l] == ans[j]) {
                        continu = 1;
                        arr[i][k][l] = -1;
                        score[i] ++;
                    }
                }
            }
        }
    }
    int p[25][32] = {0}, q;
    for (int i = 1; i < 25; i ++) {
        q = 1;
        for (int j = 0; j < n; j ++)
            if (score[j] - 1 == i) {
                p[i][0] ++;
                p[i][q] = j;
                q ++;
            }
    }
    for (int i = 1; i < 25 && p[i]; i ++) {
        if (p[i][0] != 0)
        printf("%d:", i);
        for (int j = 0; j < p[i][0]; j ++)
            printf(" %d", p[i][j + 1] + 1);
        if (p[i][0] != 0)
            printf("\n");
    }
    return 0;
}
