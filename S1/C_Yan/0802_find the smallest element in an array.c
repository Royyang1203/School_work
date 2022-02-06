#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int ans[2] = {0};
    int i, j;
    for (i = 0; i < n; i ++)
        scanf("%d", &arr[i]);

    int t = arr[0];
    for (i = 1; i < n; i ++)
            if (t > arr[i])
                t = arr[i];

    printf("%d", t);
    return 0;
}
