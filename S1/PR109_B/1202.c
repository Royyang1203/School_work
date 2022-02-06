#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    int arra[m];
    for (int i = 0; i < m; i ++) {
        scanf("%d", &arra[i]);
    }
    int arr[n][m + 1];
    for (int i = 0; i < n; i ++)
        for (int j = 0; j <= m; j ++) {
            scanf("%d", &arr[i][j]);
        }
    for (int i = 0; i < n; i ++) {
            int d;
        for (int j = m; j > 0; j --) {
            if (j == m)
                d = arr[i][j];
            else
                d = abs(arr[i][j + 1] - arr[i][j]);
            if (d >= arr[i][j - 1] != arra[j - 1]){
                //printf("%d %d!!!\n", i, j);
                break;
            }
            if (j == 1) {
                for (int k = 0; k <= m; k ++)
                    printf("%d ", arr[i][k]);
                return 0;
            }

        }
    }
    return 0;
}
