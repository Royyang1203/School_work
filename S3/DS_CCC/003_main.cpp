// Design a global function touch() in your program which finds the first pointType object,
// say p, in the container, and then outputs all objects in the container which touch p.
// The output formats of a pointType object and a lineType object should be (x,y) and (a,b,c), respectively.
// Design a  global function parallel() in your program which finds the first lineType object,
// say l, in the container, and then outputs all lineType objects in the container which are parallel to l.
// Design a  global function perpendicular() in your program which finds the first lineType object,
// say l, in the container, and then outputs all lineType objects in the container which are parallel to l.

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class pointType;
class lineType;

class Base
{
public:
    Base() = default;
    virtual int what() const = 0;
    virtual double get_x() const { return 0; }
    virtual double get_y() const { return 0; }
    virtual bool set_x(double _x) { return 0; }
    virtual bool set_y(double _y) { return 0; }
    virtual inline double distence(const pointType &that) const { return 0; }
    virtual inline bool fall_on(const pointType &that) const { return 0; }

    virtual bool set_a(double _a) { return 0; }
    virtual bool set_b(double _b) { return 0; }
    virtual bool set_c(double _c) { return 0; }
    virtual double get_a() const { return 0; }
    virtual double get_b() const { return 0; }
    virtual double get_c() const { return 0; }
    virtual bool operator|(const lineType &that) const { return 0; }
    virtual bool operator&(const lineType &that) const { return 0; }
    friend ostream &operator<<(ostream &os, const pointType &that);
    friend istream &operator>>(istream &is, pointType &that);
    friend ostream &operator<<(ostream &os, const lineType &that);
    friend istream &operator>>(istream &is, lineType &that);
};

class pointType : public Base
{
    friend ostream &operator<<(ostream &os, const pointType &that);
    friend istream &operator>>(istream &is, pointType &that);

public:
    pointType() = default;

    pointType(double _x, double _y) : x(_x), y(_y) {}

    int what() const override
    {
        return 0;
    }
    double get_x() const override
    {
        return x;
    }
    double get_y() const override
    {
        return y;
    }
    bool set_x(double _x) override
    {
        x = _x;
        return true;
    }
    bool set_y(double _y) override
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
    inline double distence(const pointType &that) const override
    {
        return sqrtf((this->x - that.x) * (this->x - that.x) + (this->y - that.y) * (this->y - that.y));
    }

    /**
     * @brief return true if the distance between the current point object (*this) and the specified point object p is below 0.0001.
     *
     * @param p
     * @return bool
     */
    inline bool fall_on(const pointType &that) const override
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

class lineType : public Base
{
    friend ostream &operator<<(ostream &os, const lineType &that);
    friend istream &operator>>(istream &is, lineType &that);

public:
    lineType() = default;
    lineType(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}

    int what() const override
    {
        return 1;
    }
    bool set_a(double _a) override
    {
        a = _a;
        return true;
    }
    bool set_b(double _b) override
    {
        b = _b;
        return true;
    }
    bool set_c(double _c) override
    {
        c = _c;
        return true;
    }
    double get_a() const override
    {
        return a;
    }
    double get_b() const override
    {
        return b;
    }
    double get_c() const override
    {
        return c;
    }

    inline bool fall_on(const pointType &that) const override
    {
        return fabs(a * that.get_x() + b * that.get_y() + c) / sqrtf(a * a + b * b) < 0.0001 ? true : false;
    }
    /**
    * @brief returns true if two lines are parallel; false otherwise.
    *
    * @param these
    * @param that
    * @return bool
    */
    bool operator|(const lineType &that) const
    {
        if (this->b == 0 && that.b == 0)
            return true;
        else if (this->b != 0 && that.b != 0)
        {
        }
        return (-this->a / this->b == -that.a / that.b) && (this->b / that.b != this->c / that.c);
        return false;
    }

