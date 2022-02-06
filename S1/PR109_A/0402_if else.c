// Description

// 讀入兩個正整數 m、n ，判斷 m 是否為 n 的倍數。

// Read in two integer m and n, determine if m is multiple of n.

// Input
// 輸入會包含兩個整數，第一個是 m 第二個是 n ，兩個數之間用一個空白隔開。

// Input will be two integer m and n separate by a single space.

// Output
// 請參考範例輸出

// Please reference the sample out

// Sample Input 1

// 9 3
// Sample Output 1

// 9 is a multiple of 3.
// Sample Input 2

// 9 4
// Sample Output 2

// 9 is not a multiple of 4.
#include <stdio.h>
#include <stdlib.h>

main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    if (m % n == 0)
        printf("%d is a multiple of %d.", m, n);
    else
        printf("%d is not a multiple of %d.", m, n);
    return 0;
}