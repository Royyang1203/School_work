#include <iostream>
using namespace std;

///one array 實作
int main()
{
    int n,k;
    cin>>n>>k;
    int len=n+1;
    int b[len];
    int i,j;

    for (i = 0; i <= n; i++)
    {
        for(j=i;j>=0;j--)
        {
            if(j==i || j==0)
                b[j] = 1;
            else
                b[j]+=b[j-1];
        }
    }
    cout<<b[k]<<" ";
}