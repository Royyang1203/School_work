#include <stdio.h>

int main (void)
{
    long long s2 = 0, s1 = 0, n, m;
    char c, arr[10000], *ptr;
    gets(arr);
    sscanf(ptr = arr, "%d%n", &s2, &m);
    ptr += m;
    while (sscanf(ptr, "%c%n", &c, &m) != EOF) {
        ptr += m;
        if (c == '+') {
            s1 += s2;
            sscanf(ptr, "%d%n", &s2, &m);
            ptr += m;
        }
        else if (c == '*') {
            sscanf(ptr, "%d%n", &n, &m);
            ptr += m;
            s2 *= n;
        }
    }
    s1 += s2;
    printf("%d", s1);
    return 0;
}
