#include <stdio.h>

int main(void)
{
    char c[4];
    scanf("%s", &c);
    for (int i = 3; i >= 0; i --)
        printf("%c", c[i]);
    return 0;
}
