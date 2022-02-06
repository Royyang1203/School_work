#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int table[26] = {0};
    char str[200] = {'\0'};

    gets(str);

    for(int i=0; i<strlen(str); i++)
        if( isalpha(str[i]) )
            table[toupper(str[i]) - 'A'] += 1;

    for(int i=0; i<26; i++)
    {
        printf("%c", i + 'A');
      	if( i < 25 )
          	printf(" ");
    }

    printf("\n");
    for(int i=0; i<26; i++)
    {
        printf("%d", table[i]);
      	if( i < 25 )
          	printf(" ");
    }

    return 0;
}
