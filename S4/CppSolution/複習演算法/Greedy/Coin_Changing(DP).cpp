#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
# define INF 9999
// 題目:換到等值且最少硬幣數量
// https://www.youtube.com/watch?v=RLHdKeduVzY 教學影片
/*不想用greedy，因為不適合所有的case，greedy是選擇當下最好的結果，但不代表就最終的結果一定是最好的。
    例如: coin={1,8,13}, 要換16cents;
    那greedy只會一昧的選擇幣額最大的coin，所以會先選13，所以最後的結果會是13+1+1+1，但其實最好的結果應該是8+8。*/
int main()
{
   int coin[]={2,1,3,4};
   int n = sizeof(coin)/sizeof(coin[0]);
   int total=6;
   int dp_table[n+1][total+1];

    for(int i=0;i<=n;i++) dp_table[i][0] = 0;
    for(int j=0;j<=total;j++) dp_table[0][j] = INF;

    for(int i=1,idx=0;i<=n;i++,idx++)
        for(int j=1;j<=total;j++)  
        {
            if(coin[idx]>j)
                dp_table[i][j] = dp_table[i-1][j];
            else
                dp_table[i][j] = min(dp_table[i][j-coin[idx]]+1,dp_table[i-1][j]); //不像是背包問題看前一列的最佳解，而是看同列的最佳解，因為硬幣可以重複拿。
                                                                                //0/1背包問題只能拿一個所以只能看前一列最佳解。
        } 

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=total;j++) printf("%5d ",dp_table[i][j]);
        cout<<endl;
    }  

}