#include <stdio.h>
/*
G(1,G(F(3),F(F(F(93)))))
*/
char p;
int at = 0, bt = 0, t = 0, c1, total = 0;
int a[100] = {0}, b[100] = {0}, c[100] = {0}, d[100] = {0};
int countF()
{
    printf("進入F\n");
    while (scanf("%c", &p) != EOF)
    {
        if (p == 'F')
        {
            printf("F又是F\n");
            return countF() + 1;
        }
        else if (p == 'G')
        {
            printf("F又是G\n");
            return countG() + 1;
        }
        else if (p >= '0' && p <= '9')
        {
            printf("計算X+1=");
            c1 = p - '0';
            while (1)
            {
                scanf("%c", &p);
                if (p >= '0' && p <= '9')
                {
                    c1 = c1 * 10 + (p - '0');
                }
                else
                {
                    break;
                }
            }
            printf("%d\n", c1);
            return c1 + 1;
        }
    }
}
int countG()
{
    printf("進入G\n");
    t = 0;
    if (c[at] == 1)
        at++;
    while (scanf("%c", &p) != EOF)
    {
        if (p == ',')
        {
            t = 1;
        }
        else if (p == 'F')
        {
            if (t == 0)
            {
                a[at] = countF(), c[at] = 1, t = 1;
            }
            else if (t == 1)
            {
                b[bt] = countF(), d[bt] = 1, t = 0;
            }
            //printf("G又是F\n");
            // printf("得到第一個數=%d\n",a[at-1]);
        }
        /*else if(p=='F'&& d[bt] == 0)
        {
            printf("G又是F\n");
            b[bt]= countF(),t=2,d[bt]=1;
            bt++;
            printf("得到第二個數=%d\n",b[bt-1]);
        }*/
        else if (p == 'G')
        {
            printf("G又是G\n");
            if (t == 0)
            {
                a[at] = countG();
                t = 1, at++;
            }
            else if (t == 1)
            {
                b[bt] = countG();
                t = 2, bt++;
            }
        }
        else if (p >= '0' && p <= '9' && t == 0)
        {
            a[at] = p - '0', t = 1;
            while (1)
            {
                scanf("%c", &p);
                if (p >= '0' && p <= '9')
                {
                    a[at] = a[at] * 10 + (p - '0');
                }
                else
                {
                    break;
                }
            }
            printf("得到第一個數=%d\n", a[at - 1]);
        }
        else if (p >= '0' && p <= '9' && t == 1)
        {
            t = 2, b[bt] = p - '0';
            while (1)
            {
                scanf("%c", &p);
                if (p >= '0' && p <= '9')
                {
                    b[bt] = b[bt] * 10 + (p - '0');
                }
                else
                {
                    break;
                }
            }
            printf("得到第二個數=%d\n", b[bt - 1]);
        }
        if (t == 2)
        {
            printf("得到G的結果:%d\n", a[at] + b[bt]);
            t = 0, c1 = a[at] + b[bt], c[at] = 0, d[bt] = 0;
            bt--, at--;
            return c1;
        }
    }
}
int main() // 2 5 8
{
    while (scanf("%c", &p) != EOF)
    {
        if (p == 'F')
        {
            total = countF();
        }
        else if (p == 'G')
        {
            total = countG();
        }
        else if (p >= '0' && p <= '9')
        {
            total = p - '0';
            while (1)
            {
                scanf("%c", &p);
                if (p >= '0' && p <= '9')
                {
                    total = total * 10 + (p - '0');
                }
                else
                {
                    break;
                }
            }
        }
    }
    printf("%d", total);
}
