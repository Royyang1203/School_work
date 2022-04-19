#include <iostream>
using namespace std;
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
    cout << "D0:"<< endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%5d ", D[i][j]);
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
        cout << "D" << k+1 <<":" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%5d ", D[i][j]);
            cout << endl;
        }
        cout << endl;
    }
}