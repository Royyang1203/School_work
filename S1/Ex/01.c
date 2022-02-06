#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, m;
    char arr[1000];
    while (scanf("%d", &n) && n != 0) {
        scanf("%s", &arr);
        m = strlen(arr);
        for (int i = 0; i < n; i ++)
            for (int j = 0; j < m / n / 2; j ++) {
                char t = arr[m / n * i + j];
                arr[m / n * i + j] = arr[m / n * i + m / n - j - 1];
                arr[m / n * i + m / n - j - 1] = t;
            }
        printf("%s\n", arr);
    }
    return 0;
}
