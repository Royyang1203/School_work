#include <stdio.h>
#include <stdbool.h>

main()
{
    int n = 1, m;
    char c[1000];
    while (gets(c) != EOF && c[0] != '0') {
        if (c[0] >= '0' && c[0] <= '9') {
            m = 0;
            bool b = false;
            for (int i = 0; i < 100 && c[i] >= '0' && c[i] <= '9'; i++) {
                m += (c[i] - '0');
                if (c[i] == '9' && !b)
                    b = true;
                }
            if (m % 9 == 0 && b)
                printf("Nines");
            else if (m % 9 == 0 && !b)
                printf("Nines without nines");
            else
                printf("Not nines");
            printf("\n");
        }
    }
    return 0;
}
