#include <stdio.h>
#include <stdbool.h>
#define Max 30000

main()
{
    bool p[Max];
    for (int i = 2; i <= Max; i++)
        p[i] = true;
    for (int i = 2; i * i <= Max; i++) {
        if(!p[i])
            i++;
        for (int j = 2 * i; j <= Max; j += i)
        p[j] = false;
    }
    int a, b;
    while (scanf("%d %d", &a, &b) != EOF && !(a ==0 && b == 0)) {
        int n = 1;
        for (int i = a; i <= b; i++)
            if (p[i]) {
                printf("%d ", i);
                n = 0;
                break;
            }
        for (int i = b; i >= a; i--)
            if (p[i]) {
                printf("%d\n", i);
            break;
            }
        if (n)
            printf("NONE\n");
    }
    return 0;
}
