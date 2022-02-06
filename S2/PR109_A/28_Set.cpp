// Description

// Please design a class Set represent the set inmathematics.

// The set contain only integer element.

// Create a default constructor to make the set empty.

// Create a copy constructor.

// Create two function member

// int add(const int );

// int add(const Set );

// to add element into the set and return the number of element added.

#include <iostream>

class Set
{
public:
    Set() = default;
    Set(Set &that)
    {
        this->count = that.count;
        for (int i = 0; i < count; ++i)
        {
            this->element[i] = that.element[i];
        }
    }
    int add(const int num)
    {
        bool b = 1;
        for (int i = 0; i < count; ++i)
        {
            if (element[i] == num)
                b = 0;
        }
        if (b)
        {
            element[count++] = num;
            return 1;
        }
        else
            return 0;
    }
    int add(const Set &that)
    {
        int num = 0;
        for (int i = 0; i < that.count; ++i)
        {
            bool b = 1;
            for (int j = 0; j < count; ++j)
            {
                if (element[j] == that.element[i])
                    b = 0;
            }
            if (b)
            {
                element[count++] = that.element[i];
                ++num;
            }
        }
        return num;
    }
    void display()
    {
        int j;
        for (j = 0; j < count; j++)
            std::cout << element[j] << " ";
    }

private:
    int element[100];
    int count = 0;
};