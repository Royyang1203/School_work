#include <stdio.h>
#include <stdlib.h>

void orderByValue(int *a, int *b, int *c)
{
    int t;

    if (*b > *a) {
        t = *a;
        *a = *b;
        *b = t;
    }
    if (*c > *b) {
        t = *c;
        *c = *b;
        *b = t;
    }
    if (*b > *a) {
        t = *a;
        *a = *b;
        *b = t;
    }
    return;
}

int main(void)
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int *pa, *pb, *pc;
    pa = &a;
    pb = &b;
    pc = &c;
    printf("%p\n", pa);
    orderByValue(&a, &b, &c);
    printf("%d %d %d", *pa, *pb, *pc);

    return 0;
}
