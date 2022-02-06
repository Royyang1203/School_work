#include <stdio.h>

int main(void)
{
    int n, m, arrk = 1, t, q = 0;
    scanf("%d%d", &n, &m);
    int arr[1000][3];
    for (int i = 0; i < 1000; i ++)
        for (int j = 0; j < 3; j ++)
            arr[i][j] = -1;
    int courses[n][5];
    for (int i = 0; i < n; i ++)
        for (int j = 3; j < 5; j ++)
            courses[i][j] = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < 3; j ++)
            scanf("%d", &courses[i][j]);

    for (int i = 0; i < m; i ++) {
        scanf("%d", &t);
        for (int j = 0; j < n; j ++)
            if (courses[j][0] == t) {
                scanf("%d", &t);
                courses[j][3] += t;
                courses[j][4] ++;
                continue;
            }
    }

    arr[0][0] = courses[0][1];
    for (int i = 1; i < n; i ++) {
        int continu = 0;
        for (int j = 0; j < arrk; j ++) {
            if (continu)
                continue;
            if (courses[i][1] == arr[j][0])
                continu = 1;
            else if (j == arrk - 1) {
                arr[arrk][0] = courses[i][1];
                arrk ++;
                continu = 1;
            }
        }
    }

    for (int i = 0; i < n; i ++)
        if ((float)courses[i][3] / courses[i][4] < 60)
            for (int j = 0; j < arrk; j ++)
                if (courses[i][1] == arr[j][0] && arr[j][1] == -1) {
                    arr[j][1] = 0;
                    q ++;
                }
    printf("%d %d", arrk, q);//output
    return 0;
}
