// 內容：

// 判斷輸入的句子是否為回文，請注意字母不分大小寫，標點符號忽略之。

// 輸入說明：

// 本題目輸入只有一行，包含數個句子，每個句子以"括住。
// 所有句子長度總合小於1000

// 輸出說明：

// 對於每一句子，
// 如果是回文，輸出Y。
// 如果不是，輸出N

// 範例輸入：

// "Mr. Owl ate my metal worm.""This is a bug."

// 範例輸出：

// Y
// N

// 提示：

// 先將輸入過濾(isalpha)並轉換成分段的小寫字母(tolower)
// E.g.: mrowlatemymetalworm thisisabug C 語言中的特殊字元，通常以反斜線 \ 開頭：
// '\0' 空字元，用於字串的結束 '\n' New Line，換行符號 '\r' Carriage Return，
// 回歸鍵(即 Enter 鍵) '\t' Tab，跳格 '\b' Backspace，倒退鍵 '\a' Bell，嗶一聲 '\\' 反斜線 \ '\'' 單引號 ' '\"' 雙引號 "

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