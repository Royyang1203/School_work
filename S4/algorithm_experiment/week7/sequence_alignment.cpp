#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <set>

using namespace std;

class Sequence_Alignment
{
public:
    string A, B;
    int A_n, B_n;
    int cost_match;
    int cost_gap;
    int cost_mismatch;
    int **dp;
    set<pair<string, string>> res_set = {};

    void init(string _A, string _B, int _cost_match = 1, int _cost_gap = -4, int _cost_mismatch = -3)
    {
        A = _A;
        B = _B;
        cost_match = _cost_match;
        cost_gap = _cost_gap;
        cost_mismatch = _cost_mismatch;
        A_n = A.size();
        B_n = B.size();

        // Create alignment matrix
        dp = new int *[A_n + 1];
        for (int i = 0; i <= A_n; ++i)
        {
            dp[i] = new int[B_n + 1];
        }
    }

    pair<string, string> f(int i, int j)
    {
        if (i > 0 && j > 0 && g(i, j) == g(i - 1, j - 1) + p(i, j))
        {
            pair<string, string> res = f(i - 1, j - 1);
            res.first.push_back(A[i - 1]);
            res.second.push_back(B[j - 1]);
            return res;
        }
        else if (i > 0 && g(i, j) == g(i - 1, j) + cost_gap)
        {
            pair<string, string> res = f(i - 1, j);
            res.first.push_back(A[i - 1]);
            res.second.push_back('-');
            return res;
        }
        else if (j > 0 && g(i, j) == g(i, j - 1) + cost_gap)
        {
            pair<string, string> res = f(i, j - 1);
            res.first.push_back('-');
            res.second.push_back(B[j - 1]);
            return res;
        }
        return pair<string, string>("", "");
    }

    int g(int i, int j)
    {
        if (i == 0 || j == 0)
            return cost_gap * (i + j);
        else
            return max(max(dp[i - 1][j - 1] + p(i, j), dp[i - 1][j] + cost_gap), dp[i][j - 1] + cost_gap);
    }

    int p(int i, int j)
    {
        return A[i - 1] == B[j - 1] ? cost_match : cost_mismatch;
    }

    int aligment()
    {
        for (int i = 0; i <= A_n; ++i)
        {
            for (int j = 0; j <= B_n; ++j)
            {
                dp[i][j] = g(i, j);
            }
        }
        return dp[A_n][B_n];
    }

    void f_all(int i, int j, pair<string, string> post_fix = pair<string, string>("", ""))
    {
        // cout << i << " " << j << endl;
        if (i > 0 && j > 0 && g(i, j) == g(i - 1, j - 1) + p(i, j))
        {
            pair<string, string> res = post_fix;
            res.first.insert(0, 1, A[i - 1]);
            res.second.insert(0, 1, B[j - 1]);
            f_all(i - 1, j - 1, res);
        }
        if (i > 0 && g(i, j) == g(i - 1, j) + cost_gap)
        {
            pair<string, string> res = post_fix;
            res.first.insert(0, 1, A[i - 1]);
            res.second.insert(0, 1, '-');
            f_all(i - 1, j, res);
        }
        if (j > 0 && g(i, j) == g(i, j - 1) + cost_gap)
        {
            pair<string, string> res = post_fix;
            res.first.insert(0, 1, '-');
            res.second.insert(0, 1, B[j - 1]);
            f_all(i, j - 1, res);
        }
        if (i == 0 && j == 0)
        {
            res_set.insert(post_fix);
        }
        return;
    }

    void print_mtx()
    {
        for (int i = 0; i <= A_n; ++i)
        {
            if (i == 0)
            {
                cout << " " << setw(4) << "-";
                for (int j = 0; j < B_n; ++j)
                {
                    cout << setw(4) << B[j];
                }
                cout << endl;
            }
            if (i == 0)
                cout << "-";
            else
                cout << A[i - 1];
            for (int j = 0; j <= B_n; ++j)
            {
                cout << setw(4) << dp[i][j];
            }
            cout << endl;
        }
    }

