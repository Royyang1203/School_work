#include<stdio.h>
main()
{
    int a,b,z=1,sum=0,temp=1,ans;
    char n;
    while(scanf("%c",&n)!=EOF)
    {
        if(n=='0')//��J0�ɸ��X�j��
            break;
        if(n>58||n<48)//�Y��J���O0~9�� �h�~��Ū���짹(�uŪ�����������
            continue;
        else if(n>=48&&n<=57)//�Y�Ĥ@�Ӥ���0 �~��Ū���B�֥[�Ʀr
        {
            sum+=(n-48);
            for(;n>=48&&n<=57;)
            {
                if(n=='9')//�O�_��9
                temp=0;
                scanf("%c",&n);
                if(n>=48&&n<=57)
                    sum+=(n-48);
            }
        }
        ans=sum%9;//n�O�_��9������
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
