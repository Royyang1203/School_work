// Description

// 請寫一個程式做質因數分解

// Please write a program for prime factorization.

// Input
// 輸入會包含很多筆測試資料，每一筆測試資料就是一個正整數，當輸入為 0 的時候結束測試。

// Input consist several test case. Every test case is just a integer. Input ended with 0.

// Output
// 對每一筆測試資料輸出一行結果，格式請參考範例輸出。

// Please reference the sample output.

// Sample Input 1

// 12
// 81
// 0
// Sample Output 1

// 12 = 2 * 2 * 3
// 81 = 3 * 3 * 3 * 3
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        if (n == 1)
        {
            printf("%d = %d\n", n, n);
            continue;
        }
        printf("%d =", n);
        for (int i = 2; i <= n; i++)
            while (n % i == 0)
            {
                if (n != i)
                    printf(" %d *", i);
                else
                    printf(" %d\n", i);
                n /= i;
            }
    }
    return 0;
}
