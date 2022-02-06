#include <iostream>
#include <cstdlib>

template <class T>
int *failure_funtion(T *pat, int length)
{
    int *f = new int[length];
    f[0] = -1;
    // int j = 0;
    for (int i = 1; i < length; ++i)
    {
        int j = f[i - 1];
        while (pat[i] != pat[j + 1] && j >= 0)
            j = f[j];
        if (pat[i] == pat[j + 1])
        {
            f[i] = j + 1;
            // ++j;
        }
        else
        {
            f[i] = -1;
        }
    }
    return f;
}

int main()
{
    int p[15] = {1, 1, 2, 3, 1, 1, 1, 2, 3, 1, 1, 2, 3, 1, 1};
    int *f = failure_funtion<int>(p, 15);
    for (int i = 0; i < 15; ++i)
    {
        std::cout << f[i] << " ";
    }
}