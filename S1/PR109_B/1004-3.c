#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[1000][1000];
    int n;
    int col = 0, row = -1;
    while (scanf("%[^\n]%n", &arr[col], &n) != EOF) {
        fflush(stdin);
        if (n > row)
            row = n;
        col ++;
    }
    for (int i = 0; i < row; i ++) {
        for (int j = col - 1; j >= 0; j --){
            if (i < strlen(arr[j]))
                printf("%c", arr[j][i]);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
