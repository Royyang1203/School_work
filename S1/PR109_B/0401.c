#include <stdio.h>

main()
{
    int x, s = 0;
    while (scanf("%d", &x) != EOF && x != 0) {
        if (x > 0) {
            s += x;
            printf("%16d%12d", x, s);
        }
        else {
            if (s + x < 0) {
                x = 0;
                printf("%8d%20d", x, s);
            }
            else {
                s += x;
                x = -x;
                printf("%8d%20d", x, s);
            }
        }
        printf("\n");
    }

    return 0;
}
