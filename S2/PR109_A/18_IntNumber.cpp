// Please create a class IntNumber using Digit that you create in Q17 represent a very huge number in integer.

// The class IntNumber can handle an integer number up to 1000 digit and both positive and negative number.

// Create two constructor for this class, one with no parameter and set number to 0, another one with a string type(char * not string) parameter and set number to what the string represent.

// Create a function member display to display the number.

// Sample Input 1

// 123456789123456789
// Sample Output 1

// 123456789123456789
// Sample Input 2

// -100000000000000
// Sample Output 2

// -100000000000000
// Sample Input 3

// 123456Abd
// Sample Output 3

// 123456
// Sample Input 4

// abc123
// Sample Output 4

// 0
// Sample Input 5

// 0000000123
// Sample Output 5

// 123
// Sample Input 6

// +987654
// Sample Output 6

// 987654

#include <cctype>
#include <cstdlib>
#include <iostream>

class Digit
{
private:
    int num;

public:
    Digit()
    {
        num = 0;
    }
    Digit(int a)
    {
        setDigit(a);
    }
    int getDigit() const
    {
        return num;
    }
    void setDigit(int a)
    {
        if (a / 10 == 0)
            num = a;
        else
            num = 0;
    }
    void setDigit(char a)
    {
        int n = a - '0';
        //std::cout << n;
        num = n;
    }
};
class IntNumber
{
private:
    Digit num[1010];
    int n;     //位數
    char sigh; //正負號
public:
    IntNumber()
    {
        n = 1;
        sigh = '+';
    }
    IntNumber(char *cstr)
    {
        setIntNumber(cstr);
    }
    void setIntNumber(char *const cstr)
    {
        n = 0;
        char *ptr = cstr;
        char c = *ptr;
        if (c == '-')
        {
            sigh = '-';
            ptr++;
        }
        else
        {
            sigh = '+';
            if (c == '+')
            {
                ptr++;
            }
        }
        if (!std::isdigit(*ptr)) //無效輸入
        {
            n = 1;
            return;
        }
        while (std::isdigit(*ptr)) //去尾
        {
            n++;
            ptr++;
        }
        ptr--; //回個位數
        int zero = 0;
        for (int i = 0; std::isdigit(*ptr); ++i)
        {
            if (*ptr == '0')
            {
                ++zero;
            }
            else
                zero = 0;
            //std::cout << i << *ptr <<std::endl;//
            //int n = *ptr;
            num[i].setDigit(*ptr);
            ptr--;
            //std::cout << (num[i].getDigit()) << std::endl;//
        }
        n -= zero;
    }
    void display()
    {
        if (sigh == '-' && (n != 1 || num[0].getDigit() != 0))
            std::cout << '-';
        for (int i = n - 1; i >= 0; --i)
        {
            std::cout << (num[i].getDigit());
        }
        //std::cout << (num[1].getDigit());
    }
};

int main()
{
    char num[10000];
    std::cin >> num;
    IntNumber *number = new IntNumber(num);
    number->display();
    return 0;
}