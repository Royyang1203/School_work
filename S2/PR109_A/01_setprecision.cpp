// Description

// 有一個男的朝著同一個方向在 Y 小時內走了 X 公里。

// 請問他的速度是多少公里每小時？

// A man walks X km in Y hours  in the same direction.

// What is the man's velocity in km/h for the journey?

// 請用 cin cout 而不是 scanf printf

// Please use cin, cout instead of scanf, printf.

// Input
// 輸入會包含兩個數字，兩個數字間會用一個空白隔開，第一個數字代表距離，單位是公里，第二個數字代表時間，單位是小時。

// Input contain two number in a line and separate by a single space, first number stand for distance in km, second number stand for time in hour.

// Output
// 輸出一個數字代表速度，請用 km/h 為單位，四捨五入到小數點後六位。

// A number stand for velocity in km/h, please rounded to six decimal places.

// Sample Input 1

// 7 2
// Sample Output 1

// 3.500000

#include <iostream>
#include <iomanip>
using namespace std;

int main(void)
{
    double n, m;
    cin >> n >> m;
    cout << setiosflags(ios::fixed) << setprecision(6) << n / m << endl;
}