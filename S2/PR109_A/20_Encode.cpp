// Please create a class Encode to encode a string.

// Create a constructor with a string type(string not char *) parameter to construct the object.

// Create a function memberstring encode();return the string after encoding.

// For a string like "Hello World!", we first convert it to integer, so 'H' become 72, 'e' become 101, 'l' become 108 and so on.

// "Hello World!" become 72, 101, 108, 108, 111, 32, 87, 111, 114, 108, 100, 33

// We pad '0' in the front if the integer is less than 3 digit.

// 072, 101, 108, 108, 111, 032, 087, 111, 114, 108, 100, 033

// "Hello World!" after encode become "072101108108111032087111114108100033"

// You can add any data member or function member you need to the class.

#include <string>
#include <iostream>

class Encode
{
private:
    std::string str;

    void setstr(const std::string &that)
    {
        for (char c : that)
        {
            char temp[5];
            temp[3] = '\0';
            temp[2] = (c % 10) + '0';
            c /= 10;
            temp[1] = (c % 10) + '0';
            c /= 10;
            temp[0] = (c % 10) + '0';
            str += temp;
        }
    }

public:
    Encode(const std::string &that)
    {
        setstr(that);
    }

    std::string encode()
    {
        return str;
    }
};

int main()
{
    std::string str;
    std::getline(std::cin, str);
    Encode *code = new Encode(str);
    std::cout << code->encode();
    return 0;
}