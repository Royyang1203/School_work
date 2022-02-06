// Description

// 請完成樣板中的三種排序函數，泡沫排序、選擇排序、插入排序。

// Please finish the three sorting function in template, bubble sort, selection sort and insertion sort.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void bubbleSort(int *array, int n)
{
}
void selectionSort(int *array, int n)
{
}
void insertionSort(int *array, int n)
{
}

int main()
{
    int array[SIZE];
    int j, k;
    srand(time(NULL));
    for (j = 0; j < SIZE; j++)
        array[j] = rand();

    for (j = 0; j < SIZE; j++)
        printf("%d ", array[j]);
    printf("\n");

    bubbleSort(array, SIZE);

    for (j = 0; j < SIZE; j++)
        printf("%d ", array[j]);
    printf("\n");

    for (j = 0; j < SIZE; j++)
        array[j] = rand();

    for (j = 0; j < SIZE; j++)
        printf("%d ", array[j]);
    printf("\n");

    insertionSort(array, SIZE);

    for (j = 0; j < SIZE; j++)
        printf("%d ", array[j]);
    printf("\n");

    for (j = 0; j < SIZE; j++)
        array[j] = rand();

    for (j = 0; j < SIZE; j++)
        printf("%d ", array[j]);
    printf("\n");

    selectionSort(array, SIZE);

    for (j = 0; j < SIZE; j++)
        printf("%d ", array[j]);
    printf("\n");
}
