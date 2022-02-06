#include <stdio.h>

void transpose(int matrix[10][10], int row, int col)
{
    int arr[10][10];
    for (int i = 0; i < 10; i ++)
        for (int j = 0; j < 10; j ++) {
            if (i >= col || j >= row)
                arr[i][j] = 0;
            else
                arr[i][j] = matrix[j][i];
        }
    for (int i = 0; i < 10; i ++) {
        for (int j = 0; j < 10; j ++)
            matrix[i][j] = arr[i][j];
    }
    return;
}

int main(void)
{
    int arr[10][10] = {0};
    for (int i = 0; i < 4; i ++)
        scanf("%d", &arr[0][i]);
    transpose(arr, 1, 4);
    return 0;
}
