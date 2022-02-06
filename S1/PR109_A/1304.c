#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    char ch[1000];
    gets(ch);
    int count = 0, len = strlen(ch) - 1;
    for (int i = len; i >= 0; i --)
    {
        if (ch[i] != ' ')
            count ++;
        else
        {
            for (int j = 1; j <= count; j ++)
            {
                printf("%c", ch[i + j]);
            }
            printf(" ");
            count = 0;
        }
    }
    count = 0;
    while (isalpha(ch[count]) )
    {
        printf("%c", ch[count]);
        count ++;
    }

    return 0;
}
