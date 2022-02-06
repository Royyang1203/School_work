// Please create a class Decode to encode a string.

// Create a constructor with a string type(string not char *) parameter to construct the object.

// Create a function memberstring decode();return the string after decoding.

// The coding method are the same as Q20.

// You can add any data member or function member you need to the class.
#include <string>
#include <iostream>

class Decode
{
private:
    std::string str;

    void setstr(const std::string &that)
    {
        auto length = that.size();
        length /= 3;
        int temp = 0, n = 0;
        for (char c : that)
        {
            if (n == 0)
                temp += (c - '0') * 10 * 10;
            else if (n == 1)
                temp += (c - '0') * 10;
            else if (n == 2)
                temp += (c - '0');
            ++n;
            if (n == 3)
            {
                str += temp;
                n %= 3;
                temp = 0;
            }
        }
    }

public:
    Decode(const std::string &that)
    {
        setstr(that);
    }

    std::string decode()
    {
        return str;
    }
};

int main()
{
    std::string str;
    std::cin >> str;
    Decode *code = new Decode(str);
    std::cout << code->decode();
    return 0;
}