// Description

// 讀入一個四位數，把它反轉後輸出。

// Read a 4 digit number, reverse it and display it.

// 請用 cin cout 而不是 scanf printf

// Please use cin, cout instead of scanf, printf.

// Input
// 一個四位數的數字，第一位數不會是0。

// A 4 digit number, first digit is not 0.

// Output
// 反轉後的四位數

// A 4 digit number after reverse.

// Sample Input 1

// 1234
// Sample Output 1

// 4321

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(void)
{
    int n;
    char str[10];
    cin >> str;
    n = strlen(str);
    for (int i = n - 1; i >= 0; i--)
        cout << str[i];
}