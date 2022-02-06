// Description

// 04-4中的 Rectangle2D 已經實作完成了

// 請輸入兩組 x, y,寬, 高

// 輸出這兩個矩型和他們相交的矩型，若無相交則請輸出錯誤訊息。

// Input
// 8 個 double，即 2 組 Rectangle2D 的 x, y, 寬, 高。

// Output
// size (寬x長) at (x, y)

// 或

// No intersection

// Sample Input 1

// 1.0 1.0 2.0 2.0
// 8.0 8.0 -2.0 3.0
// Sample Output 1

// size (2x2) at (1, 1)
// size (2x3) at (6, 8)
// No intersection
#include <iostream>
#include "0404_矩型_2_1.cpp"

using namespace std;

int main()
{
    double x1, y1, w1, h1, x2, y2, w2, h2;
    cin >> x1 >> y1 >> w1 >> h1;
    cin >> x2 >> y2 >> w2 >> h2;
    Point2D p1(x1, y1), p2(x2, y2);
    Vector2D v1(w1, h1), v2(w2, h2);
    Rectangle2D r1(p1, v1), r2(p2, v2);
    cout << "size (" << r1.getWidth() << "x" << r1.getHeight() << ") at (" << r1.getX() << ", " << r1.getY() << ")" << endl;
    cout << "size (" << r2.getWidth() << "x" << r2.getHeight() << ") at (" << r2.getX() << ", " << r2.getY() << ")" << endl;
    try
    {
        Rectangle2D r3 = r1.intersection(r2);
        cout << "size (" << r3.getWidth() << "x" << r3.getHeight() << ") at (" << r3.getX() << ", " << r3.getY() << ")" << endl;
    }
    catch (invalid_argument &a)
    {
        cout << a.what() << endl;
    }
}