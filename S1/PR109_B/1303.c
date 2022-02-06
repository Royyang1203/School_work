#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i ++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < n; i ++) {
        int j = 1, s = 0;
        while(i - j >= 0 && arr[i - j] < arr[i]) {
            s += arr[i - j];
            j ++;
        }
        j = 1;
        while (i + j < n && arr[i + j] < arr[i]) {
            s += arr[i + j];
            j ++;
        }
        printf("%d\n", s);
    }
    return 0;
}
