// Description

//         假定03 -
//     1的 Point 已經完成了，並且有一 abstract class 定義如下：

//     class Printable
// {
// public:
//     virtual std::string toString() const = 0;
// };
// 請設計一名為PPoint2D的 class ，同時繼承Point2D和Printable。PPoint2D 支援所有 Point2D 的初始化方法(即，你需要實作 Point2D 中所有種類的 constructures) 和 copy constructure。

// PPoint2D 呼叫 toString() 時，會回傳一個內容為(<X>, <Y>) 的字串，<X> 和<Y> 為其保存之 X座標 和 Y座標。

// Hint

// toString 可以試著使用

// <sstream> 的 std::ostringstream 或
// <cstdio> 的 sprintf
// 來完成

#include <iostream>
#include <string>
#include <sstream>

class Point2D
{
protected:
    double x = 0, y = 0;

public:
    Point2D() = default;
    Point2D(const Point2D &that)
    {
        *this = that;
    }
    Point2D(const double X, const double Y) : x(X), y(Y) {}
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
    /*
    void setX (const double &that)
    {
        x = that;
    }
    void setY (const double &that)
    {
        y = that;
    }
    */
};

class Printable
{
public:
    virtual std::string toString() const = 0;
    virtual void setX(const double &) = 0;

    friend std::ostream &operator<<(std::ostream &os, const Printable &that);
};

std::ostream &operator<<(std::ostream &os, const Printable &that)
{
    os << that.toString();
    return os;
}

class PPoint2D : public Printable, public Point2D
{
public:
    PPoint2D(const double _x = 0, const double _y = 0) : Point2D(_x, _y) {}
    PPoint2D(const PPoint2D &that) : Point2D(that.getX(), that.getY()) {}
    PPoint2D(const Point2D &that) : Point2D(that) {}
    virtual std::string toString() const
    {
        std::ostringstream _s;
        _s << "(" << getX() << ", " << getY() << ")";
        std::string s(_s.str());
        return s;
    }
    void setX(const double &that)
    {
        x = that;
    }
};
