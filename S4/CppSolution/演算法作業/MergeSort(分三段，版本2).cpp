#include<iostream>
#include<algorithm>
using namespace std;
 int INF = 10000000;
void Merge(int *a,int *copy_a,int l,int r,int ml,int mr)
{
    int idx=l;
    int i = l,j =ml+1,k= mr+1;
   
    while((i<=ml) && (j<=mr) && (k<=r))
    {
        if(copy_a[i]<=copy_a[j] &&copy_a[i]<=copy_a[k])a[idx++] = copy_a[i++];
    
        else if(copy_a[j]<=copy_a[i] &&copy_a[j]<=copy_a[k])a[idx++] = copy_a[j++];
            
        else a[idx++] = copy_a[k++];
    }
    while(i<=ml && j<=mr)//左邊與中間還沒排完
    {
        if(copy_a[i]<=copy_a[j]) a[idx++] = copy_a[i++];
        else  a[idx++] = copy_a[j++];
    }
    while (i<=ml && k<=r)//左邊與右邊還沒排完
    {
        if(copy_a[i]<=copy_a[k]) a[idx++] = copy_a[i++];
        else a[idx++] = copy_a[k++];
    }
    while (j<=ml && k<=r)//中間與右邊還沒排完
    {
        if(copy_a[j]<=copy_a[k]) a[idx++] = copy_a[j++];
        else a[idx++] = copy_a[k++];
    }
    while(i<=ml) a[idx++] = copy_a[i++];
    while(j<=mr) a[idx++] = copy_a[j++];
    while(k<=r)  a[idx++] = copy_a[k++];

    for(int i=l;i<=r;i++)
        copy_a[i] = a[i];
}
void MergeSort(int *a,int *copy_a,int l,int r,int n)
{
    if(n <2)
        return;

    int len = (r-l)/3;
    int ml  = l + len;
    int mr  = ml + len+1;
    
    MergeSort(a,copy_a,l,ml,ml-l+1);//左半邊
    MergeSort(a,copy_a,ml+1,mr,mr-ml);//中間
    MergeSort(a,copy_a,mr+1,r,r-mr);//右半邊
    Merge(a,copy_a,l,r,ml,mr);
}

int main() {

    int a[] = {5,3,8,6,2,7,1,4};
    int n = sizeof(a) / sizeof(a[0]);
    int copy_a[n];
    
    for(int i=0;i<n;i++)
        copy_a[i] = a[i];

    MergeSort(a,copy_a, 0, n-1,n);
    cout << "sorted:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
