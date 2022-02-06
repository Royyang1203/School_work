// Description

// 在開始這周的問題之前，我要先跟大家介紹一款遊戲，塗牆，關於這款遊戲的規則你可以在這個網站裡找到。

// 塗牆 - 線上解謎遊戲 (puzzle-nurikabe.com)

// Before i explain the question for this week, i am going to introduction a puzzle for you, Nurikabe, you can find all the detail on this website

// Nurikabe - online puzzle game (puzzle-nurikabe.com)

// 這個禮拜的作業是請你們完成我提供的樣板，讓程式能判斷玩家的答案是否符合塗牆的規則。

// Please finish the template that i provide, make it able to determine if the result fit the rule or not.

// 請務必在 2021/12/02 前上傳你的程式碼並且找 TA demo 完。

// The submission and demonstration due to 2021/12/02.

// #include <iostream>
// class Nurikabe
// {
// public:
//   /*
//   n is the size of the Nurikabe, n >= 5, n <= 20
//   game is the result from some player
//   here is one example
//   n: 5
//   game = { {'W', 'W', 'W', '1', 'W'},
//            {'W', '.', 'W', 'W', 'W'},
//            {'W', '2', 'W', '.', '3'},
//            {'3', 'W', 'W', '.', 'W'},
//            {'.', '.', 'W', 'W', 'W'} };
//   W represent wall
//   */
//   Nurikabe(char game[20][20], int n)
//   {
//   }
//   /*
//   return 1 if result fit the rule.
//   return 0 if result not fit the rule.
//   */
//   int isCorrect()
//   {
//   }
// private:
//   //請設計你自己的資料結構來儲存遊戲的結果
//   //Please design your own data structure to keet the result
// };
// int main() {
//   int n, j, l, k;
//   char game[20][20] = { {'W', 'W', 'W', '1', 'W'},
//                        {'W', '.', 'W', 'W', 'W'},
//                        {'W', '2', 'W', '.', '3'},
//                        {'3', 'W', 'W', '.', 'W'},
//                        {'.', '.', 'W', 'W', 'W'} };
//   std::cin>>n;
//   for(j = 0;j < n;j ++)
//     for(k = 0;k < n;k ++)
//       std::cin>>game[j][k];
//   Nurikabe *a = new Nurikabe(game, n);
//   std::cout<<a->iscorrect();
//   return 0;
// }

#include <iostream>
#include <queue>
#include <utility>
#include <iomanip>
// #define TEST

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
    Nurikabe(int game[20][20], int _n) : size(_n)
    {
        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < 20; ++j)
            {
                if (i < size && j < size)
                {
                    maze[i][j] = game[i][j];
                }
                else
                    maze[i][j] = 0;
                visit[i][j] = false;
            }
        }
    }
    Nurikabe(char game[20][20], int _n) : size(_n)
    {
        for (int i = 0; i < 20; ++i)
        {
            for (int j = 0; j < 20; ++j)
            {
                if (i < size && j < size)
                {
                    if (game[i][j] == 'W')
                        maze[i][j] = -1;
                    else if (game[i][j] == '.')
                        maze[i][j] = -2;
                    else if (game[i][j] >= '1' && game[i][j] <= '9')
                        maze[i][j] = game[i][j] - '0';
                }
                else
                    maze[i][j] = 0;
                visit[i][j] = false;
            }
        }
    }
    /*
    return 1 if result fit the rule.
    return 0 if result not fit the rule.
    */
    int is_correct()
    {

        bool check_river = false;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (!check_river && maze[i][j] == -1)
                {
                    check_river = true;
                    connect_river(i, j);
                }
                if (maze[i][j] >= 1 && !_is_island(i, j)) // 此島嶼是否合理
                {
                    return 0;
                }
                else if (maze[i][j] == -1 && is_lake(i, j)) // 是否為湖泊
                {
#ifdef TEST
                    std::cout << "( exist lake at (" << i << ", " << j << ")) ";
#endif
                    return 0;
                }
            }
        }
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (visit[i][j] == false)
                {
#ifdef TEST
                    std::cout << "( there are more than one river in maze or there exist hidden island ) ";
#endif
                    return 0;
                }
            }
        }
        return 1;
    }

    void print_maze()
    {
        std::cout << "maze size -> " << size << std::endl;

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (maze[i][j] == -1)
                    std::cout << std::setw(3) << "#";
                else if (maze[i][j] == -2)
                    std::cout << std::setw(3) << "*";
                else
                    std::cout << std::setw(3) << maze[i][j];
            }
            std::cout << std::endl;
        }
    }

