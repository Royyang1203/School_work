// Description

// 讀入一個數，然後將他無條件捨去到整數後輸出。

// Read in a number, round it down to an integer and display on screen.

// 請用 cin cout 而不是 scanf printf

// Please use cin, cout instead of scanf, printf.

// Input
// 一個數字

// A number.

// Output
// 輸出無條件捨去後的整數。

// Display the integer after round down.

// Sample Input 1

// 1.234
// Sample Output 1

// 1

#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main(void)
{
    double n;
    cin >> n;
    cout << static_cast<int>(n) << endl;
}