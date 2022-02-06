// Description

// Please write a function "excange" with two reference parameter and exchange the value of two.

// Function "exange"should accept any kind of type of variable.

// using template

template <class T>
void exange(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
    return;
}
