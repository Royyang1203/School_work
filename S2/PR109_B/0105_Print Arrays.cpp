// Description

// 請設計一個 function 可以使用給定的分隔符號來列印陣列中的資料

// Input
// 整數陣列 arr
// arr 的長度 n

// 分隔符 ch

// Output
// 請使用 cout 來進行輸出

// 每筆資料間需夾一個分隔符。最後一筆資料後不含分隔符。

// ex: [1, 2, 3, 4, 5], 5, ';' 會輸出 1;2;3;4;5
#include <iostream>

void output(int arr[], int n, char ch)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i];
        if (i != n - 1)
            std::cout << ch;
    }
}