    void print_all_align()
    {
        for (const auto &s : res_set)
        {
            cout << s.first << endl;
            cout << s.second << endl;
            cout << endl;
        }
    }
};

class Sequence_Alignment_efficient_2n
{
public:
    string A, B;
    int A_n, B_n;
    int cost_match = 1;
    int cost_gap = -4;
    int cost_mismatch = -3;
    int *dp;
    bool b = 0;

    void init(string _A, string _B, int _cost_match = 1, int _cost_gap = -4, int _cost_mismatch = -3)
    {
        A = _A;
        B = _B;
        cost_match = _cost_match;
        cost_gap = _cost_gap;
        cost_mismatch = _cost_mismatch;

        A_n = A.size();
        B_n = B.size();

        // Create alignment matrix
        dp = new int[(B_n + 1) * 2];
    }

    int g(int i, int j)
    {
        if (i == 0 || j == 0)
            return cost_gap * (i + j);
        else
            return max(max(dp[((i - 1) % 2) * (B_n + 1) + j - 1] + p(i, j),
                           dp[((i - 1) % 2) * (B_n + 1) + j] + cost_gap),
                       dp[(i % 2) * (B_n + 1) + j - 1] + cost_gap);
    }

    int p(int i, int j)
    {
        return A[i - 1] == B[j - 1] ? cost_match : cost_mismatch;
    }

    int aligment()
    {
        for (int i = 0; i <= A_n; ++i)
        {
            for (int j = 0; j <= B_n; ++j)
            {
                dp[(i % 2) * (B_n + 1) + j] = g(i, j);
            }
        }
        return dp[(A_n % 2) * (B_n + 1) + B_n];
    }
};

class Sequence_Alignment_efficient
{
public:
    string A, B;
    int A_n, B_n;
    int cost_match = 1;
    int cost_gap = -4;
    int cost_mismatch = -3;
    int *dp;
    bool b = 0;

    void init(string _A, string _B, int _cost_match = 1, int _cost_gap = -4, int _cost_mismatch = -3)
    {
        A = _A;
        B = _B;
        cost_match = _cost_match;
        cost_gap = _cost_gap;
        cost_mismatch = _cost_mismatch;

        A_n = A.size();
        B_n = B.size();

        // Create alignment matrix
        dp = new int[(B_n + 1)];
    }

    int p(int i, int j)
    {
        return A[i - 1] == B[j - 1] ? cost_match : cost_mismatch;
    }

    int aligment()
    {
        int cur, prev;
        for (int i = 0; i <= A_n; ++i)
        {
            for (int j = 0; j <= B_n; ++j)
            {
                prev = cur;
                cur = dp[j];
                if (i == 0 || j == 0)
                    dp[j] = cost_gap * (i + j);
                else
                    dp[j] = max(max(prev + p(i, j),
                                    cur + cost_gap),
                                dp[j - 1] + cost_gap);
            }
        }
        return dp[B_n];
    }
};

int main()
{
    string A, B;
    // cin >> A >> B;
    A = "AGCA";
    B = "XGCXXGCX";
    // A = "ATGGCCTC";
    // B = "ACGGCTC";
    // A = "ABC";
    // B = "XD";

    int cost_match = 1;
    int cost_gap = -4;
    int cost_mismatch = -3;

    // cin >> cost_match >> cost_gap << cost_mismatch;

    Sequence_Alignment s;
    s.init(A, B, cost_match, cost_gap, cost_mismatch);
    cout << s.aligment() << endl;
    s.print_mtx();
    // pair<string, string> res = s.f(4, 8);
    // cout << res.first << endl
    //      << res.second;
    // s.f_all(3, 2);
    // s.print_all_align();

    Sequence_Alignment_efficient se;
    se.init(A, B, cost_match, cost_gap, cost_mismatch);
    cout << se.aligment() << endl;
    // se.print();
}