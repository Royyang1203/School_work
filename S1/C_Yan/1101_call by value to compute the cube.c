// use the function:
// int cubeByValue( int n);

// input:
// 2
// output:
// 8

#include <stdio.h>

int cubeByValue(int n)
{
    int k = 1;
    int j;
    for (j = 0; j < 3; j++)
        k *= n;
    return k;
}

int main(void)
{
    int n, m;
    scanf("%d", &n);
    printf("%d", cubeByValue(n));

    return 0;
}
