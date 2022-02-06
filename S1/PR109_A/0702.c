#include <stdio.h>

int main(void)
{
    int arr[10];
    for (int i = 0; i < 10; i ++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < 9; i ++)
        for (int j = 0; j < 9; j ++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
    for (int i = 0; i < 10; i ++)
        if (i == 9)
            printf("%d", arr[i]);
        else
            printf("%d ", arr[i]);
    return 0;
}
