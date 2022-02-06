#include <stdio.h>

int main(void)
{
    int arr[15][5] = {0}, n, m;
    scanf("%d", &n);
    char c;
    for(int i = 0; i < n; i ++) {
        fflush(stdin);
        scanf("%c", &c);
        scanf("%d", &m);
        printf("%c %d\n", c, m);
        if (c == 'S')
            arr[m][4] = 1;
        if (c == 'H')
            arr[m][3] = 1;
        if (c == 'D')
            arr[m][2] = 1;
        if (c == 'C')
            arr[m][1] = 1;
    }
    for(int i = 0; i < 2; i ++) {
        fflush(stdin);
        scanf("%c", &c);
        scanf("%d", &m);
        printf("%c %d\n", c, m);
        if (c == 'S')
            arr[m][4] = 1;
        if (c == 'H')
            arr[m][3] = 1;
        if (c == 'D')
            arr[m][2] = 1;
        if (c == 'C')
            arr[m][1] = 1;
    }
    return 0;
}

