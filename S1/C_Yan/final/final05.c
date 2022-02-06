#include <stdio.h>
#include <string.h>

int main(void)
{
    int n, m[103] = {0};
    scanf("%d", &n);
    fflush(stdin);
    char arr[103][55], *ptr[n];
    for (int i = 0; i < n; i ++) {
        scanf("%s", arr[i]);
        ptr[i] = arr[i];
    }
    for (int i = 0; i < n; i ++) {
        for(int j = 0;  j < strlen(arr[i]); j ++)
        {
            //printf("%d\n", arr[i][j]);
            m[i] += arr[i][j];
            //printf("%d\n", m[i]);
        }
    }
    for(int i = n - 1; i > 0; i --)
        for (int j = 0; j < i; j ++) {
            int a = m[j], b = m[j + 1];
            //printf("%d %d\n", a, b);
            if(a > b) {
                char *t = ptr[j];
                ptr[j] = ptr[j + 1];
                ptr[j + 1] = t;
                int tt = m[j];
                m[j] = m[j + 1];
                m[j +1] = tt;
            }
        }
    for(int i = 0 ;i < n; i ++)
        printf("%s\n", ptr[i]);
    return 0;
}
