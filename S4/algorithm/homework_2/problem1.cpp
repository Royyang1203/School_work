#include <iostream>
#include <cstdio>
#include <algorithm>

int max(int a, int b, int c) { return std::max(std::max(a, b), c); }

// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
int maxCrossingSum(int arr[], int left, int mid, int right)
{
    int sum = arr[mid];
    int left_sum = arr[mid];
    for (int i = mid - 1; i >= left; --i)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = arr[mid + 1];
    int right_sum = arr[mid + 1];
    for (int i = mid + 2; i < right; ++i)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return max(left_sum + right_sum, left_sum, right_sum);
}

// Returns sum of maximum sum subarray in aa[l..h]
int maxSubArraySum(int arr[], int left, int right)
{
    if (right - left == 1)
        return arr[left];

    // Find middle point
    int mid = (left + right) / 2;

    return max(maxSubArraySum(arr, left, mid),
               maxSubArraySum(arr, mid, right),
               maxCrossingSum(arr, left, mid, right));
}

using namespace std;

int main()
{
    // int n = 100;
    // int arr[n];
    // srand(7);
    // for (int i = 0; i < n; ++i)
    //     arr[i] = rand() % 100 - 50;

    int arr[] = {2, -6, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSubArraySum(arr, 0, n);
    printf("Maximum contiguous sum is %d\n", max_sum);
    return 0;
}
