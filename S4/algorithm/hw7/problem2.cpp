#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <stdlib.h>
#include <unistd.h>          //哈希函数
#define CITY_N 40            //城市个数
#define POPSIZE 300          //种群个体数
#define MAXVALUE 0x7ffffffff //路径最大值上限
#define N 100000             //需要根据实际求得的路径值修正
#define MAX_GEN 50000        //最大进化代数
#define CROSS 0.5            //交叉算子
#define MUT 0.05             //变异算子
using namespace std;

int CITY_NUM = 20;

unsigned seed = (unsigned)time(0); //每次产生不同的随机序列
double Hash[CITY_N + 1];

typedef struct CityPosition
{
    double x;
    double y;
} CityPosition; //城市位置

CityPosition CityPos[38] = {};

double CityDistance[CITY_N][CITY_N]; //城市距离

typedef struct
{
    int colony[POPSIZE][CITY_N + 1]; //城市种群,默认出发城市编号为0，则城市编号的最后一个城市还应该为0
    double fitness[POPSIZE];         // 每个个体的适应度，即1/Distance[POPSIZE]
    double Distance[POPSIZE];        //每个个体的总路径
    int BestRooting[CITY_N + 1];     //最优城市路径序列
    double BestFitness;              //最优路径适应值
    double BestValue;                //最优路径长度
    int BestNum;                     //最优路径城市数目
} TSP, *PTSP;

//计算城市距离CityDistance[i][j]
double CalculatDist(CityPosition CityPos[])
{
    for (int i = 0; i < CITY_NUM; i++)
    {
        for (int j = 0; j < CITY_NUM; j++)
        { //最后一个城市还应该返回到出发节点
            if (i != j)
                CityDistance[i][j] = sqrt(pow(CityPos[j].x - CityPos[i].x, 2) + pow(CityPos[j].y - CityPos[i].y, 2));
            else
                CityDistance[i][i] = 0;
        }
    }
}

//数组复制
void copy(int a[], int b[])
{
    for (int i = 0; i < CITY_NUM + 1; i++)
    {
        a[i] = b[i];
    }
}

//用来检查新生成的节点是否在当前群体中，0号节点是默认出发节点和终止节点
bool check(TSP &city, int pop, int num, int k)
{
    for (int i = 0; i <= num; i++)
    {
        if (k == city.colony[pop][i])
            return true; //新生成节点存在于已经生成的路径中
    }
    return false; //新生成节点没有存在于已经生成的路径中
}

//种群初始化，即为city.colony[i][j]赋值
void InitColony(TSP &city)
{
    int r;
    for (int i = 0; i < POPSIZE; i++)
    {
        city.colony[i][0] = 0;
        city.colony[i][CITY_NUM] = 0;
        city.BestValue = MAXVALUE;
        city.BestFitness = 0; //适应值越大越好
    }
    for (int i = 0; i < POPSIZE; i++)
    {
        for (int j = 1; j < CITY_NUM; j++)
        {
            r = rand() % (CITY_NUM - 1) + 1; //产生1～CITY_NUM-1之间的随机数
            while (check(city, i, j, r))     //随机产生城市序号，即为city.colony[i][j]赋值
            {
                r = rand() % (CITY_NUM - 1) + 1;
            }

            city.colony[i][j] = r;
        }
    }
}

//计算适应度,同时选出最优的
void CalFitness(TSP &city)
{
    int start, end;
    int Best = 0;
    for (int i = 0; i < POPSIZE; i++)
    { //求每个个体的总路径，适应度
        city.Distance[i] = 0;
        for (int j = 1; j <= CITY_NUM; j++)
        {
            start = city.colony[i][j - 1];
            end = city.colony[i][j];
            city.Distance[i] = city.Distance[i] + CityDistance[start][end]; // city.Distance[i]每个个体的总路径
        }
        city.fitness[i] = N / city.Distance[i];
        if (city.fitness[i] > city.fitness[Best]) //选出最大的适应度，即选出所有个体中的最短路径
            Best = i;
    }
    copy(city.BestRooting, city.colony[Best]); //将最优个体拷贝给city.BestRooting
    city.BestFitness = city.fitness[Best];
    city.BestValue = city.Distance[Best];
    city.BestNum = Best;
}

//适应度
double GetFittness(int a[])
{
    int i, start, end;
    double Distance = 0;
    for (i = 0; i < CITY_NUM; i++)
    {
        start = a[i];
        end = a[i + 1];
        Distance += CityDistance[start][end];
    }
    return N / Distance;
}

//选择算子：轮盘赌法
void Select(TSP &city)
{
    int TempColony[POPSIZE][CITY_NUM + 1];
    int i, j, t;
    double s;
    double GaiLv[POPSIZE];
    double SelectP[POPSIZE + 1];
    double avg;
    double sum = 0;
    for (i = 0; i < POPSIZE; i++)
        sum += city.fitness[i];
    for (i = 0; i < POPSIZE; i++)
        GaiLv[i] = city.fitness[i] / sum;
    SelectP[0] = 0;
    for (i = 0; i < POPSIZE; i++)
        SelectP[i + 1] = SelectP[i] + GaiLv[i] * RAND_MAX;
    memcpy(TempColony[0], city.colony[city.BestNum], sizeof(TempColony[0]));
    for (t = 1; t < POPSIZE; t++)
    {
        double ran = rand() % RAND_MAX + 1;
        s = (double)ran / 100.0;
        for (i = 1; i < POPSIZE; i++)
            if (SelectP[i] >= s)
                break;
        memcpy(TempColony[t], city.colony[i - 1], sizeof(TempColony[t]));
    }
    for (i = 0; i < POPSIZE; i++)
        memcpy(city.colony[i], TempColony[i], sizeof(TempColony[i]));
}

