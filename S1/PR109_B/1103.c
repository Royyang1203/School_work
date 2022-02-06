#include <stdio.h>

int removeDuplicates(int nums[], int n)
{
    if (n == 0)
        return 0;
    int arr[n];
    for (int i = 0; i < n; i ++)
        arr[i] = 0;
    int k = 1;
    arr[0] = nums[0];
    for (int i = 0; i < n; i ++) {
        int t = 1;
        for (int j = 0; j < k && j < i; j ++)
           if (nums[i] == arr[j]) {
                t = 0;
           }
           else if (j == k - 1 && t) {
                arr[k] = nums[i];
                k ++;
           }
    }

    for (int i = 0; i < n; i ++)
        nums[i] = arr[i];
    return k;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i ++)
        scanf("%d", &arr[i]);
    int k = removeDuplicates(arr, n);
    //printf("%d ", k);
    return 0;
}
