// 10
// 3
// 1 0 1
// 2 13 16
// 3 17 4
// 4 22 10
// 5 40 1
// 6 44 10
// 7 54 1
// 8 57 10
// 9 63 19
// 10 78 8

#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class Client
{
public:
    int id;    // personal identifier
    int start; // the time to make the order
    int enter; // the time to enter the shop
    int dur;   // the needed service time
    int counter;

    Client() {}
    Client(int _i, int _t, int _d, int _c) : id(_i), start(-1), enter(_t), dur(_d), counter(_c) {}
};

class Shop
{
private:
    int checkout_counter;
    queue<Client> *que;
    int time;
    bool print_time;

public:
    Shop() {}
    Shop(int _n) : checkout_counter(_n), time(0), print_time(false)
    {
        que = new queue<Client>[_n];
    }

    void enter(int _i, int _t, int _d)
    {
        int k = que[0].size();
        int counter = 0;
        for (int i = 1; i < checkout_counter; ++i)
        {
            if ((int)que[i].size() < k)
            {
                // cout << "test" << que[i].size() << " " << k << endl;
                counter = i;
                k = que[i].size();
            }
        }
        que[counter].push(Client(_i, _t, _d, counter));
        if (!print_time)
        {
            cout << "Time " << time << ": ";
            print_time = true;
        }
        cout << "C" << _i << ">>>(D:" << _d << ")|";
        wait(_i, counter);
    }

    void wait(int _i, int _counter)
    {
        if (!print_time)
        {
            cout << "Time " << time << ": ";
            print_time = true;
        }
        cout << "C" << _i << "-->"
             << "Q" << _counter + 1 << "|";
        if (que[_counter].front().id == _i)
            order(_counter);
    }

    void order(int _counter)
    {
        que[_counter].front().start = time;
        if (!print_time)
        {
            cout << "Time " << time << ": ";
            print_time = true;
        }
        cout << "C" << que[_counter].front().id << "@Q"
             << _counter + 1 << " (ETL:" << time + que[_counter].front().dur << ")|";
    }

    void leave(int _counter)
    {
        if (!print_time)
        {
            cout << "Time " << time << ": ";
            print_time = true;
        }
        cout << "C" << que[_counter].front().id << "<--Q" << _counter + 1 << "|";
        que[_counter].pop();
        if (!que[_counter].empty())
            order(_counter);
    }

    int get_time()
    {
        return time;
    }

    queue<Client> *get_que()
    {
        return que;
    }

    void add_time()
    {
        ++time;
        if (print_time)
        {
            print_time = false;
            cout << endl;
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    int i, t, d;
    Shop shop(m);
    for (int j = 0; j < n; ++j)
    {
        cin >> i >> t >> d;
        if (t == shop.get_time())
        {
            shop.enter(i, t, d);
        }
        while (t > shop.get_time())
        {
            shop.add_time();
            if (t == shop.get_time())
            {
                shop.enter(i, t, d);
            }
            for (int i = 0; i < m; ++i)
            {
                if (!shop.get_que()[i].empty() && shop.get_que()[i].front().dur + shop.get_que()[i].front().start == shop.get_time())
                {
                    shop.leave(i);
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        while (!shop.get_que()[i].empty())
        {
            shop.add_time();
            for (int i = 0; i < m; ++i)
            {
                if (!shop.get_que()[i].empty() && shop.get_que()[i].front().dur + shop.get_que()[i].front().start == shop.get_time())
                {
                    shop.leave(i);
                }
            }
        }
    }
    return 0;
}