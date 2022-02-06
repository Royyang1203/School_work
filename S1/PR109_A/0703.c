#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int  s = 0;
    char c[100];
    bool b = true;
    scanf("%s", c);
    int n = strlen(c);
    for (int i = 0; i < n / 2 && b; i++)
        if (abs(c[i] - c[n - i -1]) != 0 && abs(c[i] - c[n - i -1]) != 32)
            b = false;
    if (b)
        printf("%s is a palindrome.", c);
    else
        printf("%s is not a palindrome.", c);
    return 0;
}
