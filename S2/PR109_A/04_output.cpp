// Description

// 請寫一隻程式，讓使用者輸入兩個整數，然後分別輸出兩數相加、相減、相乘、相除，同餘的結果。

// Please write a program allow user input two integer and print out the result of addition subtraction multiplication  division and modulo of two integer.

// 請用 cin cout 而不是 scanf printf

// Please use cin, cout instead of scanf, printf.

// Input
// 輸入兩個整數，兩個數之間用一個空白隔開

// two integer separate by a single space

// Output
// 請參考範例輸出

// see sample output

// Sample Input 1

// 1 2
// Sample Output 1

// 1 + 2 = 3
// 1 - 2 = -1
// 1 * 2 = 2
// 1 / 2 = 0
// 1 % 2 = 1

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    cout << n << " + " << m << " = " << n + m << endl;
    cout << n << " - " << m << " = " << n - m << endl;
    cout << n << " * " << m << " = " << n * m << endl;
    cout << n << " / " << m << " = " << n / m << endl;
    cout << n << " % " << m << " = " << n % m << endl;
}
