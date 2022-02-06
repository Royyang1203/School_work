#include <stdio.h>
#include <stdlib.h>

main()
{
    float a, b;
    scanf("%f%f", &a, &b);
    printf("%f + %f = %.2f\n",a ,b ,a+b);
    printf("%f - %f = %.2f\n",a ,b ,a-b);
    printf("%f * %f = %.2f\n",a ,b ,a*b);
    printf("%f / %f = %.2f\n",a ,b ,a/b);
    return 0;
}
