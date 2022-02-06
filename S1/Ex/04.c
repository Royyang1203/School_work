#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    int n, m;
    char arr[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        scanf("%s", arr);
        m = strlen(arr);
        for (int j = 1; j < m; j ++) {
            printf("%d", abs(arr[j] - arr[j - 1]) % 10);
        }
        printf("\n");
    }
    return 0;
}
