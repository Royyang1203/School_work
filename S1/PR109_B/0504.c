#include <stdio.h>

int main(void)
{
    char arra[1000], arrb[1000], ch;
    int lena, lenb;
    scanf("%[^\n]%n", &arra, &lena);
    fflush(stdin);
    scanf("%c", &ch);
    fflush(stdin);
    scanf("%[^\n]%n", &arrb, &lenb);
    for (int i = 0; i < lena; i ++)
        if (arra[i] == ch)
            printf("%s", arrb);
        else
            printf("%c", arra[i]);
    return 0;
}
