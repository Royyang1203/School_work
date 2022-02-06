#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

typedef struct date{
    int c;
    int b;
} Date;

typedef struct complex {
    int real;
    char arr[10];
    int imag;
    Date birth;
} Complex;

int main(void)
{
    Complex a;
    Complex *ptr = &a;
    scanf("%d", &a.real);
    printf("%d\n", ptr->real);
    //scanf("%d", &a.birth.c);
    //printf("%d", a.birth.c);
    //unsigned long n = 3445;
    //printf("%d", sizeof(n));
    return 0;
}

