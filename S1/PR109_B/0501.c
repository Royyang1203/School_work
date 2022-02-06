#include <stdio.h>
#include <math.h>

int main()
{

    int n;
    double s = 0, x = 0;
    scanf("%d", &n);
    double y[n];
    for (int i = 0; i < n; i++)
        scanf("%lf", &y[i]);
    for (int i = 0; i < n; i++)
        s += y[i];
    s /= n;
    for (int i = 0; i < n; i++) {
        x += pow((y[i] - s), 2);
    }
    printf("%.4lf", pow(x / n, 0.5));
    return 0;
}
