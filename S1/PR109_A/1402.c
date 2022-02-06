#include <stdio.h>

int main(void)
{
    int n, m;
    char c;
    scanf("%d", &n);
    while (scanf(" %c %d", &c, &m) != EOF) {
        switch(c) {
            case '+':
                n += m;
                break;
            case '-':
                n -= m;
                break;
            case '*':
                n *= m;
                break;
            case '/':
                n /= m;
                break;
        }
    }
    printf("%d", n);
    return 0;
}