//交叉：头尾不变，中间打乱顺序交叉
void Cross(TSP &city, double pc) //交叉概率是pc
{
    int i, j, t, l;
    int a, b, ca, cb;
    int Temp1[CITY_NUM + 1], Temp2[CITY_NUM + 1];
    for (i = 0; i < POPSIZE; i++)
    {
        double s = ((double)(rand() % RAND_MAX)) / RAND_MAX;
        if (s < pc)
        {
            cb = rand() % POPSIZE;
            ca = cb;
            if (ca == city.BestNum || cb == city.BestNum) //如果遇到最优则直接进行下次循环
                continue;

            l = rand() % (CITY_NUM / 2) + 1; // 1-一半的位置
            a = rand() % (CITY_NUM - l) + 1; //全部

            memset(Hash, 0, sizeof(Hash)); //将s中当前位置后面的n个字节 用ch替换并返回s 。
            Temp1[0] = Temp1[CITY_NUM] = 0;
            for (j = 1; j <= l; j++) //打乱顺序即随机，选出来的通过Hash标记为1
            {
                Temp1[j] = city.colony[cb][a + j - 1]; // a+l=2~48 25~38
                Hash[Temp1[j]] = 1;
            }
            for (t = 1; t < CITY_NUM; t++)
            {
                if (Hash[city.colony[ca][t]] == 0)
                {
                    Temp1[j++] = city.colony[ca][t];
                    Hash[city.colony[ca][t]] = 1;
                }
            }
            memcpy(city.colony[ca], Temp1, sizeof(Temp1));
        }
    }
}

//对换变异
void Mutation(TSP &city, double pm) //变异概率是pm
{
    int i, m;
    int Temp[CITY_NUM + 1];
    for (int k = 0; k < POPSIZE; k++)
    {
        double s = ((double)(rand() % RAND_MAX)) / RAND_MAX; //随机产生概率0~1间
        i = rand() % POPSIZE;                                //随机产生0~POPSIZE之间的数
        if (s < pm && i != city.BestNum)                     // i!=city.BestNum，即保证最优的个体不变异
        {
            int a, b, t;
            a = (rand() % (CITY_NUM - 1)) + 1;
            b = (rand() % (CITY_NUM - 1)) + 1;
            copy(Temp, city.colony[i]);
            if (a > b) //保证让b>=a
            {
                t = a;
                a = b;
                b = t;
            }
            for (m = a; m < (a + b) / 2; m++)
            {
                t = Temp[m];
                Temp[m] = Temp[a + b - m];
                Temp[a + b - m] = t;
            }

            if (GetFittness(Temp) < GetFittness(city.colony[i]))
            {
                a = (rand() % (CITY_NUM - 1)) + 1;
                b = (rand() % (CITY_NUM - 1)) + 1;
                memcpy(Temp, city.colony[i], sizeof(Temp));
                if (a > b)
                {
                    t = a;
                    a = b;
                    b = t;
                }
                for (m = a; m < (a + b) / 2; m++)
                {
                    t = Temp[m];
                    Temp[m] = Temp[a + b - m];
                    Temp[a + b - m] = t;
                }

                if (GetFittness(Temp) < GetFittness(city.colony[i]))
                {
                    a = (rand() % (CITY_NUM - 1)) + 1;
                    b = (rand() % (CITY_NUM - 1)) + 1;
                    memcpy(Temp, city.colony[i], sizeof(Temp));
                    if (a > b)
                    {
                        t = a;
                        a = b;
                        b = t;
                    }
                    for (m = a; m < (a + b) / 2; m++)
                    {
                        t = Temp[m];
                        Temp[m] = Temp[a + b - m];
                        Temp[a + b - m] = t;
                    }
                }
            }
            memcpy(city.colony[i], Temp, sizeof(Temp));
        }
    }
}

void OutPut(TSP &city)
{
    // cout << "best route : " << endl;
    // for (int i = 0; i <= CITY_NUM; i++)
    // {
    //     cout << city.BestRooting[i] + 1;
    //     if (i != CITY_NUM)
    //         cout << " ";
    // }
    // cout << endl;
    cout << city.BestValue << endl;
}

int main()
{
    TSP city;
    srand(seed);

    // 讀取數據
    int m = 0, n = 0;
    double d = 0;
    int a, b, c;
    vector<vector<double>> data;
    while (cin >> a >> b >> c)
    {
        vector<double> t;
        t.push_back(a);
        t.push_back(b);
        t.push_back(c);
        data.push_back(t);
    }
    // cout << data.size() << endl;
    CITY_NUM = data.size();

    // double num[data.size()] = {0}, lont[data.size()] = {0}, lati[data.size()] = {0};
    // for (int i = 0; i < data.size(); ++i)
    // {
    //     num[i] = data[i][0];
    //     lont[i] = data[i][1];
    //     lati[i] = data[i][2];
    // }

    CityPosition CityPos[data.size()];
    for (int i = 0; i < data.size(); i++)
    {
        CityPos[i].x = data[i][1];
        CityPos[i].y = data[i][2];
    }

    clock_t start_time = clock();

    CalculatDist(CityPos); //计算城市距离
    InitColony(city);      //生成初始种群
    CalFitness(city);      //计算适应度,同时选出最优的

    for (int i = 0; i < MAX_GEN; i++)
    {
        // cout << i << endl;
        Select(city);        //选择：轮盘赌法
        Cross(city, CROSS);  //交叉
        Mutation(city, MUT); //变异
        CalFitness(city);    //计算新的适应值
    }

    OutPut(city); //输出
    clock_t end_time = clock();
    cout << "Running time : " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    return 0;
}
