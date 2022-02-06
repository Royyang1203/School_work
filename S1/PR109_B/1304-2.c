#include <stdio.h>

int count(int y, int m, int d)
{
    int k = d;
    k += 365 * y + y / 4 - y / 100 + y / 400;
    for (int i = 12; i >= m; i --)
            switch(i) {
                case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
                    k -= 31;
                    break;
                case 4 : case 6 : case 9 : case 11 :
                    k -= 30;
                    break;
                case 2 :
                    if (y % 400 == 0 || y % 4 == 0 && y % 100 != 0)
                        k -= 29;
                    else
                        k -= 28;
                    break;
            }
    return k;
}
int main(void)
{
    int y1, y2, m1, m2, d1, d2, s1, s2;
    while (scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF) {
        int s1 = count(y1, m1, d1);
        int s2 = count(y2, m2, d2);
        printf("%d\n", abs(s1 - s2));
    }
    return 0;
}
