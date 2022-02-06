// Description

// 立於矩型2-1的基礎上，加上兩個 cascaded invokable methods

// move (Vector2D 平移方向): 平移該矩型，但不回存其結果。
// scale (double 倍率): 放大該矩型，但不回存其結果。若倍率為負，丟出訊息為 "Rate is negative" 的 invalid_argument 例外。

#include "0302_向量.cpp"
#include <stdexcept>
using namespace std;
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
        return (w != 0 || h != 0)
                   ? Rectangle2D(Point2D(x1, y1), Vector2D(w, h))
                   : throw invalid_argument("No intersection");
    } // up above is from A-C

    // use cascaded invokable methods to move the rectangle
    Rectangle2D move(Vector2D v)
    {
        Point2D newPos(position.getX() + v.getI(), position.getY() + v.getJ());
        return Rectangle2D(newPos, dimension);
    }
    // use cascaded invokable methods to scale the rectangle
    Rectangle2D scale(double r)
    {
        if (r < 0)
        {
            throw invalid_argument("Rate is negative");
        }
        else
        {
            Vector2D newVec(dimension.getI() * r, dimension.getJ() * r);
            return Rectangle2D(position, newVec);
        }
    }
}; // end of class Rectangle2D