    /**
    * @brief returns true if the distance between this linePoint object and the specified p is below 0.0001.
    *
    * @param these
    * @param that
    * @return bool
    */
    bool operator&(const lineType &that) const
    {
        if (this->a == 0 && that.b != 0 || this->a != 0 && that.b == 0)
            return true;
        else if (-this->a / this->b * -that.a / that.b == -1)
            return true;
        return false;
    }

private:
    // ax + by + c = 0
    double a = 0.0; // coefficient of x
    double b = 0.0; // coefficient of y
    double c = 0.0;
};

ostream &operator<<(ostream &os, const lineType &that)
{
    os << "(" << that.a << ", " << that.b << ", " << that.c << ")";
    return os;
}

istream &operator>>(istream &is, lineType &that)
{
    is >> that.a >> that.b >> that.c;
    return is;
}

vector<Base *> magic_bag;

void read_and_store()
{
    int n = 0;
    bool k = 0;
    double a = 0, b = 0, c = 0;
    cin >> n;
    while (--n >= 0)
    {
        cin >> k;
        if (k)
        {
            cin >> a >> b >> c;
            lineType *ptr = new lineType(a, b, c);
            cout << *ptr << endl;
            magic_bag.push_back(ptr);
        }

        else
        {
            cin >> a >> b;
            pointType *ptr = new pointType(a, b);
            cout << *ptr << endl;
            magic_bag.push_back(ptr);
        }
    }
}

/**
 * @brief finds the first pointType object, say p, in the container, and then outputs all objects in the container which touch p.
 *
 */
void touch()
{
    auto first = magic_bag.begin();
    while (first != magic_bag.end())
    {
        if ((*first)->what() == 0)
            break;
        ++first;
    }
    auto begin = magic_bag.begin();
    pointType *p = (pointType *)(*first);
    while (begin != magic_bag.end())
    {
        if ((*begin)->fall_on(*p))
        {
            if ((*begin)->what())
            {
                lineType *ptr = (lineType *)*begin;
                cout << *ptr << endl;
            }
            else
            {
                pointType *ptr = (pointType *)*begin;
                cout << *ptr << endl;
            }
        }
        ++begin;
    }
    return;
}

/**
 * @brief finds the first lineType object, say l, in the container, and then outputs all lineType objects in the container which are parallel to l.
 *
 */
void parallel()
{
    auto first = magic_bag.begin();
    while (first != magic_bag.end())
    {
        if ((*first)->what() == 1)
            break;
        ++first;
    }
    auto begin = magic_bag.begin();
    lineType *p = (lineType *)(*first);
    while (begin != magic_bag.end())
    {
        if ((*begin)->what() == 1 && ((**begin) | *p))
        {
            lineType *ptr = (lineType *)*begin;
            cout << *ptr << endl;
        }
        ++begin;
    }
    return;
}

/**
 * @brief finds the first lineType object, say l, in the container, and then outputs all lineType objects in the container which are parallel to l.
 *
 */
void perpendicular()
{
    auto first = magic_bag.begin();
    while (first != magic_bag.end())
    {
        if ((*first)->what() == 1)
            break;
        ++first;
    }
    auto begin = magic_bag.begin();
    lineType *p = (lineType *)(*first);
    while (begin != magic_bag.end())
    {
        if ((*begin)->what() == 1 && ((**begin) & *p))
        {
            lineType *ptr = (lineType *)*begin;
            cout << *ptr << endl;
        }
        ++begin;
    }
    return;
}

int main()
{
    pointType p1(2, 3), p2(1, 0);
    lineType l1(-1, 1, 1), l2(2, 2, -10), l3(-3, 3, 0);
    cout << p1.fall_on(p2) << endl;
    cout << l1.fall_on(p1) << endl;
    cout << l1.fall_on(p2) << endl;
    cout << (l1 | l2) << endl;
    cout << (l1 | l3) << endl;
    cout << (l1 & l2) << endl;
    cout << (l1 & l3) << endl;

    cout << "*** Output of read_and_store() ----------" << endl;
    read_and_store();
    cout << "*** Output of touch() ----------" << endl;
    touch();
    cout << "*** Output of parallel() ----------" << endl;
    parallel();
    cout << "*** Output of perpendicular() ----------" << endl;
    perpendicular();
    cout << "----------" << endl;
    return 0;
}