#include<iostream>
using namespace std;

int binary_search(int *a,int l,int r,int key)
{
    int mid = (l+r)/2;
    if(l>r)
        return 0;
    if(key == a[mid])
        return a[mid];
    else if(key > a[mid])
        return binary_search(a,mid+1,r,key);
    else
        return binary_search(a,l,mid-1,key);
}
int main()
{
    int a[]={2,3,4,10,15};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<binary_search(a,0,n-1,1);
}