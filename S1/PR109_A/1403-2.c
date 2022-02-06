#include <stdio.h>
#include <string.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    char arr[100][50], *ptr[100];
    for (int i = 0; i < n; i ++) {
        scanf("%s", arr[i]);
        ptr[i] = arr[i];
    }
    printf("\n");
    for (int i = 0; i < n - 1; i ++)
        for (int j = 0; j < n - 1; j ++) {
            if (strcmp(arr[j], arr[j + 1]) > 0) {
                char *t = &ptr[j];
                &ptr[j] = &ptr[j + 1];
                &ptr[j + 1] = t;
            }
            if (strcmp(arr[j], arr[j + 1]) == 0 && strlen(arr[j]) > strlen(arr[j + 1])) {
                char *t = &ptr[j];
                &ptr[j] = &ptr[j + 1];
                &ptr[j + 1] = t;
            }
            for (int k = 0; k < n; k ++)
                printf("%s\n", ptr[k]);
            printf("%d\n", j);
        }
    for (int i = 0; i < n; i ++)
        printf("%s\n", ptr[i]);
    return 0;
}
