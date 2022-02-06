#include <stdio.h>

int main(void)
{
    int sum, num;
    scanf("%d", &sum);
    char c;

    while( scanf(" %c ", &c) != EOF )
    {
        scanf("%d", &num);
        if( c == '+' )
            sum += num;
        else if( c == '-' )
            sum -= num;
        else if( c == '*' )
            sum *= num;
        else if( c == '/' )
            sum /= num;
    }
    printf("%d\n", sum);
    return 0;
}

