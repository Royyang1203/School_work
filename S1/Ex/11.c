#include <stdio.h>

int main(void)
{
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        char strT[10000], key[10000];
        scanf("%s", strT);
        int lenT = strlen(strT);
        scanf("%d", &m);
        for (int j = 0; j < m; j ++) {
            int count = 0;
            scanf("%s", key);
            int lenK = strlen(key);
            for (int k = 0; k < lenT; k ++) {
                int b = 1;
                for (int l = 0; l < lenK && b; l ++) {
                    if (strT[k + l] != key[l])
                        b = 0;
                }
                if (b)
                    count ++;
            }
            printf("%d\n", count);
        }
    }
    return 0;
}
