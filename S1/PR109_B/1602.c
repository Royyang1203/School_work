#include <stdio.h>

int main(void)
{
    int n, m, o = 0, num[4], k = -1, w;
    char arr[10][300];
    for (int i = 0; i < 10; i ++)
        scanf("%s", &arr[i]);
    if(strlen(arr[0]) == 64)
        o = 8;
    else
        o = 16;
    scanf("%d,%d", &n, &m);
    while (n > 0) {
        k ++;
        num[k] = n % 10;
        n /= 10;
    }
    for(int i = 0; i < o; i ++)
        for(int j = 0; j < m; j ++) {
            w = 0;
            while (k - w >= 0) {
                for (int l = 0; l < o; l ++)
                    for (int p = 0; p < m; p ++)
                        if(arr[num[k - w]][i * o + l] == '1')
                            printf("*");
                        else
                            printf("_");
                if(k - w > 0)
                    printf("___");
                w ++;
            }
            printf("\n");
        }
    return 0;
}
