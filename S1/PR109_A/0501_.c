// Description

// 請寫一個程式要求使用者不斷地輸入正整數，直到輸入 0 為止，將所有輸入的正整數相加並輸出。

// Please write a program that can keep read in integer until 0, sum up all integer and print out the result.

// Input
// 一連串的正整數，直到 0 為止。

// Input consist several integer until 0.

// Output
// 所有正整數的和

// sum of all integer

// Sample Input 1

// 1
// 2
// 3
// 4
// 0
// Sample Output 1

// 10

#include <stdio.h>

int main()
{
    int s = 0, n;
    while (scanf("%d", &n) != EOF && n != 0)
        s += n;
    printf("%d", s);
    return 0;
}