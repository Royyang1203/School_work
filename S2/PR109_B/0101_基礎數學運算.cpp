// Description

// 請計算兩個整數套用各種基礎數學運算的結果。

// Input
// 兩個整數 aa、bb

// Output
// 參考範例輸出以 std::cout << 來輸出，並使用 std::endl 來進行換行。

// 加、減、乘、餘 的輸出為整數

// 除法的結果請輸出至小數點下第44位

// Sample Input 1

// 4 3
// Sample Output 1

// 4+3=7
// 4-3=1
// 4*3=12
// 4/3=1.3333
// 4%3=1

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string.h>
using namespace std;

int main(void)
{
    int n, m;
    cin >> n >> m;
    cout << n << "+" << m << "=" << n + m << endl;
    cout << n << "-" << m << "=" << n - m << endl;
    cout << n << "*" << m << "=" << n * m << endl;
    cout << n << "/" << m << "=" << setprecision(4) << fixed << static_cast<double>(n) / m << endl;
    cout << n << "%" << m << "=" << n % m << endl;
}
