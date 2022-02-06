#include <stdio.h>
#include <string.h>
int main(void)
{
    int n, m;
    char arr[10000];
    while (scanf("%s", arr) != EOF) {
        n = strlen(arr);
        char *ptr = (arr + n - 1);
        for (int i = 1; i <= n / 2; i ++) {
            int b = 1;
            for (int j = 0; j < i && b; j ++) {
                if (*(ptr - j) != *(ptr - i - j))
                    b = 0;
            }
            if(b)
                m = i;
        }
        printf("%d\n", m);
    }
    return 0;
}
