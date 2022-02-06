// Description

// 請設計一個 template classPoint<D>，用於表示D維空間中的點。此 class 中每個維度的座標都是double型別的。

// 此 class 包含下列 construcrures：

// (): 將所有維度的座標設為 0.0。
// (const Point& src): 複製src每個維度的座標。
// (double pos[]): 將 pos[0]存於第1維，pos[1]存於第2維，以下類推。
// destrusture: 刪除所有配置之空間/物件。 和

// 下列方法:

// double get(size_t d) const: 回傳第d維的座標，1≤d≤D。
// double set(size_t d, double val): 設定第d維的座標，1≤d≤D。
// 若 get/set 中的維度不在合法範圍，請丟出帶有 "Need hyper dimension" 訊息之 invalid_argument 例外。
// 並多載 operator << 令其可以用(第一維, 第二維, 第三維..., 最末維)之格式來輸出其座標。

// #include <stdexcept>

// template <size_t D>
// class Point
// {
// };

// #include <iostream>

// template <size_t D>
// std::ostream &operator<<(std::ostream &out, const Point<D> &p)
// {
// }

// ------------------------------------------

#include <stdexcept>
using namespace std;
template <size_t D>
class Point
{
private:
    double x[D];

public:
    Point()
    {
        for (int i = 0; i < D; ++i)
        {
            x[i] = 0.0;
        }
    }
    Point(const Point &src)
    {
        for (int i = 0; i < D; ++i)
        {
            x[i] = src.x[i];
        }
    }
    Point(double pos[])
    {
        for (int i = 0; i < D; i++)
        {
            x[i] = pos[i];
        }
    }
    double get(size_t d) const
    {
        if (d > D)
            throw invalid_argument("Need hyper dimension");
        return x[d - 1];
    }
    double set(size_t d, double val)
    {
        if (d > D)
            throw invalid_argument("Need hyper dimension");
        double a;
        a = x[d - 1];
        x[d - 1] = val;
        return a;
    }
};

#include <iostream>

template <size_t D>
std::ostream &operator<<(std::ostream &out, const Point<D> &p)
{
    cout << "(";
    for (int i = 0; i < D; i++)
    {
        if (i != 0)
            cout << ", ";
        cout << p.get(i + 1);
    }
    cout << ")";
}
