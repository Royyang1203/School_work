// 內容：
// 判斷輸入的字是否為回文
// 輸入說明：
// one word, 長度小於100
// 輸出說明：
// 如果是回文則輸出Y，不是回文則輸出N

// 範例輸入：
// eye
// radar
// 範例輸出：

// Y
// Y

#include <stdio.h>
#include <string.h>

void Palindrome(char sen[1500], int a)
{
    int L = 0, si, i;
    while (L < a)
    {
        char newsen[1000];
        if (sen[L] == '"')
        {
            L++;
            for (si = 0; sen[L] != '"'; L++)
                if (sen[L] >= 65 && sen[L] <= 92 || sen[L] >= 97 && sen[L] <= 122)
                {
                    if (sen[L] > 64 && sen[L] < 91)
                        sen[L] += 32;
                    newsen[si++] = sen[L];
                }
            int t = 1;
            for (i = 0; i < (si + 1) / 2; i++)
                if (!(newsen[i] == newsen[si - 1 - i]))
                    t = 0;
            if (t)
                printf("Y\n");
            else
                printf("N\n");
        }
        L++;
    }
}

int main()
{
    char sen[1000];
    gets(sen);
    Palindrome(sen, strlen(sen));

    return 0;
}

// ____________________________________________________

// #include <stdio.h>
// #include <ctype.h>
// #include <string.h>

// int main(void)
// {
//     int i = 0, b = 0, j;
//     char c;
//     char arr[1000];
//     while(scanf("%c", &c)) {
//         if (c == '\n')
//             break;
//         if (c == '"')
//             b ++;
//         if (b == 2) {
//             arr[i] = '\0';
//             int n = strlen(arr);
//             //printf("%s %d\n", arr, n);
//             for (j = 0; j < n / 2; j ++) {
//                 if (arr[j] != arr[n - 1 - j]) {
//                     printf("N\n");
//                     break;
//                 }
//                 else if (j == n / 2 - 1) {

//                     printf("Y\n");
//                 }
//             }
//             i = b = 0;
//         }
//         if (isalpha(c)) {
//             c = tolower(c);
//             arr[i] = c;
//             i ++;
//         }
//     }
//     return 0;
// }
