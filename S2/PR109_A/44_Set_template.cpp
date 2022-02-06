// Description

// Please re-design the class Set in Q28 Q29.

// Using template make class Set can accept all kink of type

#include <iostream>

template <class T>
class Set
{
private:
    int count = 0;
    T element[100];

public:
    Set() = default;
    Set(Set<T> &a) { *this = a; }
    int add(const T a)
    {
        for (int i = 0; i < count; ++i)
        {
            if (a == element[i])
                return 0;
        }
        element[count++] = a;
        return 1;
    }
    int add(const Set<T> &a)
    {
        int n = 0;
        for (int i = 0; i < a.count; ++i)
        {
            n += add(a.element[i]);
        }
        return n;
    }
    void display()
    {
        int j;
        for (j = 0; j < count; j++)
            std::cout << element[j] << " ";
    }
    Set<T> operator+(const Set<T> &a)
    {
        Set<T> t(*this);
        t.add(a);
        return t;
    }
    Set<T> operator-(const Set<T> &a)
    {
        Set<T> t;
        for (int i = 0; i < count; ++i)
        {
            for (int j = 0; j < a.count; ++j)
            {
                if (element[i] == a.element[j])
                    t.add(element[i]);
            }
        }
        return t;
    }
};
