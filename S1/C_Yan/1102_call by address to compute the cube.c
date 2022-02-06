// use void cubeByReference( int *nPtr)
// to call by address and compute the cube
// input:
// 2
// output:
// 8

#include <stdio.h>

void cubeByReference(int *nPtr)
{
    int k = *nPtr;
    int j;
    for (j = 0; j < 2; j++)
        *nPtr *= k;
    return;
}

int main(void)
{
    int n, m;
    scanf("%d", &n);
    cubeByReference(&n);
    printf("%d", n);

    return 0;
}