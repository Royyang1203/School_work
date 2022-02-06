#include <stdio.h>
#include <time.h>

int main(void)
{
    int n, m;

    srand(time(NULL));
    scanf("%d", &m);
        for (int i = 0; i < m; i ++) {
            n = rand() % 62;
            if (n >= 0 && n <= 9)
                printf("%d", n);
            else if (n > 9 && n <= 35)
                printf("%c", n + 87);
            else if (n >= 36 && n < 62)
                printf("%c", n + 29);
        }
    return 0;
}
