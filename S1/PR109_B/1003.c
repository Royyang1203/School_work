#include <stdio.h>


void swap(int **a, int **b)
{

    printf("!%p %p\n", *a, *b);
    int *pa, *pb;
    pa = *a;
    printf("$$%d %d\n", *pa, **a);
    printf("!%p %p\n", a, b);

    long long t = *a;
    *a = *b;
    *b = t;
    return;

}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%p %p\n", &n, &m);
    int *a, *b;
    a = &n;
    b = &m;
    printf("##%p %p\n", a, b);
    swap(&a, &b);
    printf("%d %d\n", n, m);
    printf("%p %p\n", &n, &m);
    printf("##%p %p\n", a, b);
    return 0;
}
