#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <random>
#include <vector>
using namespace std;
std::default_random_engine random((unsigned int)time(NULL));
std::uniform_real_distribution<double> u0(0, 1); //随机数分布对象
const int citycount = 20;                        //城市的数量
class City
{
public:
    City() = default;
    City(int a, int b, int c)
    {
        name = to_string(a);
        x = b;
        y = c;
    }
    string name = "-1"; //城市名称
    double x = 0;
    double y = 0; //城市点的二维坐标
    void shuchu()
    {
        std::cout << name + ":"
                  << "(" << x << "," << y << ")" << endl;
    }
};

double round(double r) { return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5); }
class Graph
{
public:
    City city[citycount];                  //城市数组
    double distance[citycount][citycount]; //城市间的距离矩阵

    void Readcoordinatetxt(vector<City> data)
    {
        for (int i = 0; i < citycount; ++i)
        {
            city[i].name = data[i].name;
            city[i].x = data[i].x;
            city[i].y = data[i].y;
        }

        for (int i = 0; i < citycount; i++)
            for (int j = 0; j < citycount; j++)
            {
                distance[i][j] = sqrt((pow((city[i].x - city[j].x), 2) + pow((city[i].y - city[j].y), 2)) / 10.0); //计算城市ij之间的伪欧式距离
                if (round(distance[i][j] < distance[i][j]))
                    distance[i][j] = round(distance[i][j]) + 1;
                else
                    distance[i][j] = round(distance[i][j]);
            }
    }

    void shuchu()
    {
        cout << "map : " << endl;
        for (int i = 0; i < citycount; i++)
            city[i].shuchu();
        cout << "distance : " << endl;
        for (int i = 0; i < citycount; i++)
        {
            for (int j = 0; j < citycount; j++)
            {
                if (j == citycount - 1)
                    std::cout << distance[i][j] << endl;
                else
                    std::cout << distance[i][j] << "  ";
            }
        }
    }
};
Graph Map_City; //定义全局对象图
int *Random_N(int n)
{
    int *geti;
    geti = new int[n];
    int j = 0;
    while (j < n)
    {
        while (true)
        {
            int flag = -1;
            int temp = rand() % n + 1;
            if (j > 0)
            {
                int k = 0;
                for (; k < j; k++)
                {
                    if (temp == *(geti + k))
                        break;
                }
                if (k == j)
                {
                    *(geti + j) = temp;
                    flag = 1;
                }
            }
            else
            {
                *(geti + j) = temp;
                flag = 1;
            }
            if (flag == 1)
                break;
        }
        j++;
    }
    return geti;
}
class Ranseti
{
public:
    int *X;
    double fitness;
    void Init()
    {
        X = new int[citycount];
        int *M = Random_N(citycount);
        for (int j = 0; j < citycount; j++)
            X[j] = *(M + j);
        fitness = 0;
    }
    void shuchu()
    {
        for (int j = 0; j < citycount; j++)
        {
            if (j == citycount - 1)
                std::cout << X[j] << " " << fitness << endl;
            else
                std::cout << X[j] << "->";
        }
    }
};

