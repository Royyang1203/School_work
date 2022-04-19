#include<iostream>
#include<algorithm>
using namespace  std;

void order(int i,int j,int **p)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        int k = p[i][j];
        cout<<"(";
        order(i,k,p);
        order(k+1,j,p);
        cout<<")"; 
    }
}
int main()
{
    int a[]={10,4,5,20,2,50};
    int n = sizeof(a)/sizeof(a[0]);
    int m[n+1][n+1],p[n+1][n+1];

    for(int i=0;i<n+1;i++)
        for(int j=0;j<n+1;j++)
        {
            m[i][j]=0;
            p[i][j]=0;
        }
    
    for(int diagonal=1; diagonal<n; diagonal++)
    {
        for(int i=1;i<=n-diagonal;i++)
        {
            int j = diagonal+i;
            m[i][j]=9999999;
            for(int k=i;k<=j-1;k++)
                {
                    int q = m[i][k]+m[k+1][j]+a[k]*a[i-1]*a[j];
                    if(q<m[i][j])
                    {
                        m[i][j] = q;
                        p[i][j] = k;
                    }
                }
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
            printf("%8d",p[i][j]);
    cout<<endl;
    }

    int *copy[n];
    for(int i=0;i<n;i++)
        copy[i] = p[i];
    order(1,n-1,copy);
}
