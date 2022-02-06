#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, m;
    char arr[1000], c;
    while (scanf("%s", arr) != EOF) {
        m = 0;
        n = strlen(arr);
        c = arr[0];
        for (int i = 1; i <= n; i ++) {
            m ++;
            if (arr[i] != c) {
                if (m == 1)
                    printf("%c", c);
                else if (m == 2)
                    printf("%c%c", c, c);
                else
                    printf("%d%c", m, c);
                c = arr[i];
                m = 0;
            }

        }
        printf("\n");
    }
    return 0;
}
