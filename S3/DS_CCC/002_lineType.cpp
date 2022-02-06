// The equation of a line in standard form is , wherein both  and  cannot be zero, and , and  are real numbers.
// If , then  is the slope of the line. If , then it is a horizontal line, and if , then it is a vertical line.
// The slope of a vertical line is undefined. Two lines are parallel if they have the same slope or both are vertical lines.
// Two lines are perpendicular if either one of the lines is horizontal and the other is vertical or the product of their slopes is
// Design the class lineType to store a line. To store a line, you need to store the values of  (coefficient of  (coefficient of  ),
// and . Besides the required constructors, your class must also contain the following operations:

// Overloads the stream insertion operator, <<, for easy output.
// Overloads the stream extraction operator, >>, for easy input. (The line  is input as  )
// Overloads the operator |, as a member function, so that it returns true if two lines are parallel; false otherwise.
// Overloads the operator &, as a member function, so that it returns true if two lines are perpendicular; false otherwise.
// Design a bool fall_on(pointType& p) method which returns true if the distance between this linePoint object and the specified p is below 0.0001.

// Hint: the distance between a point  and a line  is .
// You can implement any other methods or operators to solve the problem in Part III, if necessary.

#include "001_pointType.cpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>

class lineType
{
    friend ostream &operator<<(ostream &os, const lineType &that);
    friend istream &operator>>(istream &is, lineType &that);
    friend bool operator|(const lineType &this, const lineType &that);
    friend bool operator&(const lineType &this, const lineType &that);

public:
    lineType() = default;
    lineType(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    bool set_a(double _a)
    {
        a = _a;
        return true;
    }
    bool set_b(double _b)
    {
        b = _b;
        return true;
    }
    bool set_c(double _c)
    {
        c = _c;
        return true;
    }
    double get_a() const
    {
        return a;
    }
    double get_b() const
    {
        return b;
    }
    double get_c() const
    {
        return c;
    }

    inline bool fall_on(pointType &that) const
    {
        return fabs(a * that.get_x() + b * that.get_y() + c) / sqrtf(a * a + b * b) < 0.0001 ? true : false;
    }

private:
    // ax + by + c = 0
    double a = 0.0; // coefficient of x
    double b = 0.0; // coefficient of y
    double c = 0.0;
};

ostream &operator<<(ostream &os, const lineType &that)
{
    os << that.a << "x + " << that.b << "y + " << that.c << " = 0";
    return os;
}

istream &operator>>(istream &is, lineType &that)
{
    is >> that.a >> that.b >> that.c;
    return is;
}

/**
 * @brief returns true if two lines are parallel; false otherwise.
 *
 * @param this
 * @param that
 * @return bool
 */
bool operator|(const lineType &this, const lineType &that)
{
    if (this.b == 0 && that.b == 0)
        return true;
    else if (this.b != 0 && that.b != 0)
        return fabs(this.a / this.b) == fabs(that.a / that.b);
    return false;
}

/**
 * @brief returns true if the distance between this linePoint object and the specified p is below 0.0001.
 *
 * @param this
 * @param that
 * @return bool
 */
bool operator&(const lineType &this, const lineType &that)
{
    if (this.a == 0 && that.b != 0 || this.a != 0 && that.b == 0)
        return true;
    else if (-this.a / this.b * -that.a / that.b == -1)
        return true;
    return false;
}