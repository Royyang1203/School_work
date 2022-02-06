#include <stdio.h>

int main(void)
{
    int y1, y2, m1, m2, d1, d2, s1, s2;
    while (scanf("%d%d%d%d%d%d", &y1, &m1, &d1, &y2, &m2, &d2) != EOF) {
        s1 = d1;
        for (int i = 1; i < m1; i ++)
            switch(i) {
                case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
                    s1 += 31;
                    break;
                case 4 : case 6 : case 9 : case 11 :
                    s1 += 30;
                    break;
                case 2 :
                    if (y1 % 400 == 0 || y1 % 4 == 0 && y1 % 100 != 0)
                        s1 += 29;
                    else
                        s1 += 28;
                    break;
            }
        s1 += y1 / 400 * 146097;
        y1 %= 400;
        if (y1 / 100 > 0)
            s1 += y1 / 100 * 36524;
        y1 %= 100;
        s1 += y1 / 4 * 1461;
        y1 %= 4;
        if (y1 > 0)
            s1 += y1 * 365 + 1;
        s2 = d2;
        for (int i = 1; i < m2; i ++)
            switch(i) {
                case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 :
                    s2 += 31;
                    break;
                case 4 : case 6 : case 9 : case 11 :
                    s2 += 30;
                    break;
                case 2 :
                    if (y2 % 400 == 0 || y2 % 4 == 0 && y2 % 100 != 0)
                        s2 += 29;
                    else
                        s2 += 28;
                    break;
            }
        s2 += y2 / 400 * 146097;
        y2 %= 400;
        if (y2 / 100 > 0)
            s2 += y2 / 100 * 36524;
        y2 %= 100;
        s2 += y2 / 4 * 1461;
        y2 %= 4;
        if (y2 > 0)
            s2 += y2 * 365 + 1;
        printf("%d\n", s1 - s2);
    }
    return 0;
}
