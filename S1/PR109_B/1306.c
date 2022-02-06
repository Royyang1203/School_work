#include <stdio.h>

int main(void)
{
    long long int m, n, s;
    char c;
    scanf("%lld%lld\n%c", &m, &n, &c);
    long long int arr[m], arrb[n];
    for (int i = 0; i < m; i ++)
        scanf("%lld", &arr[i]);
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (arr[i] % 2)
                arrb[n - j - 1] = 1;
            else
                arrb[n - j - 1] = 0;

            arr[i] /= 2;
        }
        for (int j = 0; j < n; j ++)
            if (arrb[j])
                printf("%c ", c);
            else
                printf(". ");
        printf("\n");
    }
    return 0;
}
