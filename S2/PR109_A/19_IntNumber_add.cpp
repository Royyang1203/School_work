// Base on the classIntNumberyou create in Q18, add a function memberaddtoIntNumber.

// The definition of function add is

// IntNumber *add(const IntNumber *) const;

// It will return the summation of twoIntNumbers.
#include <iostream>
#include <cctype>

using namespace std;

class IntNumber;

class Digit
{
private:
    int n = 0;

public:
    friend IntNumber;

    Digit() = default;
    Digit(int _n)
    {
        setDigit(_n);
    }
    void setDigit(int v)
    {
        n = v >= 0 && v < 10 ? v : 0;
    }
    int getDigit()
    {
        return n;
    }
};

class IntNumber
{
private:
    Digit num[1010];
    bool sign = true;
    int len = 0;
    void removeZero()
    {
        while (len > 0 && num[len - 1].n == 0)
            --len;
        if (len == 0)
            sign = true;
    }
    bool largerThan(const IntNumber &that) const
    {
        if (this->len != that.len)
            return this->len > that.len;
        for (int i = len - 1; i >= 0; --i)
            if (this->num[i].n != that.num[i].n)
                return this->num[i].n > that.num[i].n;
        return false;
    }

public:
    IntNumber() = default;
    IntNumber(const std::string &that) : sign(true), len(0)
    {
        int n = 0;
        if (that[n] == '-' || that[n] == '+')
        {
            if (that[n] == '-')
                sign = false;
            ++n;
        }
        while (n < that.length() && isdigit(that[n]))
        {
            ++len;
            ++n;
        }
        for (int i = 0; i < len; ++i)
        {
            num[i].n = that[--n] - '0';
        }
        removeZero();
    }
    void display() const
    {
        if (len == 0)
            std::cout << 0;
        if (sign == false)
            std::cout << '-';
        for (int i = len - 1; i >= 0; --i)
        {
            std::cout << num[i].n;
        }
    }
    IntNumber *add(const IntNumber *that) const
    {
        if (that->largerThan(*this))
            return that->add(this);
        IntNumber *v = new IntNumber(*this);
        if (v->sign == that->sign)
        {
            int carry = 0;
            for (int i = 0; i < v->len || i < that->len; ++i)
            {
                carry += v->num[i].n + that->num[i].n;
                v->num[i].n = carry % 10;
                carry /= 10;
            }
            v->len = v->len > that->len ? v->len : that->len;
            if (carry)
                v->num[v->len++].n = carry;
        }
        else
        {
            for (int i = that->len - 1; i >= 0; --i)
            {
                int sum = v->num[i].n - that->num[i].n;
                if (sum < 0)
                {
                    sum += 10;
                    int j = i + 1;
                    while (v->num[j].n == 0)
                    {
                        v->num[j++].n = 9;
                    }
                    v->num[j].n -= 1;
                }
                v->num[i].n = sum;
            }
            v->removeZero();
        }
        return v;
    }
};
int main()
{
    char num1[10000], num2[10000];
    cin >> num1 >> num2;
    IntNumber *number1 = new IntNumber(num1);
    IntNumber *number2 = new IntNumber(num2);
    number1->display();
    cout << endl;
    number2->display();
    cout << endl;
    number1->add(number2)->display();
    cout << endl;
    number2->add(number1)->display();
    return 0;
}

// #include <cctype>
// #include <cstdlib>
// #include <iostream>

// class Digit
// {
// private:
//     int num;

// public:
//     Digit()
//     {
//         num = 0;
//     }
//     Digit(int a)
//     {
//         setDigit(a);
//     }

//     int getDigit() const
//     {
//         return num;
//     }

//     void setDigit(int a)
//     {
//         if (a / 10 == 0)
//             num = a;
//         else
//             num = 0;
//     }
//     void setDigit(char a)
//     {
//         int n = a - '0';
//         num = n;
//     }
//     void operator=(const int n)
//     {
//         setDigit(n);
//     }
// };

// class IntNumber
// {
// private:
//     Digit num[10100];
//     int numberOfDigit; //位數
//     bool sign;         //正負號，1為正

//     //  讀入字串，去除不合字元，找位數、正負號、並將數字反向放入num
//     //  個位數字放[0]、十位放[1] ...
//     void setIntNumber(char *ptr)
//     {
//         //解決正負號
//         sign = 1;
//         numberOfDigit = 0;
//         char c = *ptr;
//         if (c == '+')
//             ++ptr;
//         else if (c == '-')
//         {
//             sign = 0;
//             ++ptr;
//         }
//         //找個位數位置，位數
//         while (std::isdigit(*ptr))
//         {
//             numberOfDigit++;
//             ptr++;
//         }
//         ptr--; //回個位數
//         //複製數值
//         for (int i = 0; i < numberOfDigit; ++i, --ptr)
//         {
//             num[i].setDigit(*ptr);
//         }
//         removeLeadingZero();                              //去多餘的零
//         if (numberOfDigit == 1 && num[0].getDigit() == 0) //設定 0
//         {
//             sign = 1;
//         }
//     }

//     void copy(const IntNumber &that)
//     {
//         sign = that.sign;
//         numberOfDigit = that.numberOfDigit;
//         for (int i = 0; i < numberOfDigit; ++i)
//             num[i] = that.num[i];
//     }

//     //  remove the leading zero until tens
//     void removeLeadingZero()
//     {
//         auto *ptr = &num[numberOfDigit - 1];
//         while (ptr->getDigit() == 0 && numberOfDigit > 1)
//         {
//             --numberOfDigit;
//             --ptr;
//         }
//     }

