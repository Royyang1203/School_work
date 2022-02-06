#include <stdio.h>
#include <string.h>

char *replaceAll(char *source, char *pattern, char *replacement)
{
    char *ptr = source;
    int n1 = strlen(source), n2 = strlen(pattern), n3 = strlen(replacement), n = n3 - n2;
    for (int i = 0; i < n1; i ++, ptr ++) {
        int b = 1;
        for (int j = 0; j < n2 && b; j ++)
            if (ptr[j] != pattern[j])
                b = 0;
        if (b) {
            if (n < 0)
                for (int j = i; j < n1 - n; j ++)
                    source[j] = source[j - n];
            else if (n > 0)
                for (int j = n1; j > i; j --)
                    source[j + n] = source[j];
            for (int j = 0; j < n3; j ++)
                ptr[j] = replacement[j];
            n1 += n;
        }
    }
    return source;
}
char *replace(char *source, char *pattern, char *replacement)
{
    char *ptr = source;
    int n1 = strlen(source), n2 = strlen(pattern), n3 = strlen(replacement), n = n3 - n2;
    for (int i = 0; i < n1; i ++, ptr ++) {
        int b = 1;
        for (int j = 0; j < n2 && b; j ++)
            if (ptr[j] != pattern[j])
                b = 0;
        if (b) {
            if (n < 0)
                for (int j = i; j < n1 - n; j ++)
                    source[j] = source[j - n];
            else if (n > 0)
                for (int j = n1; j > i; j --)
                    source[j + n] = source[j];
            for (int j = 0; j < n3; j ++)
                ptr[j] = replacement[j];
            break;
        }
    }
    return source;
}

int main(void)
{
    int  n;
    char arra[500], arrb[20], arrc[20];
    gets(arra);
    gets(arrb);
    gets(arrc);
    replace(arra, arrb, arrc);

    printf("%s", arra);
    return 0;
}
