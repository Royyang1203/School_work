// Description

// 所有的因數

// 請寫一隻程式，讀入一個正整數，輸出整數的所有正因數。

// All factor

// Please write a program read in an integer and print out all its factor.

// Input
// 輸入只會有一個正整數

// Input consist an positive integer.

// Output
// 請說出所有的正因數，由小到大排列好。

// Print out all factors incremental ordering.

// Sample Input 1

// 24
// Sample Output 1

// 1 2 3 4 6 8 12 24
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            if (i < n)
                printf("%d ", i);
            else
                printf("%d", i);
    return 0;
}
