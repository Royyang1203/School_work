#include<iostream>
using namespace std;

int binar_search(int left,int right,int key,int *val,int* a)
{
    int mid;
    if(key<=a[val[0]])///當值小於等於val的頭 ，val裡放的是 a陣列的index
        return 0;
    else if(key == a[val[right]])///當值等於val的最後一個值
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
    if(a[i]>=a[val[(*len)-1]])
    {
        temp = val[(*len)-1];
        val[(*len)++] = i;
        return temp;
    }
    else if(a[i]<a[val[(*len)-1]])
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
void print_LIS(int size,int *a,int *g,int *h,int n)
{
    int temp=-1,s[size],idx=0;
    cout<<"LIS: "<<size<<endl;
    for(int j=0;j<n;j++)
    {
        if(g[j] == size)
        {
            temp = j;
            s[idx++]= a[temp];
            break;
        }
    }
    while(h[temp]!=-1)
    {
        s[idx++] = a[h[temp]];
        temp = h[temp];
    }
    for(int i=idx-1;i>=0;i--)
        cout<<s[i]<<" ";
    cout<<endl;
}
int main()
{
     int n;
    while(cin>>n)
    {
        int a[n],f[n],g[n],val[n]={0},h[n],len=0,number;
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
            f[i] = len;
        }

        cout<<"f[i]: ";
        for(int i=0;i<n;i++) cout<<f[i]<<" ";
    
        cout<<"\ng[i]: ";
        for(int i=0;i<n;i++) cout<<g[i]<<" ";

        cout<<"\nval[i]: ";
        for(int i=0;i<n;i++) cout<<val[i]<<" ";

        cout<<"\nh[i]: ";
        for(int i=0;i<n;i++) cout<<h[i]<<" ";
        cout<<endl;
        
        while(cin>>number)
        {
            if(number==-1)
                break;
            if(number<n)
            {
                cout<<"Input: "<< number<<endl;
                print_LIS(f[number],a,g,h,n);
            }
        }
    }
    return 0;
}