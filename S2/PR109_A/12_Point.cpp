// 請設計一個類別 Point 代表二為平面上的一個點。

// Point 這個類別有兩個私有的資料成員 x 跟 y 代表平面上的一個位置，x 跟 y 是浮點數型態的。

// 建立一個預設建構子，將 x 跟 y 設成 0。

// 建立一個傳入兩個浮點數參數的建構子，依序用傳入的參數設定 x 跟 y 。

// 建立一個公開的函數成員 printPoint ，該函數會用 "(x, y)" 這樣的格式做輸出。

// Please design a class Point represent a point onplane coordinates.

// Give this class two private data member x and y represent the location of the point, x and y are float type.

// Create a default constructor to set x and y to 0.

// Create a constructor with two float parameter to set x and y.

// Create a public function member printPoint to display as the format like "(x, y)"

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
    void printPoint()
    {
        std::cout << "(" << x << ", " << y << ")";
    }
};