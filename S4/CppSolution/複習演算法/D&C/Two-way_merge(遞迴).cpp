#include<iostream>
using namespace std;
void merge(int *a,int l,int mid,int r)
{
    int *b = new int[r-l+1];
    int i=l,j=mid+1,idx=0;
    while(i<=mid && j<=r)
    {
        if(a[i]<=a[j])
            b[idx++] = a[i++];
        else
            b[idx++] = a[j++];
    }
    
    while(i<=mid)
        b[idx++] = a[i++];
    while (j<=r)
        b[idx++] = a[j++];
    for(int i=l, k=0;i<=r;i++)
       a[i]=b[k++];
    //cout<<endl;
}
void mergesort(int *a,int l,int r)
{
    if(l>=r)///剩餘一個值
        return;
    int mid = (l+r)/2;
    mergesort(a,l,mid);///排序左子序
    mergesort(a,mid+1,r);///排序右子序
    merge(a,l,mid,r);///合併左右子序
}
int main()
{
    int a[]={27,10,12,20,25,13,15,22};
    int n=sizeof(a)/sizeof(a[0]);

    mergesort(a,0,n-1);
    cout<<n<<endl;
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}