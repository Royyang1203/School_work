#include <stdio.h>



int elementAt(int *pointer, int n)
{
    return *(pointer + n - 1);
}

int main(void)
{
    int arr[10];
    for (int i = 0; i < 10; i ++)
        scanf("%d", &arr[i]);
    printf("%d ", arr[3]);

    printf("%d", elementAt(&arr[3], 3));
    return 0;
}
