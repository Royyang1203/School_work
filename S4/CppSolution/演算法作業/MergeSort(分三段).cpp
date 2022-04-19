#include<iostream>
using namespace std;
 int INF = 10000000;
void Merge(int *a,int *copy_a,int l,int r,int ml,int mr)
{
    int i = l,j =ml+1,k= mr+1 ,*min=NULL;
    //cout<<l<<" "<<ml<<" "<<mr<<" "<<r<<endl;
    for(int idx=l; idx<=r;)
	{
	    if(i<=ml)
            min=&i;

        if(min==NULL || (j<=mr && (copy_a[j]<copy_a[(*min)])) )
            min=&j;

        if(min==NULL || (k<=r && (copy_a[k]<copy_a[(*min)])) )
            min=&k;

        a[idx++] = copy_a[(*min)++];///***代表i、j、k ，當 (*min)++ 代表i,j,k;
        min=NULL;
        /*for(int i=l;i<=r;i++)
            cout<< a[i]<<" ";
        cout<<endl;*/

	}
	for(int i=l;i<=r;i++)
        copy_a[i] = a[i];
}
void MergeSort(int *a,int *copy_a,int l,int r,int n)
{
    if(n < 2)
        return;

    int len = (r-l)/3;
    int ml  = l + len;
    int mr  = ml + len+1;

    MergeSort(a,copy_a,l,ml,ml-l+1);
    MergeSort(a,copy_a,ml+1,mr,mr-ml);
    MergeSort(a,copy_a,mr+1,r,r-mr);
    Merge(a,copy_a,l,r,ml,mr);
}

int main() {

    int a[] = {9,8,7,5};
    int n = sizeof(a) / sizeof(a[0]);
    int copy_a[n];

    for(int i=0;i<n;i++)
        copy_a[i] = a[i];

    MergeSort(a,copy_a, 0, n-1,n);
    cout<< "sorted:\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
