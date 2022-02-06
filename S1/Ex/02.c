#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    char arr[n][n];
    scanf("%s", arr);
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            if (i == j)
                printf("%c", arr[i][j]);
    return 0;
}
