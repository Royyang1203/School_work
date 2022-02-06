#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

main()
{
    int a, n, j, i, m, sum, o, p, l;
    int b = 1;
    sum = 0;
    int s[10];
    n = 1;
    while (scanf("%d", &a) == 1){
    j = a;
    sum = 0;
    n = 1;
    b = 1;
    for (i = 2; i * i <= a; i++){
        if (a % i == 0)
            b = 0;
    }
    if (b == 1){

        while (a / 10 != 0){ //find the digit of 'a'
            n++; //n = the digit of 'a'
            a = a / 10;
        }
        for (o = 1; o <= n; o++){
            int p = pow(10,(n - o + 1));
            s[o] = (j % p)/ pow(10, n - o);
        }
        for (p = 1; p <= n; p++){
            int w = pow(10, n - p);
            s[n - p +1] = (w * s[n - p +1]);
            sum = sum + s[n - p +1];
            l = sum;
        }

        }
        for (i = 2; i * i <= sum; i++){
            if (sum % i == 0)
                b = 2;
        }
        if (l == j){
            b = 2;
    }

    if (b == 0)
        printf("%d is not prime.", j);
    else if (b == 2)
        printf("%d is prime.", j);
    else
        printf("%d is emirp.", j);
    printf("\n");
    }
    return 0;
}

