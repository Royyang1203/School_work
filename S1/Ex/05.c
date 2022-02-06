#include <stdio.h>
#include <string.h>

int main(void)
{
    int m = 0, k = 0;
    char arr[1005];
    scanf("%s", arr);
    int n = strlen(arr);
    for (int i = 0; i < n; i ++) {
        if (arr[i] != 'F')
            m = 0;
        else if (arr[i] == 'F')
            m ++;
        if (m > k)
            k = m;
    }
    printf("%d\n", k);
    return 0;
}
