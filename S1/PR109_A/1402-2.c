#include <stdio.h>

int main(void)
{
    char arr[10000], *ptr;
    char opd;
    int len, sum, n;
    gets(arr);
    sscanf(ptr = arr, "%d%n", &sum, &len);
    ptr += len;
    while (sscanf(ptr, " %c %d%n", &opd, &n, &len) == 2) {
        switch (opd) {
            case '+' :
                sum += n;
                break;
            case '-' :
                sum -= n;
                break;
            case '*' :
                sum *= n;
                break;
            case '/' :
                sum /= n;
                break;
        }
        ptr += len;
    }
    printf("%d\n", sum);
    return 0;
}
