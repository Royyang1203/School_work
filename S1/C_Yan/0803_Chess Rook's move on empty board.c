#include <stdio.h>

int main(void)
{
    int n, m, i, j;
    scanf("%d%d", &n, &m);
    int arr[8][8];
    for (i = 0; i < 8; i ++) {
        for (j = 0; j < 8; j ++) {
            if (n == i + 1 && m == j + 1)
                printf("%c", 'R');
            else if (n == i + 1 || m == j + 1)
                printf("%c", 'X');
            else
                printf("%c", 'E');
            if(j != 7)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
