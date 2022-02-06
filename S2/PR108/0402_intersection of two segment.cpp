// Description

// 有下列兩個類別

class Point
{
public:
    float x, y;
};

class Segment // 用兩個點表示一個線段 using two Point to represent a segment
{
public:
    Segment(Point _a, Point _b);
    Point *getIntersection(Segment that);
    // 計算與另一條線段的交點，如果只有一個交點就回傳該交點，
    // 其他狀況則回傳NULL return the intersection with another segment if exist,
    // return NULL when there are no intersection.

    float length(); //回傳線段的長度 return the length of segment
    Point getPointA()
    {
        return a;
    }
    Point getPointB()
    {
        return b;
    }

private:
    Point a, b;
    double ax = 0, bx = 0, cx = 0; // ax + by = c
};
// 請完成 getIntersection 跟 length 這兩個方法，以及建構子

// Please finish the two method getIntersection and length, and constructor.

#include <cmath>

Segment(Point _a, Point _b) : a(_a), b(_b)
{
}
Point *getIntersection(Segment that) // 計算與另一條線的交點，如果只有一個交點就回傳該交點，其他狀況則回傳NULL
{
    double aa = this->a.y - this->b.y;
    double ba = this->a.x - this->b.x;
    double ca = aa * this->a.x + ba * this->b.y;

    double ab = that.a.y - that.b.y;
    double bb = that.a.x - that.b.x;
    double cb = ab * that.a.x + bb * that.b.y;

    double d = aa * bb - ab * ba;

    static Point p; // 回傳指標，要在外面也有效

    if (d == 0)
    {
        if (this->a.x == that.a.x && this->a.y == that.a.y)
        {
            p = this->a;
            return &p;
        }
        if (this->a.x == that.b.x && this->a.y == that.b.y)
        {
            p = this->a;
            return &p;
        }
        if (this->b.x == that.a.x && this->b.y == that.a.y)
        {
            p = this->b;
            return &p;
        }
        if (this->b.x == that.b.x && this->b.y == that.b.y)
        {
            p = this->b;
            return &p;
        }
        return NULL;
    }

    p.x = (ba * cb - bb * ca) / d;
    if (p.x == -0)
        p.x = 0;
    p.y = (ca * ab - cb * aa) / d;
    if (p.y == -0)
        p.y = 0;
    return &p;
}
float length()
{
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(void)
{

    Point a(2, 1), b(3, 4), c(2, 1), d(3, 4);
    Segment L1(a, b);
    Segment L2(c, d);
    (*L2.getIntersection(L1)).printPoint();
    //p->printPoint();
}