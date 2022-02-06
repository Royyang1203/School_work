// Input n, and output n!

// You should use function for the computation of n!.
// Input:
// 5
// Output:
// 120

#include <stdio.h>

int f(int n)
{
    if (n == 1)
        return 1;
    return n * f(n - 1);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    return 0;
}