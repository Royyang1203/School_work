// Description

// 假定03-1,03-2都已經完成了。

// 請繼承 Vector2D 來完成 Vector3D 和相應的 operator

#include "0302_向量.cpp"
class Vector3D : public Vector2D
{
    double k = 0;

public:
    Vector3D() : Vector2D() {}
    Vector3D(const Vector3D &V)
    {
        *this = V;
    }
    Vector3D(Point3D start, Point3D end) : Vector2D(end.getX() - start.getX(), end.getY() - start.getY()), k(end.getZ() - start.getZ()) {}
    Vector3D(double I, double J, double K) : Vector2D(I, J), k(K) {}
    double getK() const
    {
        return k;
    }
};

// 放大 scale 倍
Vector3D operator*(Vector3D v, int scale)
{
    return Vector3D(v.getI() * scale, v.getJ() * scale, v.getK() * scale);
}

// 計算內積
double operator*(Vector3D u, Vector3D v)
{
    return u.getI() * v.getI() + u.getJ() * v.getJ() + u.getK() * v.getK();
}