#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int get_ans(char *flag)
{
    if(*flag == 'F')
    {
        return 1 + get_ans(flag+2);
    }else if(*flag == 'G'){
        int temp = 0, index = 0;
        while(1)
        {
            if( *(flag + index) == 'G' )
                temp++;
            if( *(flag + index) == ',' )
                temp--;
            if( temp == 0 )
                break;
            index ++;
        }
        return get_ans(flag+2) + get_ans(flag+index+1);
    }else if( isdigit(*flag) ){
        return atoi(flag);
    }
    return 0;
}

int main()
{
    char str[500];
    gets(str);
    printf("%d", get_ans(&str[0]));
}
