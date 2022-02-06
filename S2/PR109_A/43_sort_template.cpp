// Description

// Design a function "sort" using template.

// template < typename T >

// T *sort(T *array, int n)
// {
// }
// Sort the element in ascending order.

template <typename T>
T *sort(T *array, int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - 1; ++j)
        {
            if (array[j] > array[j + 1])
            {
                T c = array[j];
                array[j] = array[j + 1];
                array[j + 1] = c;
            }
        }
    }
    return array;
}