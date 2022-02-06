// Define a class pointType to represent a point in a two-dimensional space.
// Your class must contain the constructors required to solve the problem in Part III.
// Besides, please implement the following two methods for the class:

// double distance(pointType& p): return the distance between the current point object (*this) and the specified point object p.
// For example, we can calculate the distance between p1 and p2 by either p1.distance(p2) or p2.distance(p1).
// bool fall_on(pointType & p): return true if the distance between the current point object (*this) and the specified point object p is below 0.0001.
// You can implement any other methods or operators to solve the problem in Part III, if necessary.

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

class pointType
{
    friend ostream &operator<<(ostream &os, const pointType &that);
    friend istream &operator>>(istream &is, pointType &that);

public:
    pointType() = default;

    pointType(double _x, double _y) : x(_x), y(_y) {}
    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }
    bool set_x(double _x)
    {
        x = _x;
        return true;
    }
    bool set_y(double _y)
    {
        y = _y;
        return true;
    }

    /**
     * @brief return the distance between the current point object (*this) and the specified point object p.
     * For example, we can calculate the distance between p1 and p2 by either p1.distance(p2) or p2.distance(p1).
     * @param that
     * @return double
     */
    inline double distence(const pointType &that) const
    {
        return sqrtf((this->x - that.x) * (this->x - that.x) + (this->y - that.y) * (this->y - that.y));
    }

    /**
     * @brief return true if the distance between the current point object (*this) and the specified point object p is below 0.0001.
     *
     * @param p
     * @return bool
     */
    inline bool fall_on(const pointType &that) const
    {
        return this->distence(that) < 0.0001 ? true : false;
    }

private:
    double y = 0.0;
    double x = 0.0;
};

ostream &operator<<(ostream &os, const pointType &that)
{
    os << "(" << that.x << ", " << that.y << ")";
    return os;
}
istream &operator>>(istream &is, pointType &that)
{
    is >> that.x >> that.y;
    return is;
}

int main()
{
    pointType a(0, 0.001), b(0, 0.00095);
    cout << a.distence(b) << endl;
    cout << a.fall_on(b) << endl;
    return 0;
}