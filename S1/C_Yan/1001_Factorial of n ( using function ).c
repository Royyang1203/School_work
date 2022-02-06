// Input n, and output n!
// You should use function for the computation of n!.
// Input:
// 5
// Output:
// 120

#include <stdio.h>

int fun(int n)
{
    int s, i;
    for (s = i = 1; i <= n; i++)
        s *= i;
    return s;
}

int main(void)
{
    int n, m;
    scanf("%d", &n);
    m = fun(n);
    printf("%d", m);
    return 0;
}