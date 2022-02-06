#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

class Base
{
public:
    // 如果不會創造實體 Base 物件，函式內容只要有回傳值就好
    virtual void foo() { return; }
    // 此函示可以讓我們分辨此物件到底是 A 還是 B
    virtual int is_a() const { return 0; }
};

class A : public Base
{
public:
    A()
    {
        a = 0;
        b = 0;
    }
    A(int aa, int bb)
    {
        a = aa;
        b = bb;
    }

    void foo()
    {
        cout << "here is class A" << endl;
    }
    int is_a() const
    {
        return 0;
    }

private:
    int a;
    int b;
};

class B : public Base
{

public:
    B()
    {
        a = 0;
        b = 0;
        c = 0;
    }
    B(int aa, int bb, int cc)
    {
        a = aa;
        b = bb;
        c = cc;
    }
    // 函式後加 override IDE 會檢查是否成功多型
    void foo() override
    {
        cout << "here is class B" << endl;
    }
    int is_a() const
    {
        return 1;
    }

private:
    int a;
    int b;
    int c;
};

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
            B *ptr = new B(a, b, c);
            magic_bag.push_back(ptr);
        }

        else
        {
            cin >> a >> b;
            A *ptr = new A(a, b);
            magic_bag.push_back(ptr);
        }
    }
}

void who()
{
    auto p = magic_bag.begin();
    while (p != magic_bag.end())
    {
        if ((*p)->is_a() == 1)
            (*p)->foo();
        else if ((*p)->is_a() == 0)
            (*p)->foo();
        ++p;
    }
}

int main()
{
    read_and_store();
    who();
    return 0;
}

// 測資
// 10
// 0
// 1 1
// 1
// 1 -1 0
// 0
// 2 1
// 1
// 1 2 3
// 1
// 2 -2 0
// 0
// 1 2
// 1
// 1 -1 1
// 0
// 1.1 1.1
// 1
// 2 2 1
// 1
// -1 -1 0