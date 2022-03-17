#include <random>
#include <iostream>

void sort_by_digit(int *A, int n, int r, int p)
{
    int base = 1;
    while (p > 0)
    {
        --p;
        base *= r;
    }
    int count[r], B[n];
    for (int j = 0; j < r; ++j)
        count[j] = 0;
    for (int i = 0; i < n; ++i)
        count[(A[i] / base) % r]++;
    for (int j = 0, psum = 0, sum = 0; j < r; ++j)
    {
        psum = sum;
        sum += count[j];
        count[j] = psum;
    }
    for (int i = 0; i < n; ++i)
        B[count[(A[i] / base) % r]++] = A[i];
    for (int i = 0; i < n; ++i)
        A[i] = B[i];
}

void radix_sort(int *A, int n, int r, int d)
{
    for (int i = 0; i < d; ++i)
        sort_by_digit(A, n, r, i);
}

int binary_search(int *A, int lo, int hi, int key, int e)
{
    if (lo >= hi)
        return -1;
    if ((hi + lo) / 2 == key)
        return (hi + lo) / 2;
    else if ((hi + lo) / 2 > key)
        return binary_search(A, lo, (hi + lo) / 2 - 1, key, e);
    else
        return binary_search(A, (lo + hi) / 2 + 1, hi, key, e);
}

int main()
{
    int n = 200;
    int arr[n];

    for (int i = 0; i < n; ++i)
    {
        arr[i] = std::rand() % 1000;
    }
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    // std::cout << find_minimum_d(arr, n, 2) << std::endl;
    radix_sort(arr, n, 10, 3);
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int k = binary_search(arr, 0, n, 626, 1);
    std::cout << k << std::endl;
}