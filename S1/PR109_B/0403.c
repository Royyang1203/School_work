#include <stdio.h>

main()
{
    int x, m, n, k, l = 1;
    scanf("%d %d %d", &x, &m, &n);
    if (m <= n && m < x)
        printf("-1");
    else {
        k = m;
        while (k < x) {
            k -= n;
            k += m;
            l++;
        }
        printf("%d", l);
    }
    return 0;
}
