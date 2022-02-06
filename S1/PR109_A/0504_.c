// Description

// 請寫一程式，輸入一正整數表示正三角形層數 ，並且印出此三角形。

// Please write a program, input a positive integer to represent the number of regular triangle layers, and print this triangle.

// Input
// 一個 [1, 30] 間的正整數。

// A[1, 30] positive integer.

// Output
// 輸出此正三角形。

// 註：

// 1.以 ' * ' 字元表示。

// 2. 每行最後面不能有空白。

// 3. 最後一行後面沒有換行。

// Print this regular triangle。

// Note：

// 1.Expressed in ' * ' character.

// 2.There is no space at the end of each line.

// 3.There is no newline at the end of the last line.

// Sample Input 1

// 5
// Sample Output 1

//     *
//    * *
//   * * *
//  * * * *
// * * * * *
#include <stdio.h>

main()
{
    int a;
    scanf("%d", &a);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < a; j++)
        {
            if (j < a - i - 1)
                printf(" ");
            else if (j < a - 1)
                printf("* ");
            else
                printf("*");
        }
        if (i < a - 1)
            printf("\n");
    }
    return 0;
}