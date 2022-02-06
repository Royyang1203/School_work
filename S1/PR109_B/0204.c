#include <stdio.h>

main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (a >= (float)(a + b + c + d) / 4)
        printf("SUCCESS");
    else
        printf("FAILED");
    return 0;
}
