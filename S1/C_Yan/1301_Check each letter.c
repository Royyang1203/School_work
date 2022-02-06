// 內容：
// 寫一個檢查各種字元的數目與列印母音的程式。需要計算數目的字元為數字，字母，母音，子音。母音是不分大小寫的a, e, i, o, u。
// 輸入說明：
// 一串字元，每一個題目最後一個字元為'#'，字元總個數不超過100
// 輸出說明：
// 數字，字母，母音，子音的數目，與依序列印母音
// 範例輸入：
// 1 plus 1 equals 2#
// 範例輸出：
// 3
// 10
// 4
// 6
// ueua
// 提示：
// 使用字串陣列char s[100]存母音

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int a = 0, b = 0, e = 0, d = 0, i;
    char arr[100] = {0}, c;
    while (scanf("%c", &c) != EOF)
    {
        if (isdigit(c))
            a++;
        else if (isalpha(c))
        {
            b++;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                arr[e] = c;
                e++;
            }
            else
                d++;
        }
        if (c == '#')
        {
            printf("%d\n%d\n%d\n%d\n", a, b, e, d);
            for (i = 0; i < e; i++)
            {
                printf("%c", arr[i]);
                arr[i] = 0;
            }
            printf("\n");
            a = b = e = d = 0;
        }
    }

    return 0;
}
