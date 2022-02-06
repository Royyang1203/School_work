// 請讀取Testdata檔，排序後存在Result.txt檔案裏面
// 請上傳您的程式碼與Result.txt

#include <stdio.h>
#include <assert.h>

int main(void)
{
    FILE *fptr1 = fopen("Testdata.txt", "r");
    assert(fptr1 != NULL);
    int n[10000], i = 0, s = 0;
    while (fscanf(fptr1, "%d", &n[i]) != EOF)
    {
        i++;
        s += n[i];
    }
    fclose(fptr1);
    for (int j = i - 1; j > 0; j--)
        for (int k = 0; k < j; k++)
        {
            if (n[k] > n[k + 1])
            {
                int t = n[k];
                n[k] = n[k + 1];
                n[k + 1] = t;
            }
        }
    FILE *fptr2 = fopen("result.txt", "w");
    for (int j = 0; j < i; j++)
    {
        fprintf(fptr2, "%d\n", n[j]);
    }
    fclose(fptr2);
    return 0;
}
