#include<iostream>
#include<algorithm>
using namespace  std;
int cross_sum(int *a,int l,int r,int mid,int Max);
int start=-1,End=-1;
int maxsubarraysum(int *a,int l,int r)
{
    if(l==r)
    {
        start = End =l;
        return a[l];
    }
    int mid  = (l+r)/2;
    int lmax = maxsubarraysum(a,l,mid);
    int rmax = maxsubarraysum(a,mid+1,r);
    int Max = max(lmax,rmax);
    
    if(lmax>rmax)
    {
        start = l;
        End = mid;
    }
    else
    {
        start = mid+1;
        End = r;
    }
    int cmax = cross_sum(a,l,r,mid,Max);

    return max(max(lmax,rmax),cmax);
}
int cross_sum(int *a,int l,int r,int mid,int Max)
{
    int left_sub_sum=a[mid],right_sub_sum=a[mid+1],temp=0;
    int ls=-1,le=-1,rs=-1,re=-1;
    for(int i=mid;i>=l;i--)///leftsub
    {
        temp += a[i];
        if(left_sub_sum < temp)
        {
            left_sub_sum = max(left_sub_sum,temp);
            le = mid;
            ls = i;
        }
    }
    temp=0;
    for(int i=mid+1;i<=r;i++)///righttsub
    {
        temp += a[i];
        if(temp>right_sub_sum )
        {
            right_sub_sum = max(right_sub_sum,temp);
            rs = mid+1;
            re = i;
        }
    }
    int temp_max = max(max(left_sub_sum + right_sub_sum,left_sub_sum),right_sub_sum);
    if(temp_max>Max)
    {
        if(temp_max == left_sub_sum + right_sub_sum)
        {
            start = ls;
            End = re;
        }
        else if(temp_max==left_sub_sum )
        {
            start = ls;
            End = le;
        }
        else if(temp_max==right_sub_sum)
        {
            start = rs;
            End = re;
        }
    }
    return temp_max;
}
int main()
{
    int a[] = {5,4,-1,7,8};
    int n = sizeof(a)/sizeof(a[0]);
    int maxsum=maxsubarraysum(a,0,n-1);
    cout<<"Index: "<<start <<" "<<End<<endl;
    cout<<maxsum;
}
