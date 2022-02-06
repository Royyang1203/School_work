#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
    int n, m, k, b;
    scanf("%d\n", &n);
    char arr[1300], c;
    for (int i = 0; i < n; i ++) {
        gets(arr);
        k = b = 0;
        m = strlen(arr);
        for (int j = 0; j < m; j ++) {

            if (isgraph(arr[j]) && !b) {
                b = 1;
                k ++;
            }
            if (!isgraph(arr[j])) {
                b = 0;

            }
        }
        printf("%d\n", k);
    }
    return 0;
}
