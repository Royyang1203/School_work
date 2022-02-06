#include<stdio.h>
#include<string.h>
#include<math.h>

void change(char *arr,int k)
{
    int a=k,temp,i,b;
    for(temp=0;k!=0;k/=10,temp++);
    for(i=0;i<temp;i++)
    {
        b=pow(10,temp-i-1);
        *(arr+i)=a/b+'0';
        a=a%b;
    }
}

int F(int x)
{
    return x+1;
}
int G(int x,int y)
{
    return x+y;
}

int main()
{
    int x,y,n=0;
    char arr[100];
    int i,j,k,count=0,temp=0;
    gets(arr);
    for(i=0;i<strlen(arr);i++)
        if(arr[i]=='(')
            count=i;

    for(i=count;i>=0;i--)
    {
        if(arr[i]=='F')
        {
            n=1;
            x=0;
            temp=0;
            for(j=i;arr[j]!=')';j++);//找到右括號位置
            right=j;
            for(;arr[j]!='(';j--)
            {
                if(arr[j]=='x')
                {
                    x=k;
                    break;
                }

                if(isdigit(arr[j]))
                {
                    x+=(arr[j]-'0')*pow(10,temp);
                    temp++;
                }
                arr[j]=' ';
            }
            arr[j]=' ';
            arr[j-1]='x';
            k=F(x);
            change(arr+j-1,k);
            printf("k=%d\n",k);
        }
        if(arr[i]=='G')
        {
            n=1;
            x=0;
            temp=0;
            for(j=i;arr[j]!=')';j++);//找到右括號位置
            for(j=j;arr[j]!=',';j--)
            {
                if(arr[j]=='x')
                {
                    x=k;
                    break;
                }

                if(isdigit(arr[j]))
                {
                    x+=(arr[j]-'0')*pow(10,temp);
                    temp++;
                }
                arr[j]=' ';
            }
            arr[j]=' ';
            temp=0;
            y=0;
            for(j=j;arr[j]!='(';j--)
            {
                if(arr[j]=='x')
                {
                    y=k;
                    break;
                }

                if(isdigit(arr[j]))
                {
                    y+=(arr[j]-'0')*pow(10,temp);
                    temp++;
                }
                arr[j]=' ';
            }
            arr[j]=' ';
            arr[j-1]='x';
            k=G(x,y);
            change(arr+j-1,k);
            printf("k=%d\n",k);
        }

       printf("%s\n",arr);
    }
    if(n==0)
        printf("%s",arr);
    else
        printf("%d",k);
 return 0;
}
