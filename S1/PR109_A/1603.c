#include <stdio.h>

int stop(int arr[5][5])
{
    if (arr[0][0] == '#' && arr[0][1] == '#' && arr[0][2] == '#' && arr[0][3] == '#' && arr[0][4] == '#' ||
        arr[1][0] == '#' && arr[1][1] == '#' && arr[1][2] == '#' && arr[1][3] == '#' && arr[1][4] == '#' ||
        arr[2][0] == '#' && arr[2][1] == '#' && arr[2][2] == '#' && arr[2][3] == '#' && arr[2][4] == '#' ||
        arr[3][0] == '#' && arr[3][1] == '#' && arr[3][2] == '#' && arr[3][3] == '#' && arr[3][4] == '#' ||
        arr[4][0] == '#' && arr[4][1] == '#' && arr[4][2] == '#' && arr[4][3] == '#' && arr[4][4] == '#' ||
        arr[0][0] == '#' && arr[1][0] == '#' && arr[2][0] == '#' && arr[3][0] == '#' && arr[4][0] == '#' ||
        arr[0][1] == '#' && arr[1][1] == '#' && arr[2][1] == '#' && arr[3][1] == '#' && arr[4][1] == '#' ||
        arr[0][2] == '#' && arr[1][2] == '#' && arr[2][2] == '#' && arr[3][2] == '#' && arr[4][2] == '#' ||
        arr[0][3] == '#' && arr[1][3] == '#' && arr[2][3] == '#' && arr[3][3] == '#' && arr[4][3] == '#' ||
        arr[0][4] == '#' && arr[1][4] == '#' && arr[2][4] == '#' && arr[3][4] == '#' && arr[4][4] == '#' ||
        arr[0][0] == '#' && arr[1][1] == '#' && arr[2][2] == '#' && arr[3][3] == '#' && arr[4][4] == '#' ||
        arr[0][4] == '#' && arr[1][3] == '#' && arr[2][2] == '#' && arr[3][1] == '#' && arr[4][0] == '#')
        return 1;
    else
        return 0;
}


int main(void)
{
    int n, m, num[2][25] = {0}, ans[25][32], breaker;
    scanf("%d", &n);
    int arr[n][5][5];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < 5; j ++)
            for (int k = 0; k < 5; k ++)
                scanf("%d", &arr[i][j][k]);
    for (int i = 0; i < 25; i ++) {
        scanf("%d", &num[0][i]);
    }
    for (int i = 0; i < n; i ++) {
        breaker = 1;
        for (int j = 0; j < 25 && breaker; j ++)
            for (int k = 0; k < 5 && breaker; k ++)
                for (int l = 0; l < 5 && breaker; l ++) {
                    if (num[0][j] == arr[i][k][l]) {
                        arr[i][k][l] = '#';
                        if (stop(arr[i])) {
                            breaker = 0;
                            ans[j][num[1][j]] = i + 1;
                            num[1][j] ++;
                        }
                    }
                }
    }
    for (int i = 0; i < 25; i ++) {
        if (num[1][i] > 0) {
            for (int j = num[1][i] - 1; j > 0; j --)
                for (int k = 0; k < j; k ++)
                    if (ans[i][k] > ans[i][k + 1]) {
                        int t = ans[i][k];
                        ans[i][k] = ans[i][k + 1];
                        ans[i][k + 1] = t;
                    }
            printf("%d:", i + 1);
            for (int j = 0; j < num[1][i]; j ++)
                printf(" %d", ans[i][j]);
            printf("\n");
        }

    }
    return 0;
}
