// Description

// Please reference Q15 create a class Shape represent a 2D shape.

// class Shape
// {
// public:
//   Shape();
//   Shape(Segment *, int ); // to construct a shape with a serial of segment.
// private:
//   Segment seg[10];
//   int edgeCount;
// };

#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

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

public:
    friend Shape;

    Segment() = default;
    Segment(const Point &p1, const Point &p2) : point1(p1), point2(p2) {}
    Segment(const Segment &that)
    {
        *this = that;
    }

    Point getP1() const
    {
        return point1;
    }
    Point getP2() const
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
};

class Shape
{
public:
    Shape() = default;
    Shape(Segment *ptr, int n) // to construct a shape with a serial of segment.
    {

        map<pair<float, float>, int> p;
        for (int i = 0; i < n; ++i)
        {
            seg[i] = ptr[i];
            ++p[pair<float, float>(seg[i].getP1().x, seg[i].getP1().y)];
            ++p[pair<float, float>(seg[i].getP2().x, seg[i].getP2().y)];
        }
        edgeCount = n;

        for (auto t = p.begin(); t != p.end(); ++t)
        {
            if (t->second != 2)
                throw std::invalid_argument("the segment can not construct a close path");
        }
    }

    virtual float getArea() = 0;
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

// _______________________________________________________________

// class Shape
// {
// public:
//     Shape() : edgeCount(0)
//     {
//         //    edgeCount = 0;
//     }
//     Shape(Segment *ptr, int n) // to construct a shape with a serial of segment.
//     {
//         for (int i = 0; i < n; ++i)
//         {
//             seg[i] = ptr[i];
//         }
//         edgeCount = n;
//     }

//     // Segment getSeg(int i)
//     // {
//     //     return seg[i];
//     // }
//     // int getEdgeCount()
//     // {
//     //     return edgeCount;
//     // }

// private:
//     Segment seg[10];
//     int edgeCount;
// };