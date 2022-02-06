#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    char arr[n][55];
    for (int i = 0; i < n; i ++) {
        scanf("%s", &arr[i]);
    }
    for (int i = 0; i < n - 1; i ++)
        for (int j = 0; j < n - 1; j ++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char t[55];
                strcpy(t, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], t);
            }
        }
    for (int i = 0; i < n; i ++)
        printf("%s\n", arr[i]);
    return 0;
}
