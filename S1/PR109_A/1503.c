#include <stdio.h>

void fun()
{
    char c;
    scanf("%c", &c);
    if (c != '\n')
        fun();
    else
        return;
    printf("%c", c);
    return;
}
int main(void)
{

    fun();
    return 0;
}
