#include<iostream>
using namespace std;

int Ternary_Searching(int *a,int l,int r,int target)
{
    if(r-l+1<=3)
    {
        for(int i=l;i<=r;i++)
            if(target == a[i])
                return a[i];
         return -1;
    }

    int len = (r-l+1)/3;
    int ml = l+len-1;
    int mr = ml+len; 
        
    if(a[mr] == target || a[ml] ==target) return target;
    else if (target > a[mr] ) return Ternary_Searching(a,mr+1,r,target);
    else if( target < a[mr] && target > a[ml]) return Ternary_Searching(a,ml+1,mr-1,target);
    else return Ternary_Searching(a,l,ml-1,target);
    
}
int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a)/sizeof(a[0]);
    int target;
    while (1)
    {
        cin>>target;
        cout<<Ternary_Searching(a,0,n-1,target)<<" ";
    }
}