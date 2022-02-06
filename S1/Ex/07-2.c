#include<stdio.h>
int main()
{
    long long sum=0;
    char arr[4001];
    int last=0;
    scanf("%s",arr);
    for(int i=1;arr[i]!='\0';i+=2,last+=2)
        if(arr[i]=='+')
            sum+=(int)arr[i-1]-48;
        else
        {
            long long temp=1;
            for(;arr[i]!='+'&&arr[i]!='\0';i+=2,last+=2)
                temp*=(int)arr[i-1]-48;
            sum+=((int)arr[i-1]-48)*temp;
            if(arr[i]=='\0') break;
        }
    if(arr[last-1]=='+')
        sum+=arr[last]-48;
    printf("%lld",sum);
}
