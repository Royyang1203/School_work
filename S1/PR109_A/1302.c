#include <stdio.h>

char *trim(char *dest)
{
    int n = 0;
    char *ptr = dest;
    while (*ptr != '\0') {
        ptr ++;
        n ++;
    }
    do {
        ptr --;
    } while (!isalpha(*ptr));
    ptr ++;
    *ptr = '\0';
    while (!isalpha(*dest))
        dest ++;
    return dest;
}

int main(void)
{
    char arr[1000];
    gets(arr);
    char *ptr = trim(arr);
    return 0;
}
