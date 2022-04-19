#include<iostream>
#include<algorithm>
using namespace std;
int knapsack(int b, int idx,int *p,int *w,int **set)
{
    if(idx<0 || b==0) 
        return 0;
        
    if(w[idx]>b)
        return knapsack(b,idx-1,p,w,set);
        
    else 
    {
        int x =0,y=0;
        x = p[idx]+knapsack(b - w[idx], idx-1, p, w,set);
        y =  knapsack(b, idx-1, p, w,set);
        if(x>=y)
            set[idx][b]=1;
        return max(x,y);
    }      
}
int main()
{
    int budget_cap,n_item;
    cin>>budget_cap>>n_item;

    int preferences[n_item],weight[n_item];
    int set[n_item][budget_cap+1];
    int *copy[n_item];
    for(int i=0;i<n_item;i++)
        copy[i] = set[i];
        
    for(int i=0;i<n_item;i++) cin>>preferences[i];
    for(int i=0;i<n_item;i++) cin>>weight[i];    

    cout<<"MAX: "<<knapsack(budget_cap,n_item-1,preferences,weight,copy);
    cout<<endl;
    for(int i=n_item-1,j=budget_cap; i>=0;--i)
           if(set[i][j]==1 && j>0)
            {
                j-=weight[i];
                cout<<i<<" th items\n";
            }
    return 0;
}