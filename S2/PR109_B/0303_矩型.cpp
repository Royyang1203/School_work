// Description

// Point2D(PR109-2-03-1), Vector2D(PR109-2-03-2) 已實作完成。

// 請使用 Point2D 和 Vector2D 來設計 class Rectangle2D，可用來保存矩型於2D空間中。

// data members:

// Point2D position: 邊角位置
// Vector2D dimension: 矩型的大小
// constructors:

// default constructor(無參數): (0, 0) (0, 0)
// copy constructor(const Rectangle2D &rect): 複製
// member initialize constructor(const Point2D &p, const Vector2D &v): 將邊角位置和大小設於矩型上，注意需要讓 dimension 的兩邊長都為正數或0。
// member functions:

// Point2D location() const: 回傳位置
// Vector2D size() const: 回傳大小
// double getX() const
// double getY() const
// double getWidth() const: 寬度；即 x 方向大小
// double getHeight() const: 高度；即 y 方向大小
// double getArea() const: 面積
// Rectangle2D intersection(const Rectangle2D &rect): 回傳自己和 rect 重疊部分的矩型
#include "0302_向量.cpp"
class Rectangle2D
{
private:
    Point2D position;
    Vector2D dimension;

public:
    // constructor
    // no parameter constructor
    Rectangle2D() {}
    // copy constructor
    Rectangle2D(const Rectangle2D &rect)
    {
        position = rect.position;
        dimension = rect.dimension;
    }
    //  constructor with given point and vector
    Rectangle2D(const Point2D &p, const Vector2D &v)
    {
        // make each vector number >0
        // if both <0
        if (v.getI() < 0 && v.getJ() < 0)
        {
            Point2D NewPos(p.getX() + v.getI(), p.getY() + v.getJ());
            Vector2D NewVec((v.getI()) * (-1), (v.getJ()) * (-1));
            position = NewPos;
            dimension = NewVec;
        }
        // vector X <0 and vector Y >=0
        else if (v.getI() < 0 && v.getJ() >= 0)
        {
            Point2D NewPos(p.getX() + v.getI(), p.getY());
            Vector2D NewVec((v.getI()) * (-1), v.getJ());
            position = NewPos;
            dimension = NewVec;
        }
        // vector X >=0 and vector Y <0
        else if (v.getI() >= 0 && v.getJ() < 0)
        {
            Point2D NewPos(p.getX(), p.getY() + v.getJ());
            Vector2D NewVec(v.getI(), (v.getJ()) * (-1));
            position = NewPos;
            dimension = NewVec;
        }
        // both >=0
        else
        {
            position = p;
            dimension = v;
        }
    }
    // end of constructor

    // functions
    // get location( point )
    Point2D location() const
    {
        return position;
    }
    // get size( vector )
    Vector2D size() const
    {
        return dimension;
    }
    // get position's X
    double getX() const
    {
        return position.getX();
    }
    // get position's Y
    double getY() const
    {
        return position.getY();
    }
    // get width( vector's X )
    double getWidth() const
    {
        return dimension.getI();
    }
    // get height( vector's Y )
    double getHeight() const
    {
        return dimension.getJ();
    }
    // get area
    double getArea() const
    {
        return dimension.getI() * dimension.getJ();
    }
    /* get the position and size of the same square
		which is covered by two squares at the same time*/
    Rectangle2D intersection(const Rectangle2D &rect)
    {
        double x1 = (this->getX() > rect.getX())
                        ? this->getX()
                        : rect.getX();
        double y1 = (this->getY() > rect.getY())
                        ? this->getY()
                        : rect.getY();
        double x2 = (this->getX() + this->getWidth() < rect.getX() + rect.getWidth())
                        ? (this->getX() + this->getWidth())
                        : (rect.getX() + rect.getWidth());
        double y2 = (this->getY() + this->getHeight() < rect.getY() + rect.getHeight())
                        ? (this->getY() + this->getWidth())
                        : (rect.getY() + rect.getHeight());
        double w = (x2 > x1) ? (x2 - x1) : 0;
        double h = (y2 > y1) ? (y2 - y1) : 0;
        return Rectangle2D(Point2D(x1, y1), Vector2D(w, h));
    } // up above is from A-Shi
};    // end of class Rectangle2D

