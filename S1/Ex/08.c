#include <stdio.h>

int main(void)
{
    char p[1001], q[1001];
    int m;
    scanf("%s", p);
    scanf("%s", q);
    int n = strlen(p);
    int k = strlen(q);
    n = n < k ? n : k;
    for (int i = 0; i < n; i ++) {
        int b = 1;
        for (int j = 0; j < i && b; j ++) {
            if (p[j] != q[k - i - 1 + j]) {
                b = 0;
            }
        }
        if(b)
            m = i + 1;
    }
    if(m == 1 && p[0] != q[n - 1])
        m = 0;
    printf("%d", m);
    return 0;
}
