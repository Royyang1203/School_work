#include <iostream>
using namespace  std;

void buildarray(int ***array,int row,int col)
{
    *array = new int*[row];
    /*for(int i=0;i<row;i++)
        array[i] = new int[col];*/
    int *p = new int[row*col];
    for(int i=0;i<row;i++)
        (*array)[i] = &p[i*col]; ///or p+i*col
}
int main()
{
    int **array,row,col,k=0;
    cin>>row>>col;
   buildarray(&array,row,col);

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            array[i][j]=++k;

    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)     
            printf(" %d %p \n", array[i][j],&array[i][j]);

    printf("\n"); 
    int *ptr = &array[0][0];
    for(int i=0;i<row*col;i++)///連續陣列就可以用一維指標訪問
        printf(" %d %p \n",*(ptr+i),ptr+i);
      
}