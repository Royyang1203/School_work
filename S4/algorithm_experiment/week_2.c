// C program for the implementation
// of MSD Radix Sort using counting sort()
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A utility function to print an array
void print(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}

// A utility function to get the digit
// at index d in a integer
int digit_at(int x, int d)
{
    return (int)(x / pow(10, d - 1)) % 10;
}

// array length
int n;

// function to sort array using
// MSD Radix Sort recursively
void MSD_sort(int *arr, int lo, int hi, int d)
{

    // recursion break condition
    if (hi <= lo || d < 1)
    {
        return;
    }

    int count[10 + 2] = {0};

    // temp is created to easily swap strings in arr[]
    int temp[n];

    // Store occurrences of most significant character
    // from each integer in count[]
    for (int i = lo; i <= hi; i++)
    {
        int c = digit_at(arr[i], d);
        ++count[c];
    }

    // Change count[] so that count[] now contains actual
    //  position of this digits in temp[]
    for (int r = 0; r < 10 + 1; ++r)
        count[r + 1] += count[r];

    // Build the temp
    for (int i = lo; i <= hi; i++)
    {
        int c = digit_at(arr[i], d);
        temp[++count[c]] = arr[i];
    }

    // Copy all integer of temp to arr[], so that arr[] now
    // contains partially sorted integers
    for (int i = lo; i <= hi; i++)
    {
        arr[i] = temp[i - lo];
    }

    // Recursively MSD_sort() on each partially sorted
    // integers set to sort them by their next digit
    for (int r = 0; r < 10; r++)
        MSD_sort(arr, lo + count[r], lo + count[r + 1] - 1,
                 d - 1);
}

// function find the largest integer
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Main function to call MSD_sort
void radixsort(int *arr, int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // get the length of the largest integer
    int d = floor(log10(abs(m))) + 1;

    // function call
    MSD_sort(arr, 0, n - 1, d);
}

// Driver Code
int main()
{
    // Input array
    int arr[] = {9330, 9950, 718, 8977, 6790,
                 95, 9807, 741, 8586, 5710};

    // Size of the array
    n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array : ");

    // Print the unsorted array
    print(arr, n);

    // Function Call
    radixsort(arr, n);

    printf("Sorted array : ");

    // Print the sorted array
    print(arr, n);

    return 0;
}