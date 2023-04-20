#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > nQ;

bool isSafe2D(vector<vector<int> > board,
              int row, int col)
{
    int i, j;
    int N = board.size();
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool allNQ(vector<vector<int> >& board, int col)
{
    int N = board.size();
    if (col == N)
    {
        vector<int> v;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 1)
                    v.push_back(j + 1);
            }
        }
        nQ.push_back(v);
        return true;
    }
    bool res = false;
    for (int i = 0; i < N; i++)
    {
        if (isSafe2D(board, i, col))
        {
            board[i][col] = 1;
            res = allNQ(board, col + 1) || res;
            board[i][col] = 0; // BACKTRACK
        }
    }
    return res;
}

void nQueen(int n)
{
    nQ.clear();
    vector<vector<int> > board(n, vector<int>(n, 0));
    if (allNQ(board, 0) == false)
        return ;
    sort(nQ.begin(), nQ.end());
}

bool isSafe3D(vector<vector <int>> board,int N)//要檢查n個直排+左右斜行都不能有相同數字
{
    if(N==0)
        return true;
    int i,j,flag;

    for(i=0; i<N; i++) //檢查n直行
    {
        flag=(1<<N)-1;
        for(j=0; j<board.size(); j++)
        {
            if(!((1<<(board[j][i]-1))&flag))
                return false;
            flag-=1<<(board[j][i]-1);
        }
    }
    for(i=0; i<N; i++) //檢查右斜行
    {
        flag=(1<<N)-1;
        for(j=0; i+j<board.size(); j++)
        {
            if(!((1<<(board[j][i+j]-1))&flag))
                return false;
            flag-=1<<(board[j][i+j]-1);
        }
    }

    for(i=0; i<N; i++) //檢查左斜行
    {
        flag=(1<<N)-1;
        for(j=0; i-j>=0 && j< board.size(); j++)
        {
            if(!((1<<(board[j][i-j]-1))&flag))
                return false;
            flag-=1<<(board[j][i-j]-1);
        }
    }
    return true;
}

bool NNQ(vector<vector <int>> &board, int col,int N)
{
    if (col >= N)//找到解
    {
        for(int i=0; i<N; i++)
        {
            cout<<"[";
            for(int j=0; j<N; j++)
            {
                cout<<board[i][j]<<" ";
            }
            cout<<"]"<<endl;
        }
        return true;
    }

    for (int i = 0; i < nQ.size(); i++)
    {
        board.push_back(nQ[i]);
        if (isSafe3D(board,N))
        {
            if (NNQ(board, col + 1,N))
                return true;
        }
        board.pop_back(); // BACKTRACK
    }
    return false;
}

// Driver Code
int main()
{
    int n = 8;//1~8可很快找出解，9一分鐘左右 11約五秒內 其他太大
    nQueen(n);//先找到所有2d-nqueen
    vector<vector<int> > nnQ;
    if(NNQ(nnQ,0,n))
        cout<<"有解!";
    else
        cout<<"無解";
    return 0;
}
