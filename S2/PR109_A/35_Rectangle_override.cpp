// Description

// Please reference Q34 create a class Rectangle.

// class Rectangle : public Shape
// {
// public:
//   Rectangle(Segment *);
//   float getArea();
// };

#include <iostream>
#include <cmath>
#include <stdexcept>

class Segment;
class Shape;

class Point
{
private:
    float x = 0;
    float y = 0;

public:
    friend Segment;
    friend Shape;

    Point() = default;
    Point(const float &_x, const float &_y) : x(_x), y(_y) {}
    Point(const Point &that)
    {
        *this = that;
    }

    void printPoint() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }

    float getX() const
    {
        return x;
    }
    float getY() const
    {
        return y;
    }
    void setX(float _x)
    {
        x = _x;
    }
    void setY(float _y)
    {
        y = _y;
    }

    float getDistance(const Point &that) const
    {
        return std::sqrt((x - that.x) * (x - that.x) + (y - that.y) * (y - that.y));
    }

    bool operator!=(const Point &that)
    {
        return this->getX() == that.getX() && this->getY() == that.getY();
    }
};

class Segment
{
private:
    Point point1;
    Point point2;
    double a = 0;
    double b = 0;
    double c = 0;

public:
    friend Shape;

    Segment() = default;
    Segment(const Point &p1, const Point &p2) : point1(p1), point2(p2) {}
    Segment(const Segment &that)
    {
        *this = that;
    }

    Point getP1()
    {
        return point1;
    }
    Point getP2()
    {
        return point2;
    }

    void printSegment() const
    {
        std::cout << "P1 = ";
        point1.printPoint();
        std::cout << ", "
                  << "P2 = ";
        point2.printPoint();
    }
    float getLength() const
    {
        return point1.getDistance(point2);
    }

    void getabc()
    {
        a = point1.y - point2.y;
        b = point2.x - point1.x;
        c = a * point1.x + b * point1.y;
    }

    Point *getIntersect(Segment that)
    {
        //ax + by = c
        getabc();
        that.getabc();

        static Point p;
        double d = this->a * that.b - this->b * that.a;

        if (d == 0) //paralize
        {
            if (point1.x == that.point1.x && point1.y == that.point1.y)
            {
                p = point1;
                return &p;
            }
            else if (point1.x == that.point2.x && point1.y == that.point2.y)
            {
                p = point1;
                return &p;
            }
            else if (point2.x == that.point2.x && point2.y == that.point2.y)
            {
                p = point2;
                return &p;
            }
            else if (point2.x == that.point1.x && point2.y == that.point1.y)
            {
                p = point2;
                return &p;
            }
            else

                return nullptr;
        }
        else
        {
            p.x = (this->c * that.b - this->b * that.c) / d;
            if (p.x == -0)
                p.x = 0;
            p.y = (this->a * that.c - this->c * that.a) / d;
            if (p.y == -0)
                p.y = 0;
            return &p;
        }
        return nullptr;
    }
};

class Shape
{
public:
    Shape() = default;
    Shape(Segment *ptr, int n) // to construct a shape with a serial of segment.
    {

        for (int i = 0; i < n; ++i)
        {
            seg[i] = ptr[i];
        }
        edgeCount = n;
        if (seg[0].point1 != seg[n - 1].point1 && seg[0].point2 != seg[n - 1].point1 &&
            seg[0].point1 != seg[n - 1].point2 && seg[0].point1 != seg[n - 1].point2)
        {
            throw std::invalid_argument("the segment can not construct a close path");
        }
    }

    virtual float getArea() const = 0;
    float getPerimeter()
    {
        float t = 0;
        for (int i = 0; i < edgeCount; ++i)
            t += seg[i].getLength();
        return t;
    }
    Segment &getSeg(int index)
    {
        return seg[index];
    }
    int getEdgeCount()
    {
        return edgeCount;
    }

protected:
    Segment seg[10];
    int edgeCount = 0;
};

class Square : public Shape
{
public:
    Square(Segment *seg) : Shape(seg, 4) {}
    float getArea() const override
    {
        return seg[0].getLength() * seg[0].getLength();
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(Segment *s) : Shape(s, 4) {}
    float getPerimeter() const
    {
        float s = 0;
        for (int i = 0; i < 4; i++)
        {
            s += seg[i].getLength();
        }
        return s;
    }
    float getArea() const override
    {
        float a = seg[0].getLength(), b = seg[0].getLength();
        for (int i = 1; i < 4; ++i)
        {
            if (seg[i].getLength() != a)
                b = seg[i].getLength();
        }
        return a * b;
    }
};
class Triangle : public Shape
{
public:
    Triangle(Segment *s, int c) : Shape(s, c) {}
    float getPerimeter() const
    {
        float s = 0;
        for (int i = 0; i < 3; i++)
        {
            s += seg[i].getLength();
        }
        return s;
    }
    float getArea() const override
    {
        float a = seg[0].getLength(), b = seg[1].getLength(), c = seg[2].getLength();
        float s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }
};