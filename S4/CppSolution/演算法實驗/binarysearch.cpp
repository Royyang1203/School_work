#include<iostream>
using namespace std;

int Binary_search(int *A,int n,int x)
{
    int start=0,end=n-1,mid;

    while(start<=end)
    {
        mid = (start+end)/2;
        if(A[mid]==x)
            return A[mid];
        else if(x>A[mid])
            start = mid+1;
        else if(x<A[mid])
            end = mid-1;
    }
    return -1;
}
int main()
{
    int A[] = {-123,34,52,76,77},n,x;
    n = sizeof(A)/sizeof(A[0]);
    
    while(1)
    {
       cin>>x;
       cout<<Binary_search(A,n,x);
    }
    return 0;
}