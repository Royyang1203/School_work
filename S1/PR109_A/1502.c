#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 1000

int stack[2][MAXSTACK];
char stackchar[MAXSTACK];
int top[3] = {-1, -1, -1};

int isEmpty(int i)
{
    return (top[i] == -1);
}
void pushc(char data)
{
    if (top[2] >= MAXSTACK)
        printf("堆疊已滿,無法再加入\n");
    else
    {
        top[2]++;
        stackchar[top[2]] = data;
    }
}
char popc()
{
    char data;
    if (isEmpty(2))
        printf("堆疊已空\n");
    else
    {
        data = stackchar[top[2]];
        top[2]--;
        return data;
    }
}

void pushd(int data, int i)
{
    if (top[i] >= MAXSTACK)
        printf("堆疊已滿,無法再加入\n");
    else
    {
        top[i]++;
        stack[i][top[i]] = data;
    }
}
int popd(int i)
{
    int data;
    if (isEmpty(i))
        printf("堆疊已空\n");
    else
    {
        data = stack[i][top[i]];
        top[i]--;
        return data;
    }
}

int main()
{
    char c;
    int n = 0;
    while (scanf("%c", &c) != EOF)
    {
        if (c >= '0' && c <= '9')
            pushd(c - '0', 0);
        else
        {
            if (!isEmpty(0))
            {
                int k = 1;
                while (!isEmpty(0))
                {
                    n += popd(0) * k;
                    k *= 10;
                }
                pushd(n, 1);
                n = 0;
            }
            if (c == 'F' || c == 'G')
                pushc(c);
            else if (c == ')')
            {
                c = popc();
                if (c == 'G')
                {
                    int x = popd(1), y = popd(1);
                    x += y;
                    pushd(x, 1);
                }
                else if (c == 'F')
                {
                    int x = popd(1);
                    x++;
                    pushd(x, 1);
                }
            }
        }
        for (int i = 0; i <= top[1]; i++)
            printf("%d ", stack[1][i]);
        printf("\n");
        for (int i = 0; i <= top[2]; i++)
            printf("%c", stackchar[i]);
        printf("\n========\n");
    }
    printf("%d", popd(1));
    return 0;
}
