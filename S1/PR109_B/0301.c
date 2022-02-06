#include <stdio.h>

main()
{
    char c[20];
    scanf("%s", &c);
    for (int i = 0; c[i] >= '0' && c[i] <= '9'; i++) {
        for (int j = 0; j < 5; j++) {
            if (c[i] - 48 <= 5 && j < c[i] - 48 || c[i] - 48 > 5 && j + 5 >= c[i] - 48)
                printf(".");
            else
                printf("-");

        }
        printf(" ");
    }
    return 0;
}
