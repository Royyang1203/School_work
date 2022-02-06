// Description

// 假設已經有實作好的 Point class (描述於 PR109-2-03-1中)，請設計一 class Vector2D 包含：

// data members:

// double i: x 方向之分量 i。
// double j: y 方向之分量 j。
// constructors:

// default constructors (無參數): 將向量設為 (0, 0)
// copy constructors (const Vector2D &v): 將本身的資料設為 v 中所存之向量。
// member initialize constructor (double I, double J): 將本身的向量設為 (I, J)。
// (Point2D start, Point2D end): 令 start + (i, j) = end。
// member functions:

// double norm1() const
// double norm2() const
// double getI() const
// double getJ() const
// Vector2D scale(double ratio) const: 回傳一個 ratio 倍的向量(新Vector物件，非改自身的值)。
#include "0301_點.cpp"
#include <iostream>
#include <cmath>

class Vector2D
{
private:
    double i, j;

public:
    Vector2D()
    {
        i = 0;
        j = 0;
    }
    Vector2D(const Vector2D &that)
    {
        i = that.getI();
        j = that.getJ();
    }
    Vector2D(const double I, const double J)
    {
        i = I;
        j = J;
    }
    Vector2D(const Point2D &start, const Point2D &end)
    {
        i = end.getX() - start.getX();
        j = end.getY() - start.getY();
    }

    double getI() const
    {
        return i;
    }
    double getJ() const
    {
        return j;
    }
    void setI(const double I)
    {
        i = I;
    }
    void setJ(const double J)
    {
        j = J;
    }

    double norm1() const
    {
        return std::abs(i) + std::abs(j);
    }
    double norm2() const
    {
        return std::sqrt(i * i + j * j);
    }
    Vector2D scale(double ratio) const
    {
        static Vector2D that(this->getI() * ratio, this->getJ() * ratio);
        return that;
    }
};