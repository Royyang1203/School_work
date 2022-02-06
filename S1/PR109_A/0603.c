#include <stdio.h>
#include <stdbool.h>

main()
{
    int n;
    int m = 0;
    scanf("%d", &n);
    bool p[n];
    for (int i = 2; i < n; i++)
        p[i] = true;
    for (int i = 2; i <= n; i++) {
        while (!p[i])
            i++;
        for (int j = 2 * i; j <= n; j += i)
            p[j] = false;
    }
    for (int i = 2; i <= n / 2; i++)
        if (p[i] && p[n - i])
            m++;
    printf("%d", m);
    return 0;
}
