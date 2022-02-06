#include<stdio.h>
main()
{
    int a,b,z=1,sum=0,temp=1,ans;
    char n;
    while(scanf("%c",&n)!=EOF)
    {
        if(n=='0')//輸入0時跳出迴圈
            break;
        if(n>58||n<48)//若輸入不是0~9的 則繼續讀取到完(只讀取不做任何事
            continue;
        else if(n>=48&&n<=57)//若第一個不為0 繼續讀取且累加數字
        {
            sum+=(n-48);
            for(;n>=48&&n<=57;)
            {
                if(n=='9')//是否有9
                temp=0;
                scanf("%c",&n);
                if(n>=48&&n<=57)
                    sum+=(n-48);
            }
        }
        ans=sum%9;//n是否為9的倍數
        if(ans!=0)
            printf("Not nines\n");
        else if(ans==0&&temp==0)
            printf("Nines\n");
        else if(ans==0&&temp==1)
            printf("Nines without nines\n");
        temp=1;
        sum=0;
    }
	return 0;
}
