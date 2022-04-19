#include <iostream>
using namespace std;
int main()
{
    int a[]={9,4,1,6,7,3,8,2,5};
    int n = sizeof(a)/sizeof(a[0]);
    Quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}