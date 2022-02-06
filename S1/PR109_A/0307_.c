// Description

// Read an uppercase character and output corresponded lowercase character.

// 讀入一個大寫字母，並輸出所對應之小寫字母。

// Input
// An uppercase character c.

// 一個大寫字母 c。

// Output
// A lowercase character.

// 一個小寫字母。

// Sample Input 1

// A
// Sample Output 1

// a
// Sample Input 2

// F
// Sample Output 2

// f
#include <stdio.h>
#include <stdlib.h>

main()
{
    char i;
    scanf("%c", &i);
    printf("%c", i + 32);
    return 0;
}
