#include <iostream>
using namespace std;
int partition(int *a,int l,int r)
{
    int pivot=a[r],i=l-1,j=l;
    for(;j<=r;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);///a[i]與a[j]交換
        }
    }
    swap(a[++i],a[r]);///++i==mid,將再將pivot與a[++i]位置交換
    return i;///回傳mid的位置
}
void Quicksort(int *a,int l,int r)
{
    if(l<r)
    {
        int mid = partition(a,l,r);
        Quicksort(a,l,mid-1);///左子序列
        Quicksort(a,mid+1,r);///右子序列
    }
}
int main()
{
    int a[]={9,4,1,6,7,3,8,2,5};
    int n = sizeof(a)/sizeof(a[0]);
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}