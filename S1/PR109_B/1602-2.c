#include<stdio.h>
#include<math.h>

int main()
{
    char arr[10][300],num[100];
    int i,j,k,count,zoom,enter,z,z1;
    for(i=0;i<10;i++)
        scanf("%s",&arr[i]);
    count=strlen(arr[0]);
    if(count==64)
        enter=8;
    else
        enter=16;
    scanf(" %[^,],%d",&num,&zoom);



    for(i=0;i<enter;i++)
    {
    for(z=0;z<zoom;z++)
    {
        for(j=0;j<strlen(num);j++)
        {

            for(k=0;k<enter;k++)
            {
            for(z1=0;z1<zoom;z1++)
            {

                if(arr[num[j]-'0'][k+i*enter]=='0')
                printf("_");
            else
                printf("*");
            }
            }
            if(j!=strlen(num)-1)
            printf("___");

        }
        if(i!=enter-1||z!=zoom-1)
            printf("\n");
    }
    }
    return 0;
}
