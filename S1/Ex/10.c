#include <stdio.h>

int main(void)
{
    int l, n, m, index1, index2, q;
    scanf("%d%d%d", &l, &n, &m);
    int key[n];
    char arr[2][n];
    for(int i = 0; i < n; i ++)
        scanf("%d", &key[i]);
    for(int i = 0; i < l; i ++) {
        scanf("%s", &arr[0]);
        //for (int k = 0; k < n; k ++)
        //    printf("%c ", arr[0][i][k]);
        index1 = 1;
        index2 = 0;
        for (int k = 0; k < m; k ++) {
            //printf("!!%d %d!@", k, index1);
            for (int j = 0; j < n; j ++) {
                arr[index1][key[j] - 1] = arr[index2][j];
            }
            index1 = (index1 == 1) ? 0 : 1;
            index2 = (index2 == 1) ? 0 : 1;
        }
        if (m % 2)
            q = 1;
        else
            q = 0;
        for (int k = 0; k < n; k ++)
            printf("%c", arr[q][k]);
        printf("\n");
    }
    return 0;
}