// ___________________________________________________________________________

// class Rectangle2D
// {
// private:
//     Point2D position;
//     Vector2D dimension;
// public:
//     Rectangle2D ()
//     {
//         position.setX(0);
//         position.setY(0);
//         dimension.setI(0);
//         dimension.setJ(0);
//     }
//     Rectangle2D (const Rectangle2D &that)
//     {
//         position.setX(that.position.getX());
//         position.setY(that.position.getY());
//         dimension.setI(that.dimension.getI());
//         dimension.setJ(that.dimension.getJ());
//     }
//     Rectangle2D (const Point2D &p, const Vector2D &v)
//     {
//         if (v.getI() >= 0)
//         {
//             position.setX(p.getX());
//             dimension.setI(v.getI());
//         }
//         else
//         {
//             position.setX(p.getX() + v.getI());
//             dimension.setI(-v.getI());
//         }
//         if (v.getJ() >= 0)
//         {
//             position.setY(p.getY());
//             dimension.setJ(v.getJ());
//         }
//         else
//         {
//             position.setY(p.getY() + v.getJ());
//             dimension.setJ(-v.getJ());
//         }
//     }
//     Point2D location () const
//     {
//         return position;
//     }
//     Vector2D size () const
//     {
//         return dimension;
//     }
//     double getX () const
//     {
//         return position.getX();
//     }
//     double getY () const
//     {
//         return position.getY();
//     }
//     double getWidth () const
//     {
//         return dimension.getI();
//     }
//     double getHeight () const
//     {
//         return dimension.getJ();
//     }
//     double getArea () const
//     {
//         return dimension.getI() * dimension.getJ();
//     }
//     Rectangle2D intersection (const Rectangle2D &that)
//     {
//         Rectangle2D temp;
//         if (this->position.getX() > that.position.getX() && this->position.getX() < that.position.getX() + that.dimension.getI())
//         {
//             temp.position.setX(this->position.getX());
//             if (this->position.getX() + this->dimension.getI() > that.position.getX() + that.dimension.getI())
//             {
//                 temp.dimension.setI(that.position.getX() + that.dimension.getI() - this->position.getX());
//             }
//             else
//             {
//                 temp.dimension.setI(this->dimension.getI());
//             }
//         }
//         else if (that.position.getX() > this->position.getX() && that.position.getX() < this->position.getX() + this->dimension.getI())
//         {
//             temp.position.setX(that.position.getX());
//             if (that.position.getX() + that.dimension.getI() > this->position.getX() + this->dimension.getI())
//             {
//                 temp.dimension.setI(this->position.getX() + this->dimension.getI() - that.position.getX());
//             }
//             else
//             {
//                 temp.dimension.setI(that.dimension.getI());
//             }
//         }
//         else
//         {
//             temp.dimension.setI(0);
//             temp.position.setX(0);
//         }
//         if (this->position.getY() > that.position.getY() && this->position.getY() < that.position.getY() + that.dimension.getJ())
//         {
//             temp.position.setY(this->position.getY());
//             if (this->position.getY() + this->dimension.getJ() > that.position.getY() + that.dimension.getJ())
//             {
//                 temp.dimension.setJ(that.position.getY() + that.dimension.getJ() - this->position.getY());
//             }
//             else
//             {
//                 temp.dimension.setJ(this->dimension.getJ());
//             }
//         }
//         else if (that.position.getY() > this->position.getY() && that.position.getY() < this->position.getY() + this->dimension.getJ())
//         {
//             temp.position.setY(that.position.getY());
//             if (that.position.getY() + that.dimension.getJ() > this->position.getY() + this->dimension.getJ())
//             {
//                 temp.dimension.setJ(this->position.getY() + this->dimension.getJ() - that.position.getY());
//             }
//             else
//             {
//                 temp.dimension.setJ(that.dimension.getJ());
//             }
//         }
//         else
//         {
//             temp.dimension.setJ(0);
//             temp.position.setY(0);
//         }
//         return temp;
//     }

// };