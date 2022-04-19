/*利用二分法來找出最大的pie size*/
#include<iostream>
#include<cmath>
using namespace std;
const double PI = acos(-1);
const double error = 1e-6;
bool binary_method(double mid,double* cake_size,int cake,int friends)
{
    int person=0;
    
    for(int i=0;i<cake;i++)
        person+= cake_size[i]/mid;

    return person >= friends+1;
}

int main()
{
    int test,cake,friends,radix;
    //double answer[100]={0};
    cin>>test;
    //int k=0;
    for(int k=0;k<test;k++)
    {
        cin>>cake>>friends;
        double cake_size[cake],max=-1;
        for(int i=0;i<cake;i++)
        {
            cin>>radix;
            cake_size[i] = PI * radix *radix;   
            if(cake_size[i]>max) max = cake_size[i];
        }

        double lower=0,upper=max,mid=0;

        while((upper-lower)>error)//****主要的部份
        {
            mid = (lower+upper)/2;
            if(binary_method(mid,cake_size,cake,friends))
                lower = mid;
            else
                upper = mid;
        }
        printf("%.4lf\n",mid);
    }
    /*for(int i =0;i<100;i++)
        printf("%.4lf\n",answer[i]);*/
    return 0;
}   