#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a1 ="algorithms",a2="alchemist";
    int dp_table[a1.size()+1][a2.size()+1];

    for(unsigned int i=0;i<=a1.size();i++)
        for(unsigned int j=0;j<=a2.size();j++)
            dp_table[i][j] = 0;   

     for(unsigned int i=1;i<=a1.size();i++)
    {
        for(unsigned int j=1;j<=a2.size();j++)
        {
            if(a1[i-1]==a2[j-1])
                dp_table[i][j] = dp_table[i-1][j-1]+1;
            else
                dp_table[i][j] = max(dp_table[i-1][j],dp_table[i][j-1]);    
        }
    }
    for(unsigned int i=1;i<=a1.size();i++)
    {
        for(unsigned int j=1;j<=a2.size();j++)
            cout<<dp_table[i][j]<<" ";
        cout<<endl;
    }
}