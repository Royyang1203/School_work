#include <stdio.h>

int main()
{
    float v;
    int t0, t1;
    scanf("%f %d %d", &v, &t0, &t1);
    printf("%.2f", v * (t1 - t0));
    return 0;
}