class GA
{
public:
    Ranseti *oldranseti; //上一代种群
    Ranseti *ranseti;    //下一代种群
    int Pop_Size;        //种群大小
    int Itetime;         //迭代次数
    double Cross_Prob;   //交叉概率
    double Bianyi_Prob;  //变异概率
    Ranseti Bestranseti; //最佳染色体个体
    double Bestlength;   //最短路径的长度
    double *Leiji_Prob;  //累积选择概率
    void Init(int popsize, int itetime, double crossprob, double bianyiprob, vector<City> data)
    {
        Map_City.Readcoordinatetxt(data);
        Map_City.shuchu();
        Pop_Size = popsize;
        Itetime = itetime;
        Cross_Prob = crossprob;
        Bianyi_Prob = bianyiprob;
        oldranseti = new Ranseti[Pop_Size];
        ranseti = new Ranseti[Pop_Size];
        Leiji_Prob = new double[Pop_Size];
        for (int i = 0; i < Pop_Size; i++)
        {
            oldranseti[i].Init();
            oldranseti[i].fitness = Evaluate(i); //初始化适应度
        }
        int bestid = -1;
        for (int i = 0; i < Pop_Size; i++)
        {
            int j = 0;
            for (; j < Pop_Size; j++)
            {
                if (oldranseti[i].fitness > oldranseti[j].fitness)
                    break;
            }
            if (j == Pop_Size)
            {
                bestid = i;
                break;
            }
        }
        Bestranseti.Init();
        Bestranseti.fitness = 0;
        for (int j = 0; j < citycount; j++)
            Bestranseti.X[j] = oldranseti[bestid].X[j];
        for (int j = 0; j < citycount - 1; j++)
            Bestranseti.fitness += Map_City.distance[Bestranseti.X[j]][Bestranseti.X[j + 1]];
        Bestranseti.fitness += Map_City.distance[Bestranseti.X[citycount - 1]][Bestranseti.X[0]];
        Bestlength = Bestranseti.fitness;
    }
    void shuchu()
    {
        for (int i = 0; i < Pop_Size; i++)
            oldranseti[i].shuchu();
    }
    double Evaluate(int k) //计算染色体适应值的函数，计算路径距离
    {
        double distancer = 0;
        for (int j = 0; j < citycount - 1; j++)
            distancer += Map_City.distance[oldranseti[k].X[j]][oldranseti[k].X[j + 1]];
        distancer += Map_City.distance[oldranseti[k].X[citycount - 1]][oldranseti[k].X[0]];
        oldranseti[k].fitness = distancer;
        return distancer;
    }
    void CalculateLeijiProb()
    {
        double Sumfitness = -0;
        for (int i = 0; i < Pop_Size; i++)
            oldranseti[i].fitness = Evaluate(i);
        for (int i = 0; i < Pop_Size; i++)
            Sumfitness += oldranseti[i].fitness; //计算种群中所有染色体的适应值之和
        double *SelectProb;
        SelectProb = new double[Pop_Size];
        for (int i = 0; i < Pop_Size; i++)
            SelectProb[i] = oldranseti[i].fitness / Sumfitness; //计算每个染色体的选择概率
        for (int i = 0; i < Pop_Size; i++)
        {
            Leiji_Prob[i] = 0;
            for (int j = 0; j <= i; j++)
                Leiji_Prob[i] += SelectProb[j]; //计算每个染色体的累积概率
        }
    }
    void Roulette()
    {
        for (int i = 0; i < Pop_Size; i++) //轮盘赌选择产生新种群
        {
            cout << i << endl;
            double suijishu = u0(random); //产生一个0-1之间随机数
            int j = 0;
            for (; j < Pop_Size; j++)
            {
                if (suijishu <= Leiji_Prob[j])
                    break;
            }
            cout << "good" << endl;
            ranseti[i].Init();
            cout << "good" << endl;
            for (int k = 0; k < citycount; k++)
                cout << oldranseti[j].X[k];
            for (int k = 0; k < citycount; k++)
                ranseti[i].X[k] = oldranseti[j].X[k];
            cout << "good" << endl;
        }
        cout << "roulette" << endl;
        for (int i = 0; i < Pop_Size; i++)
        {
            ranseti[i].fitness = 0;
            for (int j = 0; j < citycount - 1; j++)
                ranseti[i].fitness += Map_City.distance[ranseti[i].X[j]][ranseti[i].X[j + 1]];
            ranseti[i].fitness += Map_City.distance[ranseti[i].X[citycount - 1]][ranseti[i].X[0]];
        }
    }
    void Cross(double Pc) // 交叉函数采用部分匹配交叉策略
    {
        for (int k = 0; k + 1 < Pop_Size; k = k + 2)
        {
            int k1 = k;
            int k2 = k1 + 1;
            double suijishu = u0(random);
            if (Pc > suijishu)
            {
                int pos1 = rand() % citycount, pos2 = rand() % citycount;
                if (pos1 > pos2) // 确保pos1小于pos2
                {
                    pos1 += pos2;
                    pos2 = pos1 - pos2;
                    pos1 = pos1 - pos2;
                }
                for (int j = 0; j < citycount; j++)
                {
                    if (j >= pos1 && j <= pos2)
                    {
                        ranseti[k1].X[j] = ranseti[k1].X[j] + ranseti[k2].X[j];
                        ranseti[k2].X[j] = ranseti[k1].X[j] - ranseti[k2].X[j];
                        ranseti[k1].X[j] = ranseti[k1].X[j] - ranseti[k2].X[j];
                    }
                }
                int cishu = pos2 - pos1 + 1;
                for (int j = 0; j < citycount; j++)
                {
                    if ((j < pos1) || (j > pos2))
                    {
                        for (int jishu = 1; jishu <= cishu; jishu++)
                        {
                            for (int m = pos1; m <= pos2; m++)
                            {
                                if (ranseti[k1].X[j] == ranseti[k1].X[m])
                                {
                                    ranseti[k1].X[j] = ranseti[k2].X[m];
                                }
                            }
                        }
                    }
                }
                for (int j = 0; j < citycount; j++)
                {
                    if ((j < pos1) || (j > pos2))
                    {
                        for (int jishu = 1; jishu <= cishu; jishu++)
                        {
                            for (int m = pos1; m <= pos2; m++)
                            {
                                if (ranseti[k2].X[j] == ranseti[k2].X[m])
                                {
                                    ranseti[k2].X[j] = ranseti[k1].X[m];
                                }
                            }
                        }
                    }
                }
            }
        }
        for (int i = 0; i < Pop_Size; i++)
        {
            ranseti[i].fitness = 0;
            for (int j = 0; j < citycount - 1; j++)
                ranseti[i].fitness += Map_City.distance[ranseti[i].X[j]][ranseti[i].X[j + 1]];
            ranseti[i].fitness += Map_City.distance[ranseti[i].X[citycount - 1]][ranseti[i].X[0]];
        }
    }
    void Bianyi(double Pm) //变异函数
    {
        for (int k = 0; k < Pop_Size; k++)
        {
            double suijishu = u0(random);
            if (Pm > suijishu)
            {
                int pos1 = rand() % citycount, pos2 = rand() % citycount; //随机选出两个变异位置，然后将两个位置上的城市序号进行交换
                while (pos2 == pos1)
                    pos2 = rand() % citycount;
                ranseti[k].X[pos1] += ranseti[k].X[pos2];
                ranseti[k].X[pos2] = ranseti[k].X[pos1] - ranseti[k].X[pos2];
                ranseti[k].X[pos1] = ranseti[k].X[pos1] - ranseti[k].X[pos2];
            }
            ranseti[k].fitness = 0;
            for (int j = 0; j < citycount - 1; j++)
                ranseti[k].fitness += Map_City.distance[ranseti[k].X[j]][ranseti[k].X[j + 1]];
            ranseti[k].fitness += Map_City.distance[ranseti[k].X[citycount - 1]][ranseti[k].X[0]];
        }
    }
    void SelectBestRanseti()
    {
        for (int i = 0; i < Pop_Size; i++)
        {
            if (ranseti[i].fitness < Bestranseti.fitness)
            {
                for (int j = 0; j < citycount; j++)
                    Bestranseti.X[j] = ranseti[i].X[j];
            }
        }
        Bestranseti.fitness = 0;
        for (int j = 0; j < citycount - 1; j++)
            Bestranseti.fitness += Map_City.distance[Bestranseti.X[j]][Bestranseti.X[j + 1]];
        Bestranseti.fitness += Map_City.distance[Bestranseti.X[citycount - 1]][Bestranseti.X[0]];
    }
    void GA_TSP()
    {
        for (int k = 0; k < Itetime; k++)
        {
            cout << "iter " << k << endl;
            CalculateLeijiProb(); //计算上一代种群染色体的累积概率
            cout << "b";
            Roulette(); //轮盘赌法选择出下一代种群
            cout << "c";
            SelectBestRanseti(); //获得最好个体

            cout << "random new" << endl;
            for (int i = 0; i < Pop_Size; i++)
                for (int j = 0; j < citycount; j++)
                {
                    if (j == citycount - 1)
                        cout << ranseti[i].X[j] << " " << ranseti[i].fitness << " " << endl;
                    else
                        cout << ranseti[i].X[j] << "->";
                }
            Cross(Cross_Prob);
            SelectBestRanseti(); //获得最好个体
            cout << "after cross" << endl;
            for (int i = 0; i < Pop_Size; i++)
                for (int j = 0; j < citycount; j++)
                {
                    if (j == citycount - 1)
                        cout << ranseti[i].X[j] << " " << ranseti[i].fitness << " " << endl;
                    else
                        cout << ranseti[i].X[j] << "->";
                }
            Bianyi(Bianyi_Prob);
            SelectBestRanseti(); //获得最好个体
            cout << "Mutation" << endl;
            for (int i = 0; i < Pop_Size; i++)
                for (int j = 0; j < citycount; j++)
                {
                    if (j == citycount - 1)
                        cout << ranseti[i].X[j] << " " << ranseti[i].fitness << " " << endl;
                    else
                        cout << ranseti[i].X[j] << "->";
                }
            SelectBestRanseti(); //获得最好个体
            cout << "best length" << Bestranseti.fitness << endl;
            for (int i = 0; i < Pop_Size; i++)
            {
                for (int j = 0; j < citycount; j++)
                {
                    oldranseti[i].X[j] = ranseti[i].X[j];
                }
                oldranseti[i].fitness = ranseti[i].fitness;
            }
        }

        std::cout << "****************finish****************" << endl;
        std::cout << Itetime << "best length" << Bestranseti.fitness << endl;
        std::cout << Itetime << "best route" << endl;

        for (int j = 0; j < citycount; j++)
        {
            if (j == citycount - 1)
            {
                std::cout << Bestranseti.X[j] << endl;
            }
            else
            {
                std::cout << Bestranseti.X[j] << "->";
            }
        }
    }
};

GA zq;

int main()
{
    int a, b, c;
    vector<City> data;
    while (cin >> a >> b >> c)
    {
        data.push_back(City(a, b, c));
    }

    zq.Init(50, 100, 0.8, 0.9, data);
    zq.shuchu();
    cout << "a" << endl;
    zq.GA_TSP();
    return 0;
}
