#include <stdio.h>

int swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return 0;
}

int main(void)
{

    int n, q, a, b;
    while (scanf("%d", &n) != EOF) {
       static int k = 0;
        int arr[n];
        for (int i = 0; i < n; i ++) {
            scanf("%d", &arr[i]);
        }
        scanf("%d", &q);
        for (int i = 0; i < q; i ++) {
            scanf("%d%d", &a, &b);
            swap(&arr[a], &arr[b]);
            k ++;
        }
        printf("Grand total: %d\n", k);
        for (int i = 0; i < n; i ++) {
            printf("%d", arr[i]);
            if (i < n - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
