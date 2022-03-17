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

// function to sort array using
// MSD Radix Sort recursively
void radix_sort_MSD_R(int *A, int lo, int hi, int r, int d)
{

    // recursion break condition
    if (hi <= lo || d < 1)
    {
        return;
    }

    int count[r + 2], B[hi - lo];

    for (int i = 0; i < r + 2; ++i)
        count[i] = 0;

    // Store occurrences of most significant character
    // from each integer in count[]
    for (int i = lo; i < hi; ++i)
        ++count[(int)(A[i] / pow(r, d - 1)) % r + 2];

    // Change count[] so that count[] now contains actual
    //  position of this digits in temp[]
    for (int i = 1; i < r + 1; ++i)
        count[i + 1] += count[i];

    for (int i = lo; i < hi; ++i)
    {
        B[count[(int)(A[i] / pow(r, d - 1)) % r + 1]++] = A[i];
    }

    // Copy all integer of temp to arr[], so that arr[] now
    // contains partially sorted integers
    for (int i = lo; i < hi; ++i)
    {
        A[i] = B[i - lo];
    }

    // Recursively MSD_sort() on each partially sorted
    // integers set to sort them by their next digit
    for (int i = 0; i < r; ++i)
        radix_sort_MSD_R(A, lo + count[i], lo + count[i + 1], r, d - 1);
}

// Main function to call MSD_sort
void radix_sort_MSD(int *A, int n, int r, int d)
{
    radix_sort_MSD_R(A, 0, n, r, d);
}

int find_minimum_d(int *A, int n, int r)
{
    // Find the maximum number to know number of digits
    int max = A[0];
    for (int i = 1; i < n; ++i)
        if (A[i] > max)
            max = A[i];

    // get the length of the largest integer
    int d = 0;
    int v = 1;
    while (v <= max)
    {
        v *= r;
        ++d;
    }
    return d;
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
    std::cout << find_minimum_d(arr, n, 2) << std::endl;
    radix_sort_MSD(arr, n, 10, 3);
    for (int i = 0; i < n; ++i)
    {
        std::cout << arr[i] << " ";
    }
}