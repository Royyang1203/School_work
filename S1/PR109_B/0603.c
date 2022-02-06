#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int arr[n][m];
    for (int i = 0;i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &arr[i][j]);
    int row = 0;
    int col = -1;
    int dir = 0;
    int distn = n - 1;
    int distm = m;
    int turn[4] = {1, 1, -1, -1};
    while (distn > 0 || distm > 0) {
        if (dir % 2 && distn > 0) {
            for (int i = 0; i < distn; i++) {
                row += turn[dir];
                printf("%d ", arr[row][col]);
            }
            dir = ((dir + 1) % 4);
            distn--;
            continue;
        }
        else if (dir % 2 == 0 && distm > 0){
            for (int i = 0; i < distm; i++) {
                col += turn[dir];
                printf("%d ", arr[row][col]);
            }
            dir = ((dir + 1) % 4);
            distm--;
            continue;
        }
        if (distn == 0 || distm == 0)
            break;
    }
    return 0;
}
