#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *mystrcat(char *dest, char *src)
{
    int n = 0;
    char *ptr1 = dest;
    char *ptr2 = src;

    while (*dest != '\0')
        dest ++;
    while (*src != '\0') {
        src ++;
        n ++;
    }

    for (int i = 0; i < n; i ++) {
        *dest = *ptr2;
        dest ++;
        ptr2 ++;
    }
    *dest = '\0';
    //printf("%s\n", ptr1);
    return ptr1;
}

char *mystrncat(char *dest, char *src, int n)
{
    char *ptr3 = dest;
    char *ptr4 = src;
    //printf("%d\n", n);
    while (*dest != '\0')
        dest ++;

    for (int i = 0; i < n; i ++) {
        *dest = *ptr4;
        dest ++;
        ptr4 ++;
    }
    *dest = '\0';
    return ptr3;
}

int main(void)
{
    int n;
    char arra[100], arrb[100];
    scanf("%s", arra);

    scanf("%s", arrb);
    scanf("%d", &n);
    char *arr = mystrcat(arra, arrb);
    //char *eee = mystrncat(arra, arrb, n);
    printf("%s", arr);
    return 0;
}
