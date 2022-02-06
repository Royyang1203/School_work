#include <iostream>
class Nurikabe
{
public:
    /*
    n is the size of the Nurikabe, n >= 5, n <= 20
    game is the result from some player
    here is one example
    n: 5
    game = { {'W', 'W', 'W', '1', 'W'},
             {'W', '.', 'W', 'W', 'W'},
             {'W', '2', 'W', '.', '3'},
             {'3', 'W', 'W', '.', 'W'},
             {'.', '.', 'W', 'W', 'W'} };
    W represent wall
    */
    Nurikabe(char game[20][20], int n)
    {
        kabesize = n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                kabe[i][j] = game[i][j];
    }
    /*
    return 1 if result fit the rule.
    return 0 if result not fit the rule.
    */
    int isCorrect()
    {
        int i, j, wi, wj;
        for (i = 0; i < kabesize; i++)
        {
            for (j = 0; j < kabesize; j++)
            {
                //std::cout<<i<<"  "<<j<<std::endl;/////////////////
                if (kabe[i][j] == 'W' && (i < kabesize - 1 && j < kabesize - 1) && (kabe[i + 1][j] == 'W' && kabe[i][j + 1] == 'W' && kabe[i + 1][j + 1] == 'W'))
                    return 0;
                if (!check(i, j))
                    return 0;
            }
        }

        for (i = 0; i < kabesize; i++)
            for (j = 0; j < kabesize; j++)
                if (kabe[i][j] == 'W')
                {
                    wi = i;
                    wj = j;
                    i = j = 20;
                }

        wall_recursion(wi, wj);
        //print();

        for (i = 0; i < kabesize; i++)
            for (j = 0; j < kabesize; j++)
                if (kabe[i][j] == '.' || isdigit(kabe[i][j]) || kabe[i][j] == 'W')
                    return 0;
        return 1;
    }
    void print()
    {
        int i, j;
        for (i = 0; i < kabesize; i++)
        {
            for (j = 0; j < kabesize; j++)
            {
                std::cout << kabe[i][j];
            }
            std::cout << std::endl;
        }
    }

private:
    //請設計你自己的資料結構來儲存遊戲的結果
    //Please design your own data structure to keet the result
    int kabesize, connect_count, num_count;
    char kabe[20][20];
    bool check(int curi, int curj)
    {
        if (!isdigit(kabe[curi][curj]))
            return true;
        connect_count = num_count = 0;
        int curnum = kabe[curi][curj] - '0';
        //std::cout<<"\ncurnum="<<curnum<<std::endl;//////////////////
        recursion(curi, curj);
        //std::cout<<"\nconnect_count="<<connect_count<<std::endl;////////////////
        if (curnum == connect_count)
            return true;
        return false;
    }

    void recursion(int rei, int rej)
    {
        if (rei >= kabesize || rej >= kabesize || rei < 0 || rej < 0 || kabe[rei][rej] == 'W' || kabe[rei][rej] == 'X')
            return;
        if (isdigit(kabe[rei][rej]))
            num_count++;
        if (num_count > 1)
        {
            connect_count = -1;
            return;
        }

        kabe[rei][rej] = 'X';
        //std::cout<<"\n---------------------------\n";
        //print();//////////////
        connect_count++;
        recursion(rei, rej - 1);
        recursion(rei - 1, rej);
        recursion(rei, rej + 1);
        recursion(rei + 1, rej);
    }

    void wall_recursion(int rei, int rej)
    {
        if (rei >= kabesize || rej >= kabesize || rei < 0 || rej < 0 || kabe[rei][rej] != 'W')
            return;
        kabe[rei][rej] = 'X';
        wall_recursion(rei, rej - 1);
        wall_recursion(rei - 1, rej);
        wall_recursion(rei, rej + 1);
        wall_recursion(rei + 1, rej);
    }
};
int main()
{
    int n, j, l, k;
    n = 5;
    char game[20][20] =
        {{'W', 'W', 'W', '1', 'W'},
         {'W', '.', 'W', 'W', 'W'},
         {'W', '2', 'W', '.', '2'},
         {'3', 'W', 'W', 'W', 'W'},
         {'.', '.', 'W', '1', 'W'}};

    std::cin >> n;
    for (j = 0; j < n; j++)
        for (k = 0; k < n; k++)
            std::cin >> game[j][k];

    Nurikabe *a = new Nurikabe(game, n);
    std::cout << a->isCorrect();
    a->print();
    return 0;
}