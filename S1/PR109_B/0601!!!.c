#include <stdio.h>

int main(void)
{
    int row, col, val;
    scanf("%d%d%d", &row, &col, &val);
    int n[val][3];
    for (int i = 0; i < val; i++)
        for (int j = 0; j < 3; j++)
            scanf("%d", &n[i][j]);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
            for (int k = 0; k < val; k++) {
                if (n[k][0] == i && n[k][1] == j) {
                    printf("%d ", n[k][2]);
                    break;
                }
                else if (k == val - 1)
                    printf("%d ", 0);
            }
        if (i < row - 1)
            printf("\n");
    }
    return 0;
}
