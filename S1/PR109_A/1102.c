#include <stdio.h>


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    return;
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    swap(&n, &m);
    printf("%d %d\n", n, m);
    return 0;
}
