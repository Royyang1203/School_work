#include <stdio.h>


int compare(int a, int b)
{
    if (a > b)
        return 1;
    else if (a < b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n, m;
    scanf("%d%d", &n, &m);
    int k = compare(n, m);
    printf("%d\n", k);
    return 0;
}

