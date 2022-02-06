// Description

// Gave you a number n, please find the maximum even number less than or equal to n.

// 給定一數字n，請找出不大於n的數字中最大的偶數。

// 請用 cin cout 而不是 scanf printf

// Please use cin, cout instead of scanf, printf.

// Input
// An positive integer n.

// 正整數n

// Output
// An largest even number less than or equal to n.

// 最大的不超過n的偶數

// Sample Input 1

// 11
// Sample Output 1

// 10

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n;
    if (n % 2)
        cout << n - 1;
    else
        cout << n;
}