// public:
//     IntNumber()
//     {

//         numberOfDigit = 1;
//         sign = 1;
//     }
//     IntNumber(char *cstr)
//     {
//         setIntNumber(cstr);
//     }
//     IntNumber(IntNumber &that)
//     {
//         copy(that);
//     }

//     void display()
//     {
//         if (sign == 0)
//             std::cout << '-';
//         for (int i = numberOfDigit - 1; i >= 0; --i)
//             std::cout << num[i].getDigit();
//     }

//     IntNumber &operator=(const IntNumber &that)
//     {
//         if (*this != that)
//             copy(that);
//         return *this;
//     }
//     bool operator==(const IntNumber &that) const
//     {
//         if (this->numberOfDigit != that.numberOfDigit)
//             return false;
//         if (this->sign != that.sign)
//             return false;
//         for (int i = numberOfDigit - 1; i >= 0; --i)
//         {
//             if (this->num[i].getDigit() != that.num[i].getDigit())
//                 return false;
//         }
//         return true;
//     }
//     bool operator!=(const IntNumber &that) const
//     {
//         return !(*this == that);
//     }
//     bool operator>(const IntNumber &that) const
//     {
//         if (this->numberOfDigit != that.numberOfDigit || this->sign != that.sign)
//             return this->numberOfDigit * (this->sign - 0.5) > that.numberOfDigit * (that.sign - 0.5);
//         for (int i = numberOfDigit - 1; i >= 0; --i)
//         {
//             if (this->num[i].getDigit() > that.num[i].getDigit())
//                 return true;
//             else if (this->num[i].getDigit() < that.num[i].getDigit())
//                 return false;
//         }
//         return false;
//     }
//     bool operator>=(const IntNumber &that) const
//     {
//         return !(that > *this);
//     }
//     bool operator<(const IntNumber &that) const
//     {
//         return that > *this;
//     }
//     bool operator<=(const IntNumber &that) const
//     {
//         return !(*this > that);
//     }

//     //  view both IntNumber as positive, keeps going until bigger than both IntNumber's #numberOfDigit
//     void addNumber(const IntNumber &that)
//     {
//         IntNumber temp(*this);
//         temp.sign = this->sign;
//         temp.numberOfDigit = (this->numberOfDigit > that.numberOfDigit) ? this->numberOfDigit : that.numberOfDigit;
//         bool carry = 0;
//         for (int i = 0; i <= temp.numberOfDigit; ++i)
//         {
//             temp.num[i] = (this->num[i].getDigit() + that.num[i].getDigit() + carry) % 10;
//             carry = ((this->num[i].getDigit() + that.num[i].getDigit() + carry) >= 10);
//         }
//         if (temp.num[temp.numberOfDigit].getDigit() != 0)
//             ++temp.numberOfDigit;
//         copy(temp);
//     }

//     //  view both IntNumber as positive, use the bigger one to subtract the other one,
//     //  keeps going until equal to both IntNumber's #numberOfDigit
//     void subtractNumber(const IntNumber &that)
//     {
//         bool carry = false;
//         numberOfDigit = (this->numberOfDigit > that.numberOfDigit) ? this->numberOfDigit : that.numberOfDigit;
//         if (*this > that)
//         {
//             for (int i = 0; i < numberOfDigit; ++i)
//             {
//                 int temp = this->num[i].getDigit() - that.num[i].getDigit() - carry;
//                 this->num[i] = (temp >= 0) ? temp : temp + 10;
//                 carry = temp < 0;
//             }
//         }
//         else
//         {
//             for (int i = 0; i < numberOfDigit; ++i)
//             {
//                 int temp = that.num[i].getDigit() - this->num[i].getDigit() - carry;
//                 this->num[i] = (temp < 0) ? temp + 10 : temp;
//                 carry = temp < 0;
//             }
//         }
//         removeLeadingZero();
//     }

//     IntNumber &operator+=(IntNumber &that)
//     {

//         if (this->sign && that.sign)
//             addNumber(that);
//         else if (this->sign && !that.sign)
//         {
//             IntNumber temp(that);
//             temp.sign = true;
//             bool t = (*this >= temp) ? true : false;
//             subtractNumber(temp);
//             sign = t;
//         }
//         else if (!this->sign && that.sign)
//         {
//             this->sign = true;
//             bool t = (*this <= that) ? true : false;
//             subtractNumber(that);
//             sign = t;
//         }
//         else
//         {
//             sign = false;
//             addNumber(that);
//         }
//         removeLeadingZero();
//         return *this;
//     }

//     IntNumber *add(IntNumber *that)
//     {
//         static IntNumber resultNumber;
//         IntNumber temp(*this);
//         temp += *that;
//         resultNumber = temp;
//         return &resultNumber;
//         /*
//             static IntNumber resultNumber;
//             resultNumber = *this;
//             resultNumber += *that;
//             return &resultNumber;
//          */
//     }
// };

// int main()
// {
//     char num1[10000], num2[10000];
//     std::cin >> num1 >> num2;
//     IntNumber *number1 = new IntNumber(num1);
//     IntNumber *number2 = new IntNumber(num2);
//     number1->display();
//     std::cout << std::endl;
//     number2->display();
//     std::cout << std::endl;
//     number1->add(number2)->display();
//     std::cout << std::endl;
//     number2->add(number1)->display();
//     std::cout << std::endl;

//     return 0;
// }