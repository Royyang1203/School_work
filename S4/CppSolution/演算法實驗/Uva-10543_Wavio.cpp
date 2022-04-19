#include<iostream>
using namespace std;

int binar_search(int left,int right,int key,int *val,int* a)
{
    int mid;
    if(key<=a[val[0]])
        return 0;
    else if(key == a[val[right]])
        return right;
    while (right-left>1)
    {
        mid =(left+right)/2;
        if(key==a[val[mid]])
            return mid;
        else if(key>a[val[mid]])
            left = mid;
        else 
            right = mid;
    }
    return right;
}

int get_index(int i,int *len,int *a,int *val,int *h)
{
    int temp;
    if((*len)==0)
    {
        val[(*len)++] = i;
        return -1;
    }
    if(a[i]>a[val[(*len)-1]])
    {
        temp = val[(*len)-1];
        val[(*len)++] = i;
        return temp;
    }
    else if(a[i]<=a[val[(*len)-1]])
    {
        int index = binar_search(0,(*len)-1,a[i],val,a);
        if(index==0)
        {
            val[index] = i;
            return-1;
        }
        else
        {
            temp = val[index];
            val[index] = i;
        }
    }
    return h[temp];
}
int main()
{
    int n;
    while(cin>>n)
    {
        int a[n],g[n],val[n]={0},h[n],len=0;
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
        {
            g[i] = 1;
            h[i] = get_index(i,&len,a,val,h);
            if(h[i] == -1)
                g[i] = 1;
            else
                g[i] = g[h[i]]+1;
        }

        int temp,g1[n];
        len = 0 ;
        for(int i=0;i<n/2;i++)///將 a[i]反轉
        {
             temp = a[i];
            a[i] = a[n-1-i];
            a[n-1-i] = temp;
        }
        for(int i=0;i<n;i++)
        {
            val[i]=h[i]=0;///把之前的值歸零
            g1[i] = 1;
            h[i] = get_index(i,&len,a,val,h);
            if(h[i] == -1)
                g1[i] = 1;
            else
                g1[i] = g1[h[i]]+1;
        }
        for(int i=0;i<n/2;i++)///將 g[i]反轉
        {
            temp = g1[i];
            g1[i] = g1[n-1-i];
            g1[n-1-i] = temp;
        }
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            temp = min(g[i], g1[i]);
            if (max < temp)
                max = temp;
        }
        cout<<max*2-1<<endl;
    }
    return 0;
}