#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1000][1000];

int main()
{
    int i, j;
    int m = 0, max = -1, len;
    while (scanf("%[^\n]", &str[m]) != EOF) {
        fflush(stdin);
        len = strlen(str[m]);
        if (max < len)
            max = len;
        m ++;
    }

    for(i = 0; i < max; i ++) {
        for(j = m - 1; j >= 0; j --) {
            if (i < strlen(str[j]))
                printf("%c", str[j][i]);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
