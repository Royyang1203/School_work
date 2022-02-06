// Description

// 請寫一個程式，判斷輸入的數是不是質數

// Please write a program to determine if a number is prime or not.

// Input
// 輸入會包含很多筆測試資料，每一筆測試資料就是一個正整數，當輸入為 0 的時候結束測試。

// Input consist several test case. Every test case is just a integer. Input ended with 0.

// Output
// 對每一筆測試資料輸出一行結果，如果是質數就輸出 "prime" ，如果不是質數就輸出 "not a prime"

// For every test case output "prime" if the input is a prime number, output "not a prime" if not.

// Sample Input 1

// 2
// 3
// 4
// 5
// 0
// Sample Output 1

// prime
// prime
// not a prime
// prime
#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n;
    bool j;
    while (scanf("%d", &n) != EOF && n != 0)
    {
        j = 1;
        if (n == 1)
            j = 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0)
                j = 0;
        if (j)
            printf("prime\n");
        else
            printf("not a prime\n");
    }
    return 0;
}