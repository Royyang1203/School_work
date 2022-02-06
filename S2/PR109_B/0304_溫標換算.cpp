// Description

// Constructors 也可用於轉型。

// 我們知道華氏和攝氏互轉的關係： F = 1.8C + 32F=1.8C+32。

// 只要我們於 F class 中實作 F(const C &temp) 這樣的 constructor，程式就會於 F f = c; 時，依你實作的 constructor 來進行轉型。

// 現在，請實作兩個 class F 和 C ，兩者都包含：

// data member:

// double temp: 溫度
// constructors:

// (): 設temp為 0
// (const C& temp) 用於 C的copy 或 F的轉型
// (const F& temp) 用於 F的copy 或 C的轉型
// member initialize constructor (double T)
// member function:

// double getTemperature() 回傳溫度。
#include <iostream>
class C;
class F
{
private:
    double temp;

public:
    F();
    F(const F &that);
    F(const C &that);
    F(double T);
    double getTemperature() const;
};

class C
{
private:
    double temp;

public:
    C();
    C(const C &that);
    C(const F &that);
    C(double T);
    double getTemperature() const;
};

F::F()
{
    temp = 0;
}
F::F(const F &that)
{
    temp = that.getTemperature();
}
F::F(const C &that)
{
    temp = that.getTemperature() * 1.8 + 32;
}
F::F(double T)
{
    temp = T;
}
double F::getTemperature() const
{
    return temp;
}

C::C()
{
    temp = 0;
}
C::C(const C &that)
{
    temp = that.getTemperature();
}
C::C(const F &that)
{
    temp = (that.getTemperature() - 32) / 1.8;
}
C::C(double T)
{
    temp = T;
}
double C::getTemperature() const
{
    return temp;
}