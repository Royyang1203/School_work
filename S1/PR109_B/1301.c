#include <stdio.h>


void specific_order(int *a, int *b, int *c, int *d, int order[4])
{
    int arr[4] = {*a, *b, *c, *d};
    for (int i = 0; i < 3; i ++)
        for (int j = 0; j < 3; j ++)
            if (arr[j] < arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
    *a = arr[order[0] - 1];
    *b = arr[order[1] - 1];
    *c = arr[order[2] - 1];
    *d = arr[order[3] - 1];
}

int main (void)
{
    int a, b, c, d;
    int arr[4];
    scanf("%d%d%d%d", &a, &b, &c, &d);
    for (int i = 0; i < 4; i ++)
        scanf("%d", &arr[i]);
    specific_order(&a, &b, &c, &d, arr);
    printf("%d%d%d%d", a, b, c, d);
    return 0;
}
