#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>

int max(int a, int b, int c) { return std::max(std::max(a, b), c); }

int sum(int arr[], std::pair<int, int> tar)
{
    int res = 0;
    for (int i = tar.first; i < tar.second; ++i)
        res += arr[i];
    return res;
}

// Find the maximum possible sum in arr[] auch that arr[m]
// is part of it
std::pair<int, int> maxCrossingSum(int arr[], int left, int mid, int right)
{
    int lindex = mid - 1;
    int sum = arr[mid - 1];
    int left_sum = arr[mid - 1];
    for (int i = mid - 2; i >= left; --i)
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            lindex = i;
            left_sum = sum;
        }
    }

    int rindex = mid;
    sum = arr[mid];
    int right_sum = arr[mid];
    for (int i = mid + 1; i < right; ++i)
    {
        sum += arr[i];
        if (sum > right_sum)
        {
            rindex = i;
            right_sum = sum;
        }
    }
    if (max(left_sum + right_sum, left_sum, right_sum) == left_sum)
        return std::pair<int, int>(lindex, mid);
    if (max(left_sum + right_sum, left_sum, right_sum) == right_sum)
        return std::pair<int, int>(mid, rindex + 1);
    else
        return std::pair<int, int>(lindex, rindex + 1);
}

// Returns sum of maximum sum subarray in aa[l..h]
std::pair<int, int> maxSubArraySum(int arr[], int left, int right)
{
    if (right - left == 1)
        return std::pair<int, int>(left, right);

    // Find middle point
    int mid = (left + right) / 2;

    std::pair<int, int> l = maxSubArraySum(arr, left, mid);
    std::pair<int, int> r = maxSubArraySum(arr, mid, right);
    std::pair<int, int> m = maxCrossingSum(arr, left, mid, right);
    if (max(sum(arr, l), sum(arr, r), sum(arr, m)) == sum(arr, l))
        return l;
    if (max(sum(arr, l), sum(arr, r), sum(arr, m)) == sum(arr, r))
        return r;
    else
        return m;
}

using namespace std;

int main()
{
    int n = 100;
    int arr[n];
    srand(9);
    for (int i = 0; i < n; ++i)
        arr[i] = rand() % 100 - 50;

    // int arr[] = {2, -6, 4, 5, 7};
    // int n = sizeof(arr) / sizeof(arr[0]);
    pair<int, int> res = maxSubArraySum(arr, 0, n);
    cout << "maximum subarray index (" << res.first << ", " << res.second << ")" << endl;
    printf("Maximum contiguous sum is %d\n", sum(arr, res));
    return 0;
}
