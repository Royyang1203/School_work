#include<iostream>
#include<algorithm>
using namespace std;
///教學影片:https://www.youtube.com/watch?v=wuU4DDEUu1w
struct edge
{
    int s;
    int e;
    int w;
};
int cmp(edge a,edge b){ return a.w<b.w;}
int find(int *p,int i) //找祖先
{
    while(p[i]>=0) i = p[i];
    return i;
}
void merge(int *p,int a,int b)
{
    int temp = p[a]+p[b];
    if(p[a]<=p[b])///a這個點的集合數量比較多。後面接前面
    {
        p[b] = a;
        p[a] = temp;
    }
    else
    {
        p[a] = b;
        p[b] = temp;
    }
}
int kruskal(edge *E,int n,int *p)
{
    int idx=0,result=0,k=0,root1,root2;
    edge chooes[n*n];
    while(cin>>E[idx].s>>E[idx].e>>E[idx].w) {idx ++;}///輸入圖
    
    sort(E,E+idx,cmp);///將邊的權重有小到大排序
   // for(int i=0;i<idx;i++) cout<<E[i].s<<" "<<E[i].e<<" "<<E[i].w<<endl; //輸出sort後的data
    for(int i=0;i<idx;i++)
    {
        root1 = find(p,E[i].s);
        root2 = find(p,E[i].e);

        if(root1 != root2)///不會形成cycle
        {
            merge(p,root1,root2);
            result+=E[i].w;
            chooes[k++] = E[i] ; 
        }
    }

    for(int i=0;i<k;i++)
         cout<<chooes[i].s<<" "<<chooes[i].e<<" "<<chooes[i].w<<endl;
    return result;
}

int main()
{
    int n;
    cin>>n;
    edge E[n*n];
    int p[n+1];
    for(int i=0;i<n+1;i++) p[i] = -1 ;
    
    cout<<kruskal(E,n,p);
    return 0;
}