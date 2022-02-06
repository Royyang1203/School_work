#include <stdio.h>
#include <stdlib.h>

void allocArray(int ***p, int m, int n) // v.2
{
    *p = (int **)malloc(m * sizeof(int *));

    int *temp = (int *)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; ++i)
    {
        (*p)[i] = (int *)(temp + n * i);
    }
}

// How to free a two dimensional array  allocated memory using int ** ptr?
void freeArray(int ***p, int m, int n)
{
}

int main()
{
    int **array, *a;
    int j, k;
    allocArray(&array, 5, 10);
    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            array[j][k] = j * 10 + k;
    for (j = 0; j < 5; j++)
        for (k = 0; k < 10; k++)
            printf("%p ", &(array[j][k]));
}