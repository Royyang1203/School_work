#include <stdio.h>

int main(void)
{
    char arr[3][3];
    int b = 1, oo = 0, xx = 0, o = 0, x = 0;
    for (int i = 0; i < 3; i ++) {
        fflush(stdin);
        for (int j = 0; j < 3; j ++) {
            scanf("%c", &arr[i][j]);
            if (arr[i][j] == 'O') {
                oo ++;
            }
            else if (arr[i][j] == 'X') {
                xx ++;
            }
        }
    }
    if (arr[0][0] == 'O' && arr[0][1] == 'O' && arr[0][2] == 'O' ||
        arr[1][0] == 'O' && arr[1][1] == 'O' && arr[1][2] == 'O' ||
        arr[2][0] == 'O' && arr[2][1] == 'O' && arr[2][2] == 'O' ||
        arr[0][0] == 'O' && arr[1][0] == 'O' && arr[2][0] == 'O' ||
        arr[0][1] == 'O' && arr[1][1] == 'O' && arr[2][1] == 'O' ||
        arr[0][2] == 'O' && arr[1][2] == 'O' && arr[2][2] == 'O' ||
        arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O' ||
        arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O')
            o = 1;
    if (arr[0][0] == 'X' && arr[0][1] == 'X' && arr[0][2] == 'X' ||
        arr[1][0] == 'X' && arr[1][1] == 'X' && arr[1][2] == 'X' ||
        arr[2][0] == 'X' && arr[2][1] == 'X' && arr[2][2] == 'X' ||
        arr[0][0] == 'X' && arr[1][0] == 'X' && arr[2][0] == 'X' ||
        arr[0][1] == 'X' && arr[1][1] == 'X' && arr[2][1] == 'X' ||
        arr[0][2] == 'X' && arr[1][2] == 'X' && arr[2][2] == 'X' ||
        arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X' ||
        arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X')
            x = 1;
    printf("%d %d %d %d\n", oo, xx, o, x);
    if(o == 1 && x == 1) {
        printf("U");
        return 0;
    }
    if (oo - xx > 1) {
        printf("U");
        return 0;
    }
    if(xx - oo > 1) {
        printf("U");
        return 0;
    }
    if(o == 1 && x == 0) {
        if(oo < xx)
            printf("U");
        else
            printf("O");
        return 0;
    }
    if(x == 1 && o == 0) {
        if(oo > xx)
            printf("U");
        else
            printf("X");
        return 0;
    }
    printf("D");
    return 0;
}
