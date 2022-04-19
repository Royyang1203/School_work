#include<iostream>
#include<algorithm>
using namespace std;

int Divide(int *a,int l,int r)
{
    if(l>=r)
        return a[l];
    int mid = (l+r)/2;
    int lmax = Divide(a,l,mid);
    int rmax = Divide(a,mid+1,r);

    return max(lmax,rmax);
}

int main()
{
    int A[] = {123, 340, 189, 56, 150, 12, 9, 240},n;
    n = sizeof(A)/sizeof(A[0]);
    
    cout<<Divide(A,0,n-1);

    return 0;
}