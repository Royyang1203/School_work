#include <iostream>
using namespace std;
void path(int r,int c,int **p)
{
    if(p[r][c]!=0)
    {
        path(r,p[r][c]-1,p);
        cout<<"v"<<p[r][c]<<" ";
        path(p[r][c]-1,c,p);
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n][n], p[n][n], D[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            p[i][j] = 0;
            D[i][j] = a[i][j];
        }
    cout << "p0:"<< endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%5d ", p[i][j]);
        cout << endl;
    }
    cout << endl;

    for (int k = 0; k < n; k++) ///必經過某個點
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (D[i][j] > (D[i][k] + D[k][j]))
                { 
                    p[i][j] = k + 1;
                    D[i][j] = D[i][k] + D[k][j];
                }
        cout << "p" << k+1 <<":" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%5d ", p[i][j]);
            cout << endl;
        }
        cout << endl;
    }
    int *copy[n];
    for(int i=0;i<n;i++)
        copy[i] = p[i];
  
    
   path(7-1,3-1,copy);
   cout<<"v3 ";
    return 0;
}