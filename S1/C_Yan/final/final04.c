#include <stdio.h>

int main(void)
{
    int m[300] = {0}, n, cc = 0;
    scanf("%d", &n);
    char c;
    for(int i = 0; i < n; i ++)
    {
        scanf("%c", &c);
        char a, b;
        scanf("%c%c", &a, &b);

        for(int i = 0; i <= cc; i ++)
        {

            if (m[a] == 0 && m[b] == 0)
            {
                cc ++;
                m[a] = m[b] = cc;
                break;
            }
            else if(m[a] == i && m[b] == 0)
            {
                m[b] = i;
                break;
            }
            else if(m[a] == 0 && m[b] == i)
            {
                m[a] = i;
                break;
            }
            else if(m[a] == i && m[b] != 0)
            {
                int w = m[b];
                for(int j = 'A'; j <= 'Z'; j ++)
                {

                    if(m[j] == w)
                        m[j] = i;
                }
                break;
            }

        }
        for(int j = 'A'; j <= 'Z'; j ++)
        {
            printf("%d ", m[j]);
        }
        printf("\n");
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i ++)
    {
        scanf("%c", &c);
        char a, b;
        scanf("%c%c", &a, &b);
        if(m[a] != 0 && m[b] != 0 && m[a] == m[b])
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}

