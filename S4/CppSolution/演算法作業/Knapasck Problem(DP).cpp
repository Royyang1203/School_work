#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int budget_cap, n_item;
    cin >> budget_cap >> n_item;

    int preferences[n_item], weight[n_item], DP_table[n_item + 1][budget_cap + 1];
    for (int i = 0; i < n_item; i++)
        cin >> preferences[i];
    for (int i = 0; i < n_item; i++)
        cin >> weight[i];

    for (int i = 0; i <= n_item; i++)
        for (int j = 0; j <= budget_cap; j++)
            DP_table[i][j] = 0;

    int idx = 0;
    for (int i = 1; i <= n_item; i++, idx++)
        for (int j = 1; j <= budget_cap; j++)
        {
            if (weight[idx] > j)
                DP_table[i][j] = DP_table[i - 1][j];
            else // weight[idx] <=j
                DP_table[i][j] = max(DP_table[i - 1][j - weight[idx]] + preferences[idx], DP_table[i - 1][j]);
        }
        
    cout <<"Max: " << DP_table[n_item][budget_cap]<<endl;
    
    for (int i = n_item, j = budget_cap; i >= 0; --i,idx--)
        if ( weight[idx-1]<= j  && DP_table[i][j] == DP_table[i-1][j - weight[idx-1]] + preferences[idx-1])
        {
            cout << "have:" << i <<"th item"<<endl;
            j -= weight[idx-1];
        }
}