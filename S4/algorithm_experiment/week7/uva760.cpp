#include <iostream>
#include <bits/stdc++.h>

#define N 2000
using namespace std;

// id = 舊的 sa 排名 , cnt 在 radix sort 時幫助
// sa[i] 依字典序第 i 大的後綴字串 在源自串的位置,id[i]為舊sa排名
// rk[i] 在源自串第i個字在字典序的排名, oldrk[i]為舊rk排名
// cnt在radix sort中用counting sort排序單個位元的矩陣
int sa[N], rk[2 * N], oldrk[2 * N], id[N], cnt[N];
// n 字串長度 , m 文字的最大長度
int n, m, maxn, lenA, lenB, flag = 0;
// 要進行 suffix array 的字串，請記住這裡的字串第一個 index 為 1
string strA = "", strB = "";

// build suffix array
void build_sa()
{
    int i, m, p, w;
    // 在這邊把常在迴圈使用的變數名稱拉出來宣告，以避免不斷宣告造成的效率浪費
    n = strA.length() - 1;       // 減去 string[0] 的空格
    m = max(n, 300);             // 由於 ascii 上限是 255，我們這邊直接開 300
    memset(cnt, 0, sizeof(cnt)); // 重設 cnt 陣列
    memset(rk, 0, sizeof(rk));   // 重設 rk 陣列

    for (i = 1; i <= n; ++i)
        ++cnt[rk[i] = (int)strA[i]];
    // rk[i] = (int) strA[i] 每一個字元在字串中排名
    //++cnt[rk[i] = (int)strA[i]] radix sort 分類
    for (i = 1; i <= m; ++i)
        cnt[i] += cnt[i - 1];
    //將 cnt 遞增排序方便之後找出數值排在第幾位
    for (i = n; i >= 1; --i)
        sa[cnt[rk[i]]--] = i;
    // cnt[rk[i]] 先找出字元在字串中排名再透過 cnt 找出他應該排在第幾位
    // 隨後進行 cnt[rk[i]]--，方便下一個值得排序位置。

    // 倍增排序
    for (w = 1; w < n; w <<= 1)
    {
        memset(cnt, 0, sizeof(cnt)); // 第一次 radix sort 開始，排序關鍵為後者
        for (i = 1; i <= n; i++)
            id[i] = sa[i];
        // id 用來記錄現在排序的順序，配合這次的 radix sort 再進行更動
        for (i = 1; i <= n; i++)
            ++cnt[rk[id[i] + w]];
        for (i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; i--)
            sa[cnt[rk[id[i] + w]]--] = id[i];
        // radix sort 與一開始相同，只是多增加 w，因為排序關鍵為後者
        // 第一次 radix sort 結束

        // 第二次 radix sort 開始，排序關鍵為前者
        memset(cnt, 0, sizeof(cnt));
        for (i = 1; i <= n; i++)
            id[i] = sa[i];
        for (i = 1; i <= n; i++)
            ++cnt[rk[id[i]]];
        for (i = 1; i <= m; i++)
            cnt[i] += cnt[i - 1];
        for (i = n; i >= 1; i--)
            sa[cnt[rk[id[i]]]--] = id[i];
        // 第二次 radix sort 結束

        // 根據 radix sort 在排列一次 rank
        memcpy(oldrk, rk, sizeof(rk)); //複製 rank 來幫助 rank 間的交換
        for (p = 0, i = 1; i <= n; i++)
        { // p 為 rank 的等級，i 則是資料
            if (oldrk[sa[i]] == oldrk[sa[i - 1]] &&
                oldrk[sa[i] + w] == oldrk[sa[i - 1] + w])
                // 如果與前一個 rank 值是相同則理應現在應該也要相同
                rk[sa[i]] = p; // rank 字典排序不變
            else
                rk[sa[i]] = ++p; // rank 字典排序增加
        }
    }
}

void build_lcp()
{
    int lcp[N] = {};
    int max_lcp = 0; // max_lcp 最大長度
    // k 為現在 i 名的後綴與前一名後綴長度算出的最長共同前綴
    for (int i = 1, k = 0; i <= n; i++)
    {
        if (k)
            k--;
        // 由於我們下次是把字串 index 在往後一個 index，所以 lcp 最差的情況則會是 x-1
        // 因為其實要比較的字串只是刪除上一個後綴的第一個字元

        while (strA[i + k] == strA[sa[rk[i] - 1] + k])
            ++k;
        //比較順序較為特殊，因為他每個陣列都可以分開進行討論，
        //於是我們比較字串的 index 開始的後綴與他的 sa 前一項找出 lcp
        // 由於 sa[rk[i]] = rk[sa[i]] = i,
        // strA[i] = 字串的 index 開始的後綴
        // strA[i] 的 suffix array 之 sa[] 應為 sa[rk[i]]
        //所以其前一項 sa[] 是 sa[rk[i] - 1]
        // 而 k 個代表要比這兩組後綴的第 k 個
        // while 裡面的 +k 則是減少重複比較，如果上次的 lcp 已經找出長度為 x 的 lcp

        lcp[rk[i]] = k;
    }

    // 因為我們將兩個字串合在一起，所以可能會比較到同個字串內的lcp
    // 所以要塞選兩個字串一個在A的範圍一個在B的範圍，且其為有效後綴
    for (int i = 1; i <= n; i++)
    {
        if ((sa[i] < lenA && sa[i - 1] < n + 1 && sa[i - 1] > lenA) ||
            (sa[i] > lenA && sa[i - 1] < n + 1 && sa[i - 1] < lenA))
            max_lcp = max(max_lcp, lcp[i]);
    }

    if (flag) // 確認是第幾筆資料，是否中間要空行
        cout << '\n';
    flag = 1;

    map<string, int> mp;
    if (max_lcp == 0)
    {
        cout << "No common sequence.\n";
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if ((sa[i] < lenA && sa[i - 1] < n + 1 && sa[i - 1] > lenA) ||
            (sa[i] > lenA && sa[i - 1] < n + 1 && sa[i - 1] < lenA))
            if (lcp[i] == max_lcp)
            {
                string temp = strA.substr(sa[i], max_lcp);
                if (mp[temp])
                    continue;
                else
                    mp[temp] = 1;
                cout << temp << '\n';
            }
    }
}

int main()
{
    while (cin >> strA >> strB)
    {
        lenA = strA.length() + 1;
        lenB = strB.length();
        strA = ' ' + strA + '$' + strB + '#';

        build_sa();
        build_lcp();
    }
    return 0;
}
