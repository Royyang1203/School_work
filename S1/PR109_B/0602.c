#include <stdio.h>

int out(int r, int c ,int n)
{
    return (r >= 0 && c >= 0 && r < n && c < n);
}

int maze(int *n, int arr[*n][*n], int curr, int curc)
{
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    if (curr == *n - 1 && curc == *n - 1)
        return 1;
    for (int j = 0; j < 4; j++) {
        int nexr = curr + dr[j];
        int nexc = curc + dc[j];
        if (out(nexr, nexc, *n) && arr[nexr][nexc] == 0) {
            arr[nexr][nexc] = 1;
            if (maze(n, arr, nexr, nexc))
                return 1;
            arr[nexr][nexc] = 0;
        }
    }
    return 0;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    int curr = 0;
    int curc = 0;
    if (arr[curr][curc] == 1) {
        printf("No\n");
        return 0;
    }
    arr[curr][curc] = 2;
    if (maze(&n, arr, curr, curc))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