private:
    bool _is_island(int r, int c)
    {
        const int dir_r[4] = {0, 1, 0, -1};
        const int dir_c[4] = {-1, 0, 1, 0};

        int num = maze[r][c];
        std::queue<std::pair<int, int>> que;
        que.push(std::pair<int, int>(r, c));
        visit[r][c] = true;

        while (!que.empty())
        {
            std::pair<int, int> cur = que.front();

            if (--num < 0)
                break;

            for (int i = 0; i < 4; ++i)
            {
                int next_r = cur.first + dir_r[i];
                int next_c = cur.second + dir_c[i];
                if (!is_inmaze(next_r, next_c) || visit[next_r][next_c] == true)
                    continue;
                else if (maze[next_r][next_c] >= 1) // 兩座島嶼相連
                {
#ifdef TEST
                    std::cout << "( two island connected at (" << cur.first << ", " << cur.second << ")) ";
#endif
                    return false;
                }
                else if (maze[next_r][next_c] == -2)
                {
                    que.push(std::pair<int, int>(next_r, next_c));
                    visit[next_r][next_c] = true;
                }
            }
            que.pop();
        }
        if (num != 0)
        {
#ifdef TEST
            std::cout << "( island size is wrong ) ";
#endif
            return false;
        }
        return true;
    }
    bool is_lake(int r, int c)
    {
        if (r == size - 1 || c == size - 1)
            return false;
        return maze[r + 1][c] == -1 && maze[r][c + 1] == -1 && maze[r + 1][c + 1] == -1;
    }
    void connect_river(int r, int c)
    {
        const int dir_r[4] = {0, 1, 0, -1};
        const int dir_c[4] = {-1, 0, 1, 0};

        std::queue<std::pair<int, int>> que;
        que.push(std::pair<int, int>(r, c));

        while (!que.empty())
        {
            std::pair<int, int> cur = que.front();
            visit[cur.first][cur.second] = true;

            for (int i = 0; i < 4; ++i)
            {
                int next_r = cur.first + dir_r[i];
                int next_c = cur.second + dir_c[i];
                if (!is_inmaze(next_r, next_c) || visit[next_r][next_c] == true)
                    continue;
                else if (maze[next_r][next_c] == -1) // 為同一條河流
                {
                    que.push(std::pair<int, int>(next_r, next_c));
                }
            }
            que.pop();
        }
    }
    bool is_inmaze(int r, int c)
    {
        return r >= 0 && c >= 0 && r < size && c < size;
    }

    //請設計你自己的資料結構來儲存遊戲的結果
    //Please design your own data structure to keet the result
    int maze[20][20]; // -1代表河流 -2 代表島嶼
    bool visit[20][20];
    int size = 0;
};

int main()
{
    int n, j, l, k;
    char game[20][20] = {{'W', 'W', 'W', '1', 'W'},
                         {'W', '.', 'W', 'W', 'W'},
                         {'W', '2', 'W', '.', '3'},
                         {'3', 'W', 'W', '.', 'W'},
                         {'.', '.', 'W', 'W', 'W'}};
    std::cin >> n;
    for (j = 0; j < n; j++)
        for (k = 0; k < n; k++)
            std::cin >> game[j][k];

    // int game[20][20] = {{-1, -1, -1, 1, -1},
    //                     {-1, -2, -1, -1, -1},
    //                     {-1, 2, -1, -2, 3},
    //                     {3, -1, -1, -2, -1},
    //                     {-2, -2, -1, -1, -1}}; // -1代表河流 -2 代表島嶼
    Nurikabe *a = new Nurikabe(game, n);
    std::cout << a->is_correct();
    // std::cout << "is correct ? -> " << a->is_correct() << std::endl;
    // std::cout << std::endl;
    // a->print_maze();
    return 0;
}