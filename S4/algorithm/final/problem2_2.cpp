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

bool isSafe3D(vector<vector <int>> board,int N)//�n�ˬdn�Ӫ���+���k�צ泣���঳�ۦP�Ʀr
{
    if(N==0)
        return true;
    int i,j,flag;

    for(i=0; i<N; i++) //�ˬdn����
    {
        flag=(1<<N)-1;
        for(j=0; j<board.size(); j++)
        {
            if(!((1<<(board[j][i]-1))&flag))
                return false;
            flag-=1<<(board[j][i]-1);
        }
    }
    for(i=0; i<N; i++) //�ˬd�k�צ�
    {
        flag=(1<<N)-1;
        for(j=0; i+j<board.size(); j++)
        {
            if(!((1<<(board[j][i+j]-1))&flag))
                return false;
            flag-=1<<(board[j][i+j]-1);
        }
    }

    for(i=0; i<N; i++) //�ˬd���צ�
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
    if (col >= N)//����
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
    int n = 8;//1~8�i�ܧ֧�X�ѡA9�@�������k 11������ ��L�Ӥj
    nQueen(n);//�����Ҧ�2d-nqueen
    vector<vector<int> > nnQ;
    if(NNQ(nnQ,0,n))
        cout<<"����!";
    else
        cout<<"�L��";
    return 0;
}
