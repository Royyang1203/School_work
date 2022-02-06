#include <iostream>
#include <cstdlib>

using namespace std;
double Eval0(istream &iss);

double Eval2(istream &iss)
{
    double res = 0;
    if (iss.peek() == '(' && iss.get())
    {
        res = Eval0(iss);
        iss.peek() == ')' && iss.get();
    }
    else
    {
        iss >> res;
    }
    return res;
}

double Eval1(istream &iss)
{
    double res = Eval2(iss);
    while (iss.peek() == '*' || iss.peek() == '/' || iss.peek() == '%')
        (iss.get() == '*') ? (res *= Eval2(iss)) : (res /= Eval2(iss));
    return res;
}

double Eval0(istream &iss)
{
    double res = Eval1(iss);
    while (iss.peek() == '+' || iss.peek() == '-')
        res += (iss.get() == '+') ? Eval1(iss) : -Eval1(iss);
    return res;
}

int main()
{
    cout << Eval0(cin) << endl;
}