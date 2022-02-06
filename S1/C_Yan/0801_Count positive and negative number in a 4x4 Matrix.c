#include <stdio.h>

int main(void)
{
    int arr[4][4];
    int ans[2] = {0};
    int i, j;
    for (i = 0; i < 4; i ++)
        for (j = 0; j < 4; j ++)
            scanf("%d", &arr[i][j]);
    for (i = 0; i < 4; i ++)
        for (j = 0; j < 4; j ++) {
            if (arr[i][j] < 0)
                ans[0] ++;
            else if (arr[i][j] > 0)
                ans[1] ++;
        }
    printf("%d\n%d", ans[0], ans[1]);
    return 0;
}
