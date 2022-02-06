#include <stdio.h>

int merger(int *a, int *b, int *c)
{
    for (int i = 0; i < 5; i ++)
        *(c + i) = *(a + i);
    for (int i = 0; i < 5; i ++)
        *(c + 5 + i) = *(b + i);
    for (int i = 0; i < 9; i ++)
        for (int j = 0; j < 9; j ++)
            if (*(c + j) > *(c + j + 1)) {
                int t = *(c + j);
                *(c + j) = *(c +j + 1);
                *(c + j + 1) = t;
            }
}

int main(void)
{
    int arr[5], arrb[5], arrc[10];
    for(int i = 0; i < 5; i ++)
        scanf("%d", &arr[i]);
    for(int i = 0; i < 5; i ++)
        scanf("%d", &arrb[i]);
    merger(&arr, &arrb, &arrc);
    for(int i = 0; i < 10; i ++)
        printf("%d ", arrc[i]);
    return 0;
}
