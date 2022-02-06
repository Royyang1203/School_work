#include <iostream>
#include <ostream>
#include <istream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define POINT 0
#define LINE 1
class BaseType
{
public:
    BaseType()
    {
    }
    virtual void printData(){};
    virtual bool fall_on(BaseType &p)
    {
        return false;
    };
    virtual int instanceof ()
    {
        return -1;
    };
};
class pointType : public BaseType
{
protected:
    double x, y;

public:
    friend istream &operator>>(istream &in, pointType &p);
    friend ostream &operator<<(ostream &out, pointType &p);
    pointType()
    {
        x = y = 0;
    }
    pointType(pointType &p)
    {
        x = p.x;
        y = p.y;
    }
    pointType(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
    int instanceof ()
    {
        return POINT;
    }
    void set(double xx, double yy)
    {
        x = xx;
        y = yy;
    }
    void get(double *xx, double *yy)
    {
        *xx = x;
        *yy = y;
    }
    double distance(pointType &p)
    {
        return (sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y)));
    }
    bool fall_on(BaseType &p)
    {
        double d = distance((pointType &)p);
        return (d <= 0.0001);
    }
    void printData()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
class lineType : public BaseType
{
protected:
    double a, b, c;

public:
    friend istream &operator>>(istream &in, lineType &l);
    friend ostream &operator<<(ostream &out, lineType &l);
    lineType()
    {
        a = b = c = 0;
    }
    lineType(lineType &l)
    {
        a = l.a;
        b = l.b;
        c = l.c;
    }
    lineType(double aa, double bb, double cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
    bool operator+()
    {
        return (a != 0 && b == 0);
    }
    bool operator-()
    {
        return (a == 0 && b != 0);
    }
    bool operator==(lineType &l)
    {
        return (a == l.a && b == l.b && c == l.c);
    }
    bool operator|(lineType &l)
    {
        return (a * l.b == b * l.a);
    }
    bool operator&(lineType &l)
    {
        return (a * l.a + b * l.b == 0);
    }
    void set(double aa, double bb, double cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
    void get(double *aa, double *bb, double *cc)
    {
        *aa = a;
        *bb = b;
        *cc = c;
    }
    int instanceof ()
    {
        return LINE;
    }
    bool fall_on(BaseType &p)
    {
        pointType &p1 = (pointType &)p;
        double x, y;
        p1.get(&x, &y);
        double d = fabs(a * x + b * y + c) / sqrt(a * a + b * b);
        return (d <= 0.0001);
    }
    void printData()
    {
        cout << "(" << a << ", " << b << ", " << c << ")" << endl;
    }
};
istream &operator>>(istream &in, pointType &p)
{
    double x, y;
    cin >> x >> y;
    p.set(x, y);
    return in;
}
ostream &operator<<(ostream &out, pointType &p)
{
    double x, y;
    p.get(&x, &y);
    cout << "(" << x << "," << y << ")";
    return out;
}
istream &operator>>(istream &in, lineType &l)
{
    double a, b, c;
    cin >> a >> b >> c;
    l.set(a, b, c);
    return in;
}
ostream &operator<<(ostream &out, lineType &l)
{
    double a, b, c;
    l.get(&a, &b, &c);
    cout << "(" << a << "," << b << "," << c << ")";
    return out;
}
vector<BaseType *> magic_bag;
void read_and_store()
{
    int n;
    int type;
    pointType p;
    pointType *pp;
    lineType *pl;
    lineType l;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type;
        switch (type)
        {
        case 0:
            cin >> p;
            pp = new pointType(p);
            magic_bag.push_back(pp);
            break;
        case 1:
            cin >> l;
            pl = new lineType(l);
            magic_bag.push_back(pl);
        }
    }
}
void touch()
{
    BaseType *p = NULL, *p1 = NULL;
    vector<BaseType *>::iterator it = magic_bag.begin();
    while ((*it)->instanceof () != POINT)
    {
        it++;
        if (it == magic_bag.end())
            break;
    }
    p = *it;
    for (it = magic_bag.begin(); it != magic_bag.end(); it++)
    {
        p1 = *it;
        if (p1->fall_on(*p))
            p1->printData();
    }
}
void parallel()
{
    BaseType *p = NULL, *p1 = NULL;
    vector<BaseType *>::iterator it = magic_bag.begin();
    while ((*it)->instanceof () != LINE)
    {
        it++;
        if (it == magic_bag.end())
            break;
    }
    p = *it;
    for (vector<BaseType *>::iterator it = magic_bag.begin(); it != magic_bag.end(); it++)
    {
        p1 = *it;
        if ((p1->instanceof () == LINE))
            if ((lineType &)(*p1) | (lineType &)(*p))
                p1->printData();
    }
}
void perpendicular()
{
    BaseType *p = NULL, *p1 = NULL;
    vector<BaseType *>::iterator it = magic_bag.begin();
    while ((*it)->instanceof () != LINE)
    {
        it++;
        if (it == magic_bag.end())
            break;
    }
    p = *it;
    for (vector<BaseType *>::iterator it = magic_bag.begin(); it != magic_bag.end(); it++)
    {
        p1 = *it;
        if ((p1->instanceof () == LINE))
            if ((lineType &)(*p1) & (lineType &)(*p))
                p1->printData();
    }
}
int main()
{
    cout << "*** Output of read_and_store() ----------" << endl;
    read_and_store();
    cout << "*** Output of touch() ----------" << endl;
    touch();
    cout << "*** Output of parallel() ----------" << endl;
    parallel();
    cout << "*** Output of perpendicular() ----------" << endl;
    perpendicular();
    cout << "----------" << endl;
    pointType p1(2.0, 3.0), p2(1.0, 0.0);
    lineType l1(-1.0, 1.0, 1.0), l2(2.0, 2.0, -10.0), l3(-3.0, 3.0, 0.0);
    cout << p1.fall_on(p2) << endl;
    cout << l1.fall_on(p1) << endl;
    cout << l1.fall_on(p2) << endl;
    cout << (l1 | l2) << endl;
    cout << (l1 | l3) << endl;
    cout << (l1 & l2) << endl;
    cout << (l1 & l3) << endl;
    return 0;
}