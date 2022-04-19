#include<iostream>
#include<algorithm>
using namespace std;
///教學影片:https://www.youtube.com/watch?v=wuU4DDEUu1w，https://www.youtube.com/watch?v=KEQjrKN0yhg&t=1075s
struct edge
{
    int s;
    int e;
    int w;
};
int cmp(edge a,edge b){ return a.w<b.w;}
int find(int *p,int i) //找祖先      time complexity O(lgn) 因為他的建立出來樹的高度絕對不會超過 (lgn) + 1
{
    while(p[i]>=0) i = p[i];
    return i;
}
void merge(int *p,int a,int b)
{
    int temp = p[a]+p[b]; //根節點的祖先都會是負數，負數可以代表此家族有幾個人
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
/*
7
1 2 23
2 3 20
3 4 15
4 5 3
5 6 17
6 1 28
7 1 36
7 2 1
7 3 4
7 4 9
7 5 16
7 6 25
^Z
output:
7 2 1
4 5 3
7 3 4
7 4 9
5 6 17
1 2 23
57
6
1 2 20
2 4 10
4 5 5
5 6 80
3 6 100
1 3 40
2 3 70
2 5 5
2 6 10
^Z
output:
4 5 5
2 5 5
2 6 10
1 2 20
1 3 40
80
*/