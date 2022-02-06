#include <stdio.h>
#include <stdbool.h>

main()
{
    int s = 0;
    char c;
    bool b;
    while (scanf("%c", &c) != EOF && c != '0') {
        if (c != '\n' && c < '0' || c != '\n' && c > '9')
            continue;
        else if (c >= '0' && c <= '9') {
            s += (c - '0');
            if (c == '9' && !b)
                b = true;
        }
        else if (s != 0) {
            if (s % 9 == 0 && b)
                printf("Nines\n");
            else if (s % 9 == 0 && !b)
                printf("Nines without nines\n");
            else
                printf("Not nines\n");
            s = 0;
            b = false;
        }
    }
    return 0;
}
