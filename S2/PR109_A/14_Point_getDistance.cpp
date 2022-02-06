// 請設計一個類別 Point 代表二為平面上的一個點。

// Point 這個類別有兩個私有的資料成員 x 跟 y 代表平面上的一個位置，x 跟 y 是浮點數型態的。

// 建立一個預設建構子，將 x 跟 y 設成 0。

// 建立一個傳入兩個浮點數參數的建構子，依序用傳入的參數設定 x 跟 y 。

// 建立一個公開的函數成員 printPoint ，該函數會用 "(x, y)" 這樣的格式做輸出。

// 建立公開的函數成員 getX setX getY setY 用來存取資料成員 x 跟 y 。

// 請建立一個公開的函數成員 getDistance ，該函數有一個 Point 型態的參數，會回傳一個浮點數代表兩個點的距離。

// Please design a class Point represent a point onplane coordinates.

// Give this class two private data member x and y represent the location of the point, x and y are float type.

// Create a default constructor to set x and y to 0.

// Create a constructor with two float parameter to set x and y.

// Create a public function member printPoint to display as the format like "(x, y)"

// Create public function member getX, setX, getY, setY to access the data member x and y.

// Create a public function member getDistance with one Point type parameter, return a float type value represent the distance of two point.
#include <cmath>
#include <iostream>

class Point
{
private:
    float x;
    float y;

public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(float a, float b)
    {
        x = a;
        y = b;
    }
    void printPoint() const
    {
        std::cout << "(" << x << ", " << y << ")";
    }
    void setX(float a)
    {
        x = a;
    }
    void setY(float a)
    {
        y = a;
    }
    float getX() const
    {
        return x;
    }
    float getY() const
    {
        return y;
    }
    float getDistance(Point a)
    {
        return std::sqrt(std::fabs((a.getX() - x) * (a.getX() - x) + (a.getY() - y) * (a.getY() - y)));
    }
};

// ___________________________________________________________________

// class Point
// {
// private:
//     float x = 0;
//     float y = 0;
// public:
//     friend Segment;

//     Point () = default;
//     Point (float _x, float _y) : x(_x), y(_y) {}
//     Point (Point &that) { *this = that;}

//     void printPoint () const
//     {
//         std::cout << "(" << x << ", " << y << ")";
//     }

//     float getX () const
//     {
//         return x;
//     }
//     float getY () const
//     {
//         return y;
//     }
//     void setX (float _x)
//     {
//         x = _x;
//     }
//     void setY (float _y)
//     {
//         y = _y;
//     }

//     float getDistance (const Point &that) const
//     {
//         return std::sqrt((x - that.x) * (x - that.x) + (y - that.y) * (y - that.y));
//     }
// };