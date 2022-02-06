// 請設計一個類別 Point 代表二為平面上的一個點。

// Point 這個類別有兩個私有的資料成員 x 跟 y 代表平面上的一個位置，x 跟 y 是浮點數型態的。

// 建立一個預設建構子，將 x 跟 y 設成 0。

// 建立一個傳入兩個浮點數參數的建構子，依序用傳入的參數設定 x 跟 y 。

// 建立一個公開的函數成員 printPoint ，該函數會用 "(x, y)" 這樣的格式做輸出。

// 建立公開的函數成員 getX setX getY setY 用來存取資料成員 x 跟 y 。

// 請建立一個公開的函數成員 getDistance ，該函數有一個 Point 型態的參數，會回傳一個浮點數代表兩個點的距離。

// 請設計一個類別 Segment 代表平面上的一個線段。

// Segment 這個類別有兩個私有的資料成員 point1 跟 point2 表示線段的兩個端點。

// 建立一個預設的建構子將兩個端點預設在 (0, 0) 的位置。

// 建立一個傳入兩個 Point 物件為參數的建構子用來設定 point1 跟 point2 。

// 請設計下列函數成員

// float getLength(); // 沒有參數，回傳線段的長度

// Point *getIntersect(Segment s); //傳入另一個線段，回傳兩個線段的交點，如果不存在交點，回傳 NULL

// Please design a class Point represent a point on plane coordinates.

// Give this class two private data member x and y represent the location of the point, x and y are float type.

// Create a default constructor to set x and y to 0.

// Create a constructor with two float parameter to set x and y.

// Create a public function member printPoint to display as the format like "(x, y)"

// Create public function member getX, setX, getY, setY to access the data member x and y.

// Create a public function member getDistance with one Point type parameter, return a float type value represent the distance of two point.

// Please design a class Segment represent a segment on plane coordinates.

// Give this class two private data member point1 and point2 represent the endpoint of this segment.

// Create a default constructor to set the both endpoint to (0, 0).

// Create a constructor with two Point object as parameter to set two endpoint.

// Implement the following function member

// float getLength(); //No parameter, return the length of the segment.

// Point *getIntersect(Segment s); //with another segment as parameter，return the intersect point if exist, NULL if not.

#include <cmath>
#include <iostream>

class Point
{
private:
    float x;
    float y;

public:
    bool b; //whether is set or not
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

class Segment
{
private:
    Point point1;
    Point point2;
    double a = 0; // ax + by = c
    double b = 0;
    double c = 0;

public:
    Segment()
    {
        point1.setX(0);
        point2.setX(0);
        point1.setY(0);
        point2.setY(0);
    }
    Segment(Point a, Point b)
    {
        point1.setX(a.getX());
        point2.setX(b.getX());
        point1.setY(a.getY());
        point2.setY(b.getY());
    }
    float getLength()
    {
        return point1.getDistance(point2);
    }

