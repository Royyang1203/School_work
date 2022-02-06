// Description

// 摩斯電碼（英語：Morse code）是一種時通時斷的訊號代碼，通過不同的排列順序來表達不同的英文字母、數字和標點符號。是由美國人艾爾菲德·維爾與薩繆爾·摩斯在1836年發明。摩斯電碼是一種早期的數位化通訊形式，但是它不同於現代只使用0和1兩種狀態的二進位代碼。請寫一隻程式，讓使用者輸入一個數字，程式會輸出相對應的摩斯密碼

// Morse code is a character encoding scheme used in telecommunication that encodes text characters as standardized sequences of two different signal durations called dots and dashes or dits and dahs. Morse code is named for Samuel F. B. Morse, an inventor of the telegraph. Write a program allow user input a number and print out corresponding Morse code.

// Input
// 輸入會是一個正整數。

// Input is an integer number.

// Output
// 輸出相對應的摩斯密碼，數字與摩斯密碼的對照如下。

// Print out the corresponding Morse code. Mapping table as follow.

// 0-----

// 1.----

// 2..---

// 3...--

// 4....-

// 5.....

// 6-....

// 7--...

// 8---..

// 9----.

// Sample Input 1

// 0
// Sample Output 1

// −−−−−
// Sample Input 2

// 2095366
// Sample Output 2

// ..--- ----- ----. ..... ...-- -.... -....
#include <stdio.h>

main()
{
    char c[20];
    scanf("%s", &c);
    for (int i = 0; c[i] >= '0' && c[i] <= '9'; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (c[i] - 48 <= 5 && j < c[i] - 48 || c[i] - 48 > 5 && j + 5 >= c[i] - 48)
                printf(".");
            else
                printf("-");
        }
        printf(" ");
    }
    return 0;
}
