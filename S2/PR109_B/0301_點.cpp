// Description

// C++ 中含有一些特別的 constructors

// default constructor: 無參數，自動呼叫於 MyType a;
// copy constructor: 參數為 const Type &，呼叫於 MyType b = a;
// member initialize constructor: 列舉 members 於參數列，呼叫於 MyType c = {x, y} 時。
// 請設計一個 class Point2D 包含

// data members：

// double x: x 座標。
// double y: y 座標。
// constructors:

// default constructor (無參數): 將座標設為 (0, 0)
// copy constructor (const Point2D& point): 將本身座標設為 point 中所存的座標
// member initialize constructor (double X, double Y): 將本身座標設為 (X, Y)
// member functions:

// double getX() const : 回傳 x 座標。
// double getY() const: 回傳 y 座標。

#include <iostream>

class Point2D
{
private:
    double x, y;

public:
    Point2D()
    {
        x = 0;
        y = 0;
    }
    Point2D(const Point2D &point)
    {
        x = point.getX();
        y = point.getY();
    }
    Point2D(double X, double Y)
    {
        x = X;
        y = Y;
    }
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
};