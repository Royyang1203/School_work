#include <stdio.h>

int main()
{
    int r, c, n, i, j, k, l;
    scanf("%d%d", &r, &c);
    int arr[r][c];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%d", &arr[i][j]);
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            //printf("%d\n", arr[i][j]);
            int b = 1;
            for (k = -1; k <= 1; k++)
                for (l = -1; l <= 1; l++) {
                    if (k * l != 0 || k == 0 && l == 0 || i + k < 0 ||
                        i + k >= r || j + l < 0 || j + l >= c)
                        continue;
                    if (arr[i + k][j + l] >= arr[i][j])
                        b = 0;
                }
            if (b)
                printf("%d\n", arr[i][j]);
        }
    return 0;
}
