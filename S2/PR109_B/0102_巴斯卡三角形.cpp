// Description
// 請輸出 nn 層的巴斯卡三角形

// Input
// 整數 nn
// 請使用 cin 進行輸入

// Output

// 一個輸出單元佔兩個字元。有兩種可能的單元，分別是空格和數字。
// 若為 &lt;
// 10 < 10的數字，則需靠右對齊
// 巴斯卡三角形需置中對齊

// 例：高度33時
// □□■\n
// □■□■\n
// ■□■□■\n
// \n

// 其中□為雙空白；■為數字。
// 請使用 cout 進行輸出

// Sample Input
// 1

// 5 Sample Output 1
//     1
//    1 1
//   1 2 1
//  1 3 3 1
// 1 4 6 4 1

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

int factorial(int n)
{
    if (n == 1 || n <= 0)
        return 1;
    return n * factorial(n - 1);
}

int main(void)
{
    int n;
    cin >> n;
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= i;
        for (int j = n - i; j > 0; j--)
            cout << setw(2) << " ";
        for (int j = 0; j < i; j++)
        {
            cout << setw(2) << factorial(i - 1) / factorial(j) / factorial(i - j - 1);
            if (j != i - 1)
                cout << setw(2) << " ";
        }
        cout << endl;
    }
}