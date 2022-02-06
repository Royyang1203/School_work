// Given an arithmetic expression which main contain operators ('+', '-', '*', '/', '%','(', ')'))
// and operands (integer numbers), please write a program to evaluate the result of this expression.

// E.g.

// Input expression: 10-(2+30)/2/8

// Evaluated result: 8

// Input expression: ((1331/11)%10+2)*5

// Evaluated result: 15
#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>
#include <string>

using namespace std;

class A
{
public:
    virtual int is()
    {
        return 0;
    }
    virtual char get_char()
    {
        char c = '0';
        return c;
    }
    virtual int get_int()
    {
        int n = 0;
        return n;
    }
};
class Number : public A
{
public:
    int n;
    Number(int _n) : n(_n) {}
    int get_int()
    {
        return n;
    }
    int is()
    {
        return 1;
    }
};
class Character : public A
{
public:
    char a;
    Character(char _a) : a(_a) {}
    char get_char()
    {
        return a;
    }
    int is()
    {
        return 2;
    }
};

int main()
{
    stack<Character *> sta;
    queue<A *> que;
    string ss;
    cin >> ss;
    int i = 0;
    int num = 0;
    bool bb = 0;
    while (ss[i] != '\0')
    {

        if (ss[i] >= '0' && ss[i] <= '9')
            num = num * 10 + ss[i] - '0';
        else if (ss[i] == '(')
        {
            sta.push(new Character('('));
        }
        else if (ss[i] == '*' || ss[i] == '/' || ss[i] == '%')
        {
            if (!bb)
            {
                que.push(new Number(num));
                num = 0;
            }
            bb = 0;
            if (!sta.empty() && (sta.top()->get_char() == '*' || sta.top()->get_char() == '/' || sta.top()->get_char() == '%'))
            {
                A *ptr = sta.top();
                sta.pop();
                que.push(ptr);
            }
            sta.push(new Character(ss[i]));
        }
        else if (ss[i] == '+' || ss[i] == '-')
        {
            // cout << "+++---" << endl;
            if (!bb)
            {
                que.push(new Number(num));
                num = 0;
            }
            bb = 0;
            if (!sta.empty() && sta.top()->get_char() != '(')
            {
                A *ptr = sta.top();
                sta.pop();
                que.push(ptr);
            }
            sta.push(new Character(ss[i]));
        }
        else if (ss[i] == ')')
        {
            if (!bb)
            {
                que.push(new Number(num));
                num = 0;
            }
            bb = 1;

            while (sta.top()->get_char() != '(')
            {
                A *ptr = sta.top();
                sta.pop();
                que.push(ptr);
            }
            sta.pop();
        }
        ++i;
    }

    que.push(new Number(num));
    while (!sta.empty())
    {
        A *ptr = sta.top();
        sta.pop();
        que.push(ptr);
    }
    stack<int> stk;
    while (!que.empty())
    {
        if (que.front()->is() == 1)
            stk.push(que.front()->get_int());
        else
        {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            if (que.front()->get_char() == '+')
            {
                a += b;
            }
            else if (que.front()->get_char() == '-')
            {
                a -= b;
            }
            else if (que.front()->get_char() == '*')
            {
                a *= b;
            }
            else if (que.front()->get_char() == '/')
            {
                a /= b;
            }
            else if (que.front()->get_char() == '%')
            {
                a %= b;
            }
            stk.push(a);
        }
        que.pop();
    }
    cout << stk.top() << endl;
    return 0;
}