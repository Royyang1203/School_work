// 字典樹 - Google 搜尋

// 字典樹的介紹請參閱上面的連結

// trie - Google search

// Please reference the link above to see the definition of Trie

// 請自行設計並實作一棵字典樹並完成下列的要求

// Please design and implement a Trie fulfill the request below.

// Input
// 一開始會有兩個整數，n 跟 m ，接下來會有 n 行，每行代表一個單字，用這 n 個單字來建構字典樹。再接下來會有 m 行，每行代表一個單字，請檢查這 m 個單字是否存在。

// Input start with two integer n and m, fellow by n line. Each line is a word, create a trie with the n word. Next m line, each line is a word, check if the word exists in trie,

// Output
// 存在的話輸出 1 ，不存在則輸出 0。

// output 1 if the word is exist, output 0 if not.

#include <string>
#include <iostream>

class Trie
{
private:
    bool flag = false;
    Trie *next[26] = {nullptr};

public:
    Trie() = default;

    void insert(const std::string &word)
    {
        Trie *node = this;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (node->next[c - 'a'] == nullptr)
            {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        node->flag = true;
    }

    bool search(const std::string &word)
    {
        Trie *node = this;
        for (int i = 0; i < word.length(); i++)
        {
            char c = word[i];
            if (node->next[c - 'a'] == nullptr)
                return false;
            node = node->next[c - 'a'];
        }
        return node->flag;
    }
};

using namespace std;

int main()
{
    Trie *t = new Trie();
    int n, m;
    cin >> n >> m;
    string ss;

    for (int i = 0; i < n; ++i)
    {
        cin >> ss;
        t->insert(ss);
    }

    for (int i = 0; i < m; ++i)
    {
        cin >> ss;
        cout << t->search(ss) << endl;
    }
}