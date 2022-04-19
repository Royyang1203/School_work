#include <iostream>
using namespace std;

int binary_search(int *a, int l, int r, int key)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (key == a[mid])
            return a[mid];
        else if (key > a[mid])
            l = mid+1;
        else
            r = mid-1;
    }
    return 0;
}
int main()
{
    int a[] = {2, 3, 4, 10, 15};
    int n = sizeof(a) / sizeof(a[0]);
    cout << binary_search(a, 0, n - 1, 20);
}