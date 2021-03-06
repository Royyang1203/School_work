#include <stdio.h>

int findpath(int *maze, int n, int row, int col)
{
    if((row == n-1 && col == n-1) || *(maze + n*n - 1) == 2)
    {
        *(maze + n*row + col) = 2;
        return 1;
    }
    if(*(maze + n*row + col + 1) == 0 && col + 1 < n){
        *(maze + n*row + col + 1) = 2;
        findpath(maze, n, row , col+1);
    }
    if(*(maze + n*(row+1) + col) == 0 && row + 1 < n){
        *(maze + n*(row+1) + col) = 2;
        findpath(maze, n, row+1, col);
    }
    if(*(maze + n*row + col - 1) == 0 && col - 1 >= 0){
        *(maze + n*row + col - 1) = 2;
        findpath(maze, n, row, col-1);
    }
    if(*(maze + n*(row-1) + col) == 0 && row - 1 >= 0){
        *(maze + n*(row-1) + col) = 2;
        findpath(maze, n, row-1, col);
    }
    return *(maze + n*row + col) = 3;
}

int main()
{
    int n;
    scanf("%d", &n);
    int maze[n][n];
    int i, h, temp;

    for(i=0; i<n; i++)
        for(h=0; h<n; h++)
            scanf("%d", &maze[i][h]);

    temp = findpath(maze, n, 0, 0);
    if(maze[n-1][n-1] == 2)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
