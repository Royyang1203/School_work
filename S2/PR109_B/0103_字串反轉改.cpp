// Description

// 給定一字串 ss。

// 將其反轉並將其所有的小寫字母轉成大寫字母。

// Input
// 請使用 cin 輸入字串 ss。

// ss 是一個長度介於 11 至 255255 間，由大小寫英文字母構成的字串。

// Output
// 請使用 cout 輸出

// Sample Input 1
// and

// Sample Output 1
// DNA

#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
    char arr[1000];
    cin >> arr;
    int n;
    n = strlen(arr);
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= 'A' && arr[i] <= 'Z')
            arr[i] += 32;
        if (arr[i] >= 'a' && arr[i] <= 'z')
            arr[i] -= 32;
        cout << arr[i];
    }
}
