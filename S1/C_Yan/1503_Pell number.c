// 內容：
// 佩爾數(Pell)由以上的遞推關係定義：
// 最初的幾個佩爾數是 0, 1, 2, 5, 12, 29, 70, 169, 408, 985, 2378……
// 給定一個正整數 k ，請問佩爾數的第 k 項是多少?
// 注意，在本題中，第0項是0 ，第1項是1，依此類推。
// 請寫一個程式，利用遞迴的方式解題。main function大致上如下：
// #include <stdio.h>
// int main()
// {
// int x;

// scanf("%d", &x);
// printf("%d\n",Pell(x));

// return 0;
// }
// 請寫出函式 "Pell" 。
// 輸入說明：
// 每筆測資是一個正整數 k

// 輸出說明：
// 請針對一筆測資 k ，輸出佩爾數的第 k 項。
// 範例輸入：
// 9
// 14
// 1
// 範例輸出：

// 985
// 80782
// 1

#include <stdio.h>

int Pell(int n)
{
    if (n == 1)
        return 1;
    else if (n == 0)
        return 0;
    else
        return 2 * Pell(n - 1) + Pell(n - 2);
}

int main()
{
    int x;
    while (scanf("%d", &x) != EOF)
        printf("%d\n", Pell(x));

    return 0;
}