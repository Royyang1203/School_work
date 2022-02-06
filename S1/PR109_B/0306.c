#include <stdio.h>

main()
{
    int a, b, k, l;
    while (scanf("%d %d", &a, &b) != EOF) {
        if (a < b) {
            k = a;
            l = b;
        }
        else {
            k = a;
            l = b;
            int t = a;
            a = b;
            b = t;
        }
        int m = 0;
        for (int i = a; i <=b; i++) {
            int n = 1;
            int j = i;
            while (j != 1) {
                if (j % 2 == 1)
                    j = 3 * j + 1;
                else
                    j /= 2;
                n++;
            }
            if (n > m)
                m = n;

        }
        printf("%d %d %d\n", k, l, m);
    }
    return 0;
}
