#include <stdio.h>

int between(int *a, int *b)
{
    int s = 0;
    while (a < b) {
        s += *a;
        a ++;
    }
    return s;
}

int main(void)
{
    int arr[5];
    for (int i = 0; i < 5; i ++)
        scanf("%d", &arr[i]);
        printf("%p %p\n", &arr[1], &arr[4]);
    //printf("%d ", arr[3]);

    printf("%d", between(&arr[1], &arr[4]));

    return 0;
}
