#include <stdio.h>

int main(void)
{
    int n;
    char m[21][21] = {0};
    for(int i = 1; i < 20; i ++) {
        fflush(stdin);
        for (int j = 1; j < 20; j ++)
            scanf("%c", &m[i][j]);
    }
    for (int i = 1; i < 20; i ++)
        for (int j = 1; j < 20; j ++) {
            //printf("%d %d\n", i, j);
            if (m[i][j] == 'O' || m[i][j] == 'X') {
                if (m[i][j] == 'O' && m[i + 1][j] == 'O' && m[i + 2][j] == 'O' && m[i + 3][j] == 'O' && m[i + 4][j] == 'O' ||
                    m[i][j] == 'O' && m[i][j + 1] == 'O' && m[i][j + 2] == 'O' && m[i][j + 3] == 'O' && m[i][j + 4] == 'O' ||
                    m[i][j] == 'O' && m[i + 1][j + 1] == 'O' && m[i + 2][j + 2] == 'O' && m[i + 3][j + 3] == 'O' && m[i + 4][j + 4] == 'O' ||
                    m[i][j] == 'O' && m[i + 1][j - 1] == 'O' && m[i + 2][j - 2] == 'O' && m[i + 3][j - 3] == 'O' && m[i + 4][j - 4] == 'O') {
                    printf("White");
                    return 0;
                    }
                else if (m[i][j] == 'X' && m[i + 1][j] == 'X' && m[i + 2][j] == 'X' && m[i + 3][j] == 'X' && m[i + 4][j] == 'X' ||
                        m[i][j] == 'X' && m[i][j + 1] == 'X' && m[i][j + 2] == 'X' && m[i][j + 3] == 'X' && m[i][j + 4] == 'X' ||
                        m[i][j] == 'X' && m[i + 1][j + 1] == 'X' && m[i + 2][j + 2] == 'X' && m[i + 3][j + 3] == 'X' && m[i + 4][j + 4] == 'X' ||
                        m[i][j] == 'X' && m[i + 1][j - 1] == 'X' && m[i + 2][j - 2] == 'X' && m[i + 3][j - 3] == 'X' && m[i + 4][j - 4] == 'X') {
                        printf("Black");
                        return 0;
                    }
            }
        }
    printf("No winner");
    return 0;
}
