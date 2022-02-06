// Given a rectangular grid of characters you have to find out the length of a side of the largest square such that all the characters of the square are same and the center [intersecting point of the two diagonals] of the square is at location (r, c). The height and width of the grid is M and N respectively. Upper left corner and lower right corner of the grid will be denoted by (0, 0) and (M − 1, N − 1) respectively. Consider the grid of characters given below. Given the location (1, 2) the length of a side of the largest square is 3.

// abbbaaaaaa
// abbbaaaaaa
// abbbaaaaaa
// aaaaaaaaaa
// aaaaaaaaaa
// aaccaaaaaa
// aaccaaaaaa

// Input
// The input starts with a line containing a single integer T (< 21). This is followed by T test cases. The first line of each of them will contain three integers M, N and Q (< 21) separated by a space where M, N denotes the dimension of the grid. Next follows M lines each containing N characters. Finally, there will be Q lines each containing two integers r and c. The value of M and N will be at most 100.

// Output
// For each test case in the input produce Q + 1 lines of output. In the first line print the value of M, N and Q in that order separated by single space. In the next Q lines, output the length of a side of the largest square in the corresponding grid for each (r, c) pair in the input.

// Sample Input
// 1
// 7 10 4
// abbbaaaaaa
// abbbaaaaaa
// abbbaaaaaa
// aaaaaaaaaa
// aaaaaaaaaa
// aaccaaaaaa
// aaccaaaaaa
// 1 2
// 2 4
// 4 6
// 5 2

// Sample Output
// 7 10 4
// 3
// 1
// 5
// 1

#include <stdio.h>
char arr[200][200];
int count = 0;
int square(int x, int y)
{
    int i, j;
    int k = 1;
    for (i = x - count; i <= x + count; i++)
    {
        for (j = y - count; j <= y + count; j++)
        {
            if (arr[i][j] != arr[x][y])
                k = 0;
        }
    }
    if (k == 0)
    {
        count--;
        return square(x, y);
    }
    else if (k == 1)
        return count;
}

int main()
{

    int n, a, b, c, x, y, out[200] = {0};
    int i, j, k;
    scanf("%d", &n);
    for (k = 0; k < n; k++)
    {
        scanf("%d%d%d", &a, &b, &c);
        for (i = 0; i < a; i++)
            for (j = 0; j < b; j++)
                scanf(" %c", &arr[i][j]);
        for (i = 0; i < c; i++)
        {
            count = 1;
            scanf("%d%d", &x, &y);
            while (arr[x - count][y - count] == arr[x][y] && (x + count < a && y + count < b && x - count >= 0 && y - count >= 0))
                count++;
            out[i] = square(x, y);
        }

        for (i = 0; i < 199; i++)
            for (j = 0; j < 199; j++)
                arr[i][j] = ' ';

        printf("%d %d %d\n", a, b, c);
        for (i = 0; i < c; i++)
        {
            printf("%d", out[i] * 2 + 1);
            if (i < c - 1)
                printf("\n");
        }
    }
    return 0;
}