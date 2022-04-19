#include<iostream>
using namespace  std;

void sort_by_digit(int *A, int n,int begin,int end, int r , int d)
{
    //cout<<begin<<" "<<end<<" "<<d<<" "<<r<<endl;
    if(d<0)
        return;
        
    int base = 1,copy_d=d,count[r]={0}, B[n],begin_arr[r],number[r]={0};
   
    while (copy_d > 0)
    {
        --copy_d;
        base *= r;
    }

    for (int i = begin; i < end; ++i)
        count[(A[i] / base) % r]++;

    for (int i = 0; i < r; ++i)
        number[i]=count[i];

    for (int j = 0, psum = 0, sum = 0; j < r; ++j)  
    {
        psum = sum;
        sum += count[j];
        count[j] = psum;
    }

    for (int i = 0; i < r; ++i)
        begin_arr[i] = count[i];

    for (int i = begin; i < end; ++i)
        B[count[(A[i] / base) % r]++] = A[i];
    for (int i = begin,j=0; i < end;j++, ++i)
        A[i] = B[j];
   
    for (int i = 0; i < r; ++i)
        if(number[i]>1)
            sort_by_digit(A,n,begin_arr[i]+begin,count[i]+begin,r,d-1);
}
void radix_sort(int *A, int n, int r, int d)
{
        sort_by_digit(A,n,0,n, r, d-1);
}
int maxbit(int data[], int n,int r) //求資料的最大位數
{
    int d = 1; //儲存最大的位數
    int base = r;
    for(int i = 0; i < n; ++i) 
    {
        while(data[i] >= base) 
        {
            base *= r;
            ++d;
        }
    }
    return d;
}
int main()
{
    int a[] = {34,35,52,76,21,77};
    int n,d=1,r=10;
    n = sizeof(a) / sizeof(a[0]);
    d = maxbit(a,n,r);
   // cout<<d;
    radix_sort(a,n,r,d);

    for(int k = 0; k < n; k++)
        printf("%d ", a[k]);
    printf("\n");
    return 0;
}