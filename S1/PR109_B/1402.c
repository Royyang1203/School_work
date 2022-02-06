#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[300] = {'\0'};

    while(scanf("%s", str) != EOF)
    {
        int count = 0, flag = 0;
        for(int i=0; i<strlen(str); i++)
        {
            if( isalpha(str[i]) )
            {
                count += tolower(str[i]) - 'a' + 1;
            }else{
                flag = 1;
                break;
            }
        }
        if( !flag )
            printf("%d\n", count);
        else
            printf("Fail\n");
    }
    return 0;
}
