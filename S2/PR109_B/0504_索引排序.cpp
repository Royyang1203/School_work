// Description

// 現有兩個一樣長的陣列，一為 keys；一為 vals。每個 key 都會對應到固定的 val。請實作 function 可將 keys 由小至大排序，並維持 key 和 val 的對應。

// 本題所有測試的 class 都一定支援 < 比較子。
#include <iostream>
#include <algorithm>
using namespace std;
template <typename KeyT, typename ValT>
void sort_by(KeyT keys[], ValT vals[], int len)
{
    for (int i = 0; i < len; ++i)
        for (int j = 1; j < len; ++j)
            if (keys[j] < keys[j - 1])
            {
                swap(keys[j], keys[j - 1]);
                swap(vals[j], vals[j - 1]);
            }
}