// Please create a class Digit represent a single digit in base ten.

// Class Digit should contain two constructor, one with no parameter and set digit to 0, another one with one integer parameter and use the parameter to set the digit.

// Create two function member setDigit and getDigit to set and get the digit int integer type. You should set digit to 0 if setDigit receive a unreasonable parameter.

// Constructor may also get unreasonable parameter too.
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
        num = n;
    }
    void operator=(const int n)
    {
        setDigit(n);
    }
    void operator=(const Digit n)
    {
        setDigit(n.getDigit());
    }
};