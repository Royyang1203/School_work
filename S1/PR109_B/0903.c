#include <stdio.h>

int bubbleSort(int *array, int n)
{
    int k = 0;
    int *t;
    for(int i = 0; i < n - 1; i ++)
        for (int j = 0; j < n - 1; j ++) {
            if (*array[j] < *array[j + 1]) {
                t = *array[j];
                *array[j] = *array[j + 1];
                *array[j + 1] = t;
                k ++;
            }

        }

    return k;
}


int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i ++)
        scanf("%d", &arr[i]);
    int k = bubbleSort(&arr, n);
    printf("%d", k);
    return 0;
}
