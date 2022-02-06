#include <stdio.h>
int main()
{
    int a,b,c,x,y;
    scanf("%d%d%d",&a,&b,&c);
    int arr[a][b];
    for (int i = 0; i < a; i ++)
        for (int j = 0; j < b; j ++)
            arr[i][j] = NULL;
    for (int i = 0; i < c; i ++) {
        scanf("%d%d", &x, &y);
        scanf("%d", &arr[x][y]);
    }
    for (int i = 0; i < a; i ++) {
        for (int j = 0; j < b; j ++) {
             printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
