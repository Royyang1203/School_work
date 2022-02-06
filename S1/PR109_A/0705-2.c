#include <stdio.h>
#include <math.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        float sum = 0, top = 0, h;
        scanf("%d", &m);
        float arr[m][2];
        for (int j = 0; j < m; j ++)
            scanf("%f%f", &arr[j][0], &arr[j][1]);
        for (int j = 0; j < m - 1; j ++)
            for (int k = 0; k < m - 1; k ++)
                if (arr[k][0] < arr[k + 1][0]) {
                    int t = arr[k][0];
                    arr[k][0] = arr[k + 1][0];
                    arr[k + 1][0] = t;
                    t = arr[k][1];
                    arr[k][1] = arr[k + 1][1];
                    arr[k + 1][1] = t;
                }
        for (int j = 1; j < m; j ++)
            if (arr[j][1] > top) {
                h = arr[j][1] - top;
                sum += pow((pow((arr[j][0] - arr[j - 1][0]) * h / (arr[j][1] - arr[j - 1][1]), 2) + pow(h, 2)), 0.5);
                top = arr[j][1];
            }
        printf("%.2f\n", sum);
    }
    return 0;
}
