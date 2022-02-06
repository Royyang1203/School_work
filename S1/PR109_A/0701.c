#include <stdio.h>

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n <= 6)
        return 0;
    float arr[n], sum = 0;
    for (int i = 0; i < n; i ++)
        scanf("%f", &arr[i]);
    for (int i = 0; i < n - 1; i ++)
        for (int j = 0; j < n - 1; j ++) {
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    for (int i = 3; i < n - 3; i ++) {
        sum += arr[i];
    }
    printf("%.2f", sum / (n - 6));
    return 0;
}
