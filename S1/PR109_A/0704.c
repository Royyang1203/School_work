#include <stdio.h>

int main()
{
    int n, m, v, w, q;
    while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0) {
        int a[n + 1];
        q = 1;
        for (int i = 0; i < n + 1; i++)
            a[i] = 0;
        for (int i = 1; i <= m; i++) {
            scanf("%d", &v);
            if (v <= n) {
                a[v]++;
            }
        }
        if (a[1] > 0) {
            q = 0;
            w = 1;
        }
        for (int i = 1; i < n; i++) {
            if (a[w] < a[i + 1]) {
                w = i + 1;
                q = 0;
            }
            else if (w == i && a[i] == a[i + 1])
                q = 1;
        }

        if (q)
            printf("No winner\n");
        else if (a[w] > m / 2)
            printf("Majoritarian winner %d\n", w);
        else
            printf("Plurality winner %d\n", w);
    }
    return 0;
}
