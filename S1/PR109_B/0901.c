#include <stdio.h>

int maxElementIndex(int *array, int n)
{
    int m = 0;
    for (int i = 0; i < n; i ++) {
        if (array[i] >= array[m])
            m = i;
    }
    return m;
}

int main(void)
{
    int arr[1000];
    int i = 0;
    while (scanf("%d", &arr[i]) != EOF)
        i ++;
    printf("%d\n", i);
    printf("%d", maxElementIndex(&arr, i));
    return 0;
}
