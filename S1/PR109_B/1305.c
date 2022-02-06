#include <stdio.h>

int main(void)
{
    int a, b = 0, c = 0;
    scanf("%d", &a);
    b =  10 - a % 10;
    a /= 10;
    for (int i = 0; i < 8; i ++) {
        c += (a % 10) * (i + 1);
        a /= 10;
    }
    //printf("%d %d", b, c);
    c %= 10;
    if (b >= c)
        b -= c;
    else
        b = 10 - c + b;
    switch(b) {
        case 0 :
            printf("BNZ");
            break;
        case 1 :
            printf("AMW");
            break;
        case 2 :
            printf("KLY");
            break;
        case 3 :
            printf("JVX");
            break;
        case 4 :
            printf("HU");
            break;
        case 5 :
            printf("GT");
            break;
        case 6 :
            printf("FS");
            break;
        case 7 :
            printf("ER");
            break;
        case 8 :
            printf("DOQ");
            break;
        case 9 :
            printf("CIP");
            break;
    }
    return 0;
}
