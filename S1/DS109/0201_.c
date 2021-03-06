// Description

// 請完成函數 allocArray

// 該函數會配置一個整數的二維陣列，大小是 m * n

// 然後用 p 指向配置好的二維陣列

// Please finish the function allocArray

// This function will allocate a 2-D array with size m * n, then point the array using pointer p.

// #include
// #include
// void allocArray(int ***p, int m, int n)
// {
// }

// int main()
// {
//     int **array, *a;
//     int j, k;
//     allocArray(&array, 5, 10);
//     for (j = 0; j < 5; j++)
//         for (k = 0; k < 10; k++)
//             array[j][k] = j * 10 + k;
//     for (j = 0; j < 5; j++)
//         for (k = 0; k < 10; k++)
//             printf("%p ", &(array[j][k]));
// }

// 如果你能成功的配置一個二維陣列，你就能得到80分

// 如果你能配置出連續的空間，你就可以得到100分

// You will get 80 point if you can successfully allocate a 2-D array.

// You will get 100 point if you can allocateconsecutive memory for this 2-D array.

#include <stdio.h>
#include <stdlib.h>
// void allocArray(int ***p, int m, int n)
// {
//     int i, j;

//     *p = (int **)malloc(m * sizeof(int *));
//     for (int i = 0; i < m; ++i)
//     {
//         (*p)[i] = (int *)malloc(n * sizeof(int));
//     }
// }

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