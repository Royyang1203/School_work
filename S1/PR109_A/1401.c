#include <stdio.h>
#include <string.h>

char *replace(char *source, char const *pattern, char const *replacement)
{
    static char *ptrSource, *ptr;
    static int i;
    if (source != NULL) {
        ptrSource = source;
        ptr = ptrSource;
        i = 0;
    }
    int n1 = strlen(ptrSource), n2 = strlen(pattern), n3 = strlen(replacement), n = n3 - n2;
    for ( ; *ptr != '\0'; i ++, ptr ++) {
        int b = 1;
        for (int j = 0; j < n2 && b; j ++)
            if (ptr[j] != pattern[j])
                b = 0;
        if (b) {
            if (n < 0)
                for (int j = i; j < n1 - n; j ++)
                    ptrSource[j] = ptrSource[j - n];
            else if (n > 0)
                for (int j = n1; j > i; j --)
                    ptrSource[j + n] = ptrSource[j];
            for (int j = 0; j < n3; j ++)
                ptr[j] = replacement[j];
            ptr += n3;
            n1 += n;
            i += n3;
            break;
        }
    }
    return ptrSource;
}

int main(void)
{
    int  n;
    char arra[500], arrb[20], arrc[20];
    gets(arra);
    gets(arrb);
    gets(arrc);
    replace(arra, arrb, arrc);
    printf("%s\n", arra);
    replace(arra, arrb, arrc);
    printf("%s\n", arra);
    replace(NULL, arrb, arrc);
    printf("%s\n", arra);
    return 0;
}
