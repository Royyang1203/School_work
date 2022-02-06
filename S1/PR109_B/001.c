#include<stdio.h>
int main ()
{
    int a[10000],b[10000],p[10000],i=0,c=0,d=0,e=0,X,Y,x,y,h=0,t;
    // [1] start
    while(scanf("%d %d",&x,&y) && x!=0 && y!=0)
    {
        if(y>x){
            t=x;x=y;y=t;
        }
        X=x; Y=y;

        while(x>=1)
        {
            x=x/10;
            c++;
        }

        while(y>=1)
        {
            y=y/10;
            d++;
        }

        if(d>=c)
            e=d;
        else
            e=c;

        for(i=e; i>=1; i--)
        {
            a[i]=X%10;
            X=X/10;

        }
        for(i=e; i>=1; i--)
        {
            b[i]=Y%10;
            Y=Y/10;
        }

        for(i=e; i>=1; i--){
            p[i]=p[i]+a[i];
        }
        for(i=e; i>=1; i--){
            p[i]=p[i]+b[i];
        }

        for(i=e; i>=1; i--){
            while(p[i]>=10){
                p[i]=p[i]-10;
                h++;
                p[i-1]=p[i-1]+1;
            }
        }

        printf("%d\n",h);
        for(int i=0; i<=e;i++)
            p[i]=0;
        h=0;c=0;d=0;e=0;

    }
    return 0;
}
