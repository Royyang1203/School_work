#include <stdio.h>
#include <string.h>

int main(void)
{
    char arr[1000];
    scanf("%s", &arr);
    int n = strlen(arr);
    for (int i = 0; i < n; i ++)
        if(arr[i] >= 'C' && arr[i] <= 'Z')
            printf("%c", arr[i] - 2);
        else if (arr[i] == 'A')
            printf("%c", 'Y');
        else if (arr[i] =='B')
            printf("%c", 'Z');
    return 0;
}

