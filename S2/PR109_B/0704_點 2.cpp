// Description

// 假定03-1已經完成，請繼承 Point2D 來製作 Point3D。
#include "0301_點.cpp"

class Point3D : public Point2D
{
    double z = 0;

public:
    Point3D() : Point2D() {}
    Point3D(const Point3D &src)
    {
        *this = src;
    }
    Point3D(double X, double Y, double Z) : Point2D(X, Y), z(Z) {}
    double getZ() const
    {
        return z;
    }
};