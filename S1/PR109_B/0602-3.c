#include <stdio.h>


int out(int r, int c ,int n)
{
    return (r >= 0 && c >= 0 && r < n && c < n);
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    if (arr[0][0] == 1) {
        printf("No\n");
        return 0;
    }
    arr[0][0] = 2;
    for (int k = 0; k < n * n; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (arr[i][j] == 0 && (out(i + 1, j, n) && arr[i + 1][j] == 2 || out(i - 1, j, n) && arr[i - 1][j] == 2 || out(i, j + 1, n) && arr[i][j + 1] == 2 || out(i, j - 1, n) && arr[i][j - 1] == 2)) {
                    arr[i][j] = 2;
                }
            }
        }
        if (arr[n - 1][n - 1] == 2) {
            printf("Yes\n");
            return 0;
        }
    }

    printf("No\n");
    return 0;
}
