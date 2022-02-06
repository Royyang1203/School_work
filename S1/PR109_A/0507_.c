// Description

// 已知一正整數N的平方根介於0到N之間，令N的平方根為x，a=0為下界，b=N為上

// 界。則有不等式a<=x<=b，將不等式平方可以得到a*a<=x*x=N<=b*b，根據二分

// 逼近法計算c = (a+b)/2，當c平方大於等於N時我們將上界更新，得到新的不等式

// a<=x<=c，反之，則更新下界，得到新的不等式c<=x<=b，上界與下界的差稱為誤

// 差。請設計一個程式，由使用者輸入一個正整數，計算出該正整數的平方根，

// 請精準到小數點後四位。

// Given the square root of a positive integer N is between 0 and N, let the square root of N be x, a=0 is the lower bound, and b=N is the upper bound. Then there is the inequality a<=x<=b, square the inequality to get a*a<=x*x=N<=b*b, and let c = (a+b)/2 according to the root approximation through bisection, when square of c is greater than or equal to N, we update the upper bound and get a new inequality a<=x<=c, otherwise, we update the lower bound and get a new inequality c<=x<=b. The difference between the upper and lower bounds is called the error. Please design a program in which the user enters a positive integer and calculates the square root of the positive integer. Please be accurate to four decimal places.

// Input
// 一個整數 n

// An integer n

// Output
// 輸出 n 的平方根到小數點後四位

// Output the root of naccurate to four decimal places.

// Sample Input 1

// 4
// Sample Output 1

// 2.0000
// Sample Input 2

// 2
// Sample Output 2

// 1.4142

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double fun(double a, double b, double n)
{
    double c = (a + b) / 2;
    if (c * c - n >= 0.00001)
    {
        return fun(a, c, n);
        //printf("%d!\n", 6);
    }
    else if (n - c * c >= 0.00001)
    {
        return fun(c, b, n);
        //printf("%d!\n", 7);
    }

    return c;
}

int main()
{
    double n;
    scanf("%lf", &n);
    double a = 0, b = n;
    printf("%.4lf", fun(a, b, n));
    return 0;
}

// #include <stdio.h>

// int main()
// {
//     float n, c, a, b;
//     scanf("%f", &n);
//     a = 0;
//     b = n;
//     c = (a + b) / 2;
//     while ((c * c > n) && (c * c - n) > 0.0001 || (c * c < n) && (c * c - n) < 0.0001)
//     {
//         if (c * c > n)
//             b = c;
//         else
//             a = c;
//         c = (a + b) / 2;
//     }
//     printf("%.4f", c);
//     return 0;
// }
