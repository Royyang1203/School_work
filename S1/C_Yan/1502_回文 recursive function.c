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
void f(char *ptr, int n, int i)
{
    //printf("%d\n", i);
    int k = n / 2;
    if (i > k && *ptr == ptr[n - i - 1])
    {
        printf("Y\n");
        return;
    }
    if (ptr[i] == ptr[n - i - 1])
    {
        f(ptr, n, i + 1);
        return;
    }
    printf("N\n");
    return;
}
int main(void)
{
    char arr[100];
    int n;
    while (scanf("%s", &arr) != EOF)
    {
        n = strlen(arr);
        //printf("!!%d\n", n);
        f(arr, n, 0);
    }
    return 0;
}