    void getLinePara(Segment &line)
    {
        line.a = line.point1.getY() - line.point2.getY();
        line.b = line.point2.getX() - line.point1.getX();
        line.c = line.point1.getX() * line.a + line.b * line.point1.getY();
        //std::cout <<line.a<< " " << line.b<<" "<< line.c << std::endl;
    }
    Point *getIntersect(Segment L1)
    {
        Segment L2(point1, point2);
        getLinePara(L1);
        getLinePara(L2);

        double d = L1.a * L2.b - L2.a * L1.b;
        //std::cout << d << std::endl;
        static Point p;
        p.b = 0;

        if (d == 0) // parallel
        {
            if (L1.point1.getX() == L2.point1.getX() && L1.point1.getY() == L2.point1.getY())
            {
                if (p.b)
                    return NULL;
                else
                {
                    p.setX(L1.point1.getX());
                    p.setY(L1.point1.getY());
                    p.b = 1;
                }
            }
            if (L1.point1.getX() == L2.point2.getX() && L1.point1.getY() == L2.point2.getY())
            {
                if (p.b)
                    return NULL;
                else
                {
                    p.setX(L1.point1.getX());
                    p.setY(L1.point1.getY());
                    p.b = 1;
                }
            }
            if (L1.point2.getX() == L2.point1.getX() && L1.point2.getY() == L2.point1.getY())
            {
                if (p.b)
                    return NULL;
                else
                {
                    p.setX(L1.point2.getX());
                    p.setY(L1.point2.getY());
                    p.b = 1;
                }
            }
            if (L1.point2.getX() == L2.point2.getX() && L1.point2.getY() == L2.point2.getY())
            {
                if (p.b)
                    return NULL;
                else
                {
                    p.setX(L1.point2.getX());
                    p.setY(L1.point2.getY());
                    p.b = 1;
                }
            }
            if (p.b)
                return &p;
            else
                return NULL;
        }
        p.setX((L1.c * L2.b - L1.b * L2.c) / d);
        if (p.getX() == -0)
            p.setX(0);
        p.setY((L1.a * L2.c - L1.c * L2.a) / d);
        if (p.getY() == -0)
            p.setY(0);
        //p.printPoint();
        if (((p.getX() >= L1.point1.getX() && p.getX() <= L1.point2.getX()) || (p.getX() >= L1.point2.getX() && p.getX() <= L1.point1.getX())) && (p.getX() >= L2.point1.getX() && p.getX() <= L2.point2.getX()) || (p.getX() >= L2.point2.getX() && p.getX() <= L2.point1.getX()))
        {
            //std::cout << "!!";
            return &p;
        }
        //std::cout << "@@";
        return NULL;
    }
};

// _______________________________________________________________

// #include <iostream>
// #include <cmath>

// using namespace std;

// class Point
// {
// public:
//     float x, y;
//     Point() : x(0), y(0)
//     {
//     }

//     Point(float _x, float _y) : x(_x), y(_y)
//     {
//     }

//     void printPoint()
//     {
//         cout << "(" << x << ", " << y << ")" << endl;
//     }

//     float getDistance(Point &p_value)
//     {

//         double distance = sqrt(pow(x - p_value.x, 2) + pow(y - p_value.y, 2));
//         return distance;
//     }

//     void setX(float _x)
//     {
//         x = _x;
//     }

//     void setY(float _y)
//     {
//         y = _y;
//     }

//     float getX()
//     {
//         return x;
//     }

//     float getY()
//     {
//         return y;
//     }
// };

// class Segment //y = ax+b
// {
// public:
//     double a = 0, b = 0, c = 0;
//     Segment() : p1(Point(0, 0)), p2(Point(0, 0))
//     {
//     }
//     Segment(Point a, Point b)
//     {
//         p1 = a;
//         p2 = b;
//         //cout<<p1.x <<" "<<p1.y << endl;
//         //cout<<p2.x <<" "<<p2.y << endl;
//     }

//     float getLength()
//     {
//         double distance = sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
//         return distance;
//     }

//     void getLinePara(Segment &line)
//     {
//         line.a = line.p1.y - line.p2.y;
//         line.b = line.p2.x - line.p1.x;
//         line.c = line.p1.x * line.p2.y - line.p2.x * line.p1.y;
//         //cout <<line.a<< " " << line.b<<" "<< line.c <<endl;
//     }

//     Point *getIntersect(Segment L2) // return the intersection of two segment; �p��P�t�@���u�����I�A�p�G�u���@�ӥ��I�N�^�Ǹӥ��I�A��L���p�h�^��NULL
//     {
//         Segment L1(p1, p2);
//         //p1.printPoint();
//         //p2.printPoint();

//         //L2.p1.printPoint();
//         //L2.p2.printPoint();

//         getLinePara(L1);
//         getLinePara(L2);
//         static Point p;

//         double D = L1.a * L2.b - L2.a * L1.b;
//         //cout<< D <<endl;
//         if (D == 0)
//         {
//             if (L1.p1.x == L2.p1.x && L1.p1.y == L2.p1.y)
//             {
//                 p = L1.p1;
//                 return &p;
//             }
//             if (L1.p1.x == L2.p2.x && L1.p1.y == L2.p2.y)
//             {
//                 p = L1.p1;
//                 return &p;
//             }
//             if (L1.p2.x == L2.p1.x && L1.p2.y == L2.p1.y)
//             {
//                 p = L1.p2;
//                 return &p;
//             }
//             if (L1.p2.x == L2.p2.x && L1.p2.y == L2.p2.y)
//             {
//                 p = L1.p2;
//                 return &p;
//             }

//             return NULL;
//         }
//         p.x = (L1.b * L2.c - L2.b * L1.c) / D;
//         if (p.x == -0)
//             p.x = 0;
//         p.y = (L1.c * L2.a - L2.c * L1.a) / D;
//         if (p.y == -0)
//             p.y = 0;
//         //p.printPoint();
//         return &p;
//     }

// private:
//     Point p1, p2;
// };

// int main(void)
// {

//     Point a(2, 1), b(3, 4), c(2, 1), d(3, 4);
//     Segment L1(a, b);
//     Segment L2(c, d);
//     (*L2.getIntersect(L1)).printPoint();
//     //p->printPoint();
// }

// ______________________________________________________________

// class Segment
// {
// private:
//     Point point1;
//     Point point2;
//     double a = 0;
//     double b = 0;
//     double c = 0;
// public:
//     Segment () = default;
//     Segment (Point p1, Point p2) : point1(p1), point2(p2) {}

//     float getLength ()
//     {
//         return point1.getDistance(point2);
//     }

//     void getabc ()
//     {
//         a = point1.y - point2.y;
//         b = point2.x - point1.x;
//         c = a * point1.x + b * point1.y;
//     }

//     Point *getIntersect (Segment that)
//     {
//         //ax + by = c
//         getabc();
//         that.getabc();

//         static Point p;
//         double d = this->a * that.b - this->b * that.a;

//         if (d == 0) //paralize
//         {
//             if (point1.x == that.point1.x && point1.y == that.point1.y)
//             {
//                 p = point1;
//                 return &p;
//             }
//             else if (point1.x == that.point2.x && point1.y == that.point2.y)
//             {
//                 p = point1;
//                 return &p;
//             }
//             else if (point2.x == that.point2.x && point2.y == that.point2.y)
//             {
//                 p = point2;
//                 return &p;
//             }
//             else if (point2.x == that.point1.x && point2.y == that.point1.y)
//             {
//                 p = point2;
//                 return &p;
//             }
//             else

//                 return nullptr;
//         }
//         else
//         {
//             p.x = (this->c * that.b - this->b * that.c) / d;
//             if(p.x == -0)
//                 p.x = 0;
//             p.y = (this->a * that.c - this->c * that.a) / d;
//             if (p.y == -0)
//                 p.y = 0;
//             return &p;
//         }
//         return nullptr;
//     }

// };