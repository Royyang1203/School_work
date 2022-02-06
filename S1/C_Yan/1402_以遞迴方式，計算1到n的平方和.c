// 內容：

// 以遞迴方式，計算1到n的平方和，0<n<=100
// 輸入說明：

// 一個數值 n
// 輸出說明：

// 輸出 1到n的平方和
// 範例輸入：

// 10
// 範例輸出：

// 385

#include <stdio.h>

int fun(int n)
{
    if (n == 1)
        return 1;
    return (n * n + fun(n - 1));
}
int main(void)
{
    int n, m;
    scanf("%d", &n);
    printf("%d", fun(n));
    return 0;
}