#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int n, m = 0, l = 0, arr[256] = {0};
    char a;
    scanf("%d", &n);
    while (m <= n) {
        scanf("%c", &a);
        if (a == '\n') {
            m ++;
            continue;
        }
        else if (a >= 'A' && a <= 'Z')
            arr[a] ++;
        else if (a >= 'a' && a <= 'z') {
            a = toupper(a);
            arr[a] ++;
        }
        if (arr[a] > l)
            l = arr[a];
    }
    for (int i = l; i > 0; i --)
        for (int j = 0; j < 256; j ++)
            if (arr[j] == i)
                printf("%c %d\n", j, i);

    return 0;
}
