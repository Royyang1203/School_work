#include<stdio.h>

int C(int Cn, int Ck)
{
    int CN = 1, CK = 1, CM = 1;
    for (int i = 0; i < Cn; i++)
        CN *= (i + 1);
    for (int i = 0; i < Cn - Ck; i++)
        CM *= (i + 1);
    for (int i = 0; i < Ck; i++)
        CK *= (i + 1);
    return CN / (CK * CM);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("1 \n");
    for (int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= i; j++)
            printf("%d ", C(i, j));
        printf("\n");
    }
    return 0;
}
