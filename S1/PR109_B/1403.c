#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[100] = {'\0'};

    while(scanf("%s", str) != EOF)
    {
        int count = 0;
        if( strlen(str) >= 8 )
            count ++;

        int islow = 0, isup = 0, isnum = 0, issym = 0;
        for(int i=0; i<strlen(str); i++)
        {
            if( islower(str[i]) )
                islow = 1;
            else if( isupper(str[i]) )
                isup = 1;
            else if( isdigit(str[i]) )
                isnum = 1;
            else
                issym = 1;
        }

        if( islow && isup )
            count ++;
        if( (islow || isup) && (issym || isnum))
            count ++;

        if( count == 3 )
            printf("This password is STRONG\n");
        else if( count == 2 )
            printf("This password is GOOD\n");
        else if( count == 1)
            printf("This password is ACCEPTABLE\n");
        else
            printf("This password is WEAK\n");
    }

    return 0;
}
