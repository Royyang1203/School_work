char *replace(char *source, char const *pattern, char const *replacement)
{
    static char arr[10000],ram[10000],*m;

    int j=0,k,lpa,lre,temp=0;
    static char *i,*n;
    static int lso, count=0,a,mc;
    lpa=strlen(pattern);
    lre=strlen(replacement);


    if(source!=NULL)
    {
        i=n=source;
        lso=strlen(source);
        count=0;
        a=0;
    }
    else
    {
        source=n;
        a=count=mc;
    }
    temp=0;
    for(i=n+a;*i!='\0';i++)//
    {
        if(*i == pattern[0] && j >= 0)
        {
            j=0;
            for(k=0,m=i;k<lpa;m++,k++)
            {
                if(*m!=pattern[k])
                    j=1;
            }
            if(j==0)
            {
                for(k=0;k<lre;k++)
                {
                    arr[count]=replacement[k];
                    count++;
                }
                i+=lpa-1;
                j=-1;
                a=i-n;
                mc=count;
                continue;

            }
        }
        arr[count]=*i;
        count++;
    }
    if(temp!=0)
        {
            for(j=temp;j>=0;j--)
            {
                arr[count]=ram[j];
                count++;
            }
        }
    arr[count]='\0';
    for(i=n,j=0;i<n+lso+count+1;i++,j++)
    {
        source[j]=arr[j];
    }
    return source;
}
