#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    int a, i, j;
    scanf("%d", &a);
    for (i = 1; i <= a; i++){
        for (j = 1;j <= i; j++){
            printf("%d\n", j);
        }
    }
    return 0;
}
