#include <stdio.h>
#include <stdlib.h>

void queens(int, int);
void queensstarter();
void printarea();
void printmatrix(int);
int placequeen(int, int, int);
int removequeen(int, int, int);

/*
Queens(x,y) function is recursive function to find all possible position set of queen by backtrackig.
Queensstarter function starts recursive call of function queens in first position (0,0,0).
Printarea function calls printmatrix function. It prints out answer set of queens and its 1 through n-1 shifted-answers.
Printmatrix function checks position of queens in area array and prints out to visible table form.
Placequeen function places a queen to input position and refresh all unavailable count in area array.
Removequeen function removes a queen from input position and refresh all unavailable count in area array
*/

int n;
int count = 0;

/*
Int variable n saves input number.
Int variable count saves a number of possible solution.
*/

int area[100][100][100] = {0};

/*
Array area makes space to place queen, save position of each queen and unavailable area.
In this area, value of cell goes up from 0. During the procedure, meaning of area[x][y][z] value are belowed:
    area[x][y][z] = 0: Queen can be placed in (x,y,z).
        area[x][y][z] = 1 of above: Queen cannot be placed in (x,y,z).
And the end of the each result, the cells which its value=1 shows the position of queens.
*/

int main(int argc, char *argv[])
{
    int i, j, k;
    n = atoi(argv[1]);
    queensstarter();
    if (count == 0)
        printf("#0\n");
}

void queensstarter()
{
    int i;
    placequeen(0, 0, 0);  // place Q in position(0,0,0)
    queens(0, 1);         // call queens function itself in next position
    removequeen(0, 0, 0); // remove Q in position(0,0,0)
}

void queens(int x, int y)
{
    int i, j, k;
    if (x == n)
        printarea(); // x=n means all n*n queens placed in right position. So current set of queens is a solution.
    else if (y == n)
        queens(x + 1, 0); // y=n means current yz plane is fulled by queen. So It calls queens(x+1 plane).
    else
    {
        for (i = 0; i < n; i++)
        {
            if (area[x][y][i] == 0)
            {
                placequeen(x, y, i);  // place Q in current position
                queens(x, y + 1);     // call queens function itself in next position
                removequeen(x, y, i); // remove Q in current position
            }
        }
    }
}
void printarea()
{
    int i;
    for (i = 0; i < n; i++)
        printmatrix(i); // it prints 1 through n-1 shifted set of answers.
}

void printmatrix(int shift)
{
    int i, j, k;
    count++;
    printf("#%d\n", count);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (area[i][j][k] == 1)
                {
                    if ((k + shift) < n)
                        printf("%03d, ", k + shift + 1); // It prints value of z(= height of queen).
                    else
                        printf("%03d, ", k + shift + 1 - n); // If shifted value is heigher than n, it goes height-n.
                }
            }
        }
        for (k = 0; k < n; k++)
        {
            if (area[i][n - 1][k] == 1)
            {
                if ((k + shift) < n)
                    printf("%03d\n", k + shift + 1);
                else
                    printf("%03d\n", k + shift + 1 - n);
            }
        }
    }
}

int placequeen(int x, int y, int z)
{
    int i, j;

    // belowed are check array refresh
    // next queen will be placed in bigger x, bigger y value.
    // It means we don't need to add the unavailable count through x--, y-- direction.
    for (i = 0; i < n; i++)
    {
        area[i][y][z]++;
        area[x][i][z]++;
        area[x][y][i]++;
    } // xyz axis

    // belowed are 2-axis shift
    // belowed are xy plane
    i = 0;
    while (((x + i) < n) && ((y + i) < n))
    {
        area[x + i][y + i][z]++;
        i++;
    } // x+y+

    i = 0;
    while (((x + i) < n) && ((y - i) >= 0))
    {
        area[x + i][y - i][z]++;
        i++;
    } // x+y-

    // belowed are yx plane
    i = 0;
    while (((y + i) < n) && ((z + i) < n))
    {
        area[x][y + i][z + i]++;
        i++;
    } // y+z+

    i = 0;
    while (((y + i) < n) && ((z - i) >= 0))
    {
        area[x][y + i][z - i]++;
        i++;
    } // y+z-

    // belowed are zx plane
    i = 0;
    while (((z + i) < n) && ((x + i) < n))
    {
        area[x + i][y][z + i]++;
        i++;
    } // z+x

    i = 0;
    while (((z - i) >= 0) && ((x + i) < n))
    {
        area[x + i][y][z - i]++;
        i++;
    } // z-x+

    // belowed are 3-axis shift
    i = 0;
    while (((x + i) < n) && ((y + i) < n) && ((z + i) < n))
    {
        area[x + i][y + i][z + i]++;
        i++;
    } // x+y+z+

    i = 0;
    while (((x + i) < n) && ((y + i) < n) && ((z - i) >= 0))
    {
        area[x + i][y + i][z - i]++;
        i++;
    } // x+y+z-

    i = 0;
    while (((x + i) < n) && ((y - i) >= 0) && ((z + i) < n))
    {
        area[x + i][y - i][z + i]++;
        i++;
    } // x+y-z+

    i = 0;
    while (((x + i) < n) && ((y - i) >= 0) && ((z - i) >= 0))
    {
        area[x + i][y - i][z - i]++;
        i++;
    } // x+y-z-

    area[x][y][z] = 1;
}

int removequeen(int x, int y, int z)
{
    int i, j;

    // belowed are check array refresh
    for (i = 0; i < n; i++)
    {
        area[i][y][z]--;
        area[x][i][z]--;
        area[x][y][i]--;
    } // xyz axis

    // belowed are 2-axis shift
    // belowed are xy plane
    i = 0;
    while (((x + i) < n) && ((y + i) < n))
    {
        area[x + i][y + i][z]--;
        i++;
    } // x+y+

    i = 0;
    while (((x + i) < n) && ((y - i) >= 0))
    {
        area[x + i][y - i][z]--;
        i++;
    } // x+y-

    // belowed are yx plane
    i = 0;
    while (((y + i) < n) && ((z + i) < n))
    {
        area[x][y + i][z + i]--;
        i++;
    } // y+z+

    i = 0;
    while (((y + i) < n) && ((z - i) >= 0))
    {
        area[x][y + i][z - i]--;
        i++;
    } // y+z-

    // belowed are zx plane
    i = 0;
    while (((z + i) < n) && ((x + i) < n))
    {
        area[x + i][y][z + i]--;
        i++;
    } // z+x

    i = 0;
    while (((z - i) >= 0) && ((x + i) < n))
    {
        area[x + i][y][z - i]--;
        i++;
    } // z-x+

    // belowed are 3-axis shift
    i = 0;
    while (((x + i) < n) && ((y + i) < n) && ((z + i) < n))
    {
        area[x + i][y + i][z + i]--;
        i++;
    } // x+y+z+

    i = 0;
    while (((x + i) < n) && ((y + i) < n) && ((z - i) >= 0))
    {
        area[x + i][y + i][z - i]--;
        i++;
    } // x+y+z-

    i = 0;
    while (((x + i) < n) && ((y - i) >= 0) && ((z + i) < n))
    {
        area[x + i][y - i][z + i]--;
        i++;
    } // x+y-z+

    i = 0;
    while (((x + i) < n) && ((y - i) >= 0) && ((z - i) >= 0))
    {
        area[x + i][y - i][z - i]--;
        i++;
    } // x+y-z-

    area[x][y][z] = 0;
}