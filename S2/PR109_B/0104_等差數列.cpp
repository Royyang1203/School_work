// Description

// 我們可以用三個參數：首項、公差、項數來描述一個等差數列。

// 舉例來說，1, 3, 5, 7, 91,3,5,7,9 是一個首項為11；公差為22；項數為55的等差數列。

// Input
// 33個整數，首項a_1a
// 1
// ​
//  、公差ss和項數nn。

// 請使用 cin 輸入

// Output
// 輸出相對應的等差數列，每項後都有換行。

// 請使用 cout 輸出，並使用 endl 換行

// Sample Input 1

// 1 2 5
// Sample Output 1

// a[1]=1
// a[2]=3
// a[3]=5
// a[4]=7
// a[5]=9

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    int a1, s, n;
    cin >> a1 >> s >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "a[" << i + 1 << "]=" << a1 << endl;
        a1 += s;
    }
}