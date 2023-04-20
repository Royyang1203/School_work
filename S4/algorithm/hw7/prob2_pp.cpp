#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <random>
#include <cfloat>
#include <limits>
using namespace std;
const int citycount = 20;
double vmax = 1, vmin = -1;
std::default_random_engine random(time(NULL));
static std::uniform_real_distribution<double> distribution(0.0, std::nextafter(1.0, DBL_MAX)); // C++11提供的实数均匀分布模板类
static std::uniform_real_distribution<double> distribution1(vmin, std::nextafter(vmax, DBL_MAX));

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
Graph Map_City; //定义全局对象图,放在Graph类后
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
double Evaluate(int *x) //计算粒子适应值的函数
{
    double fitnessvalue = 0;
    for (int i = 0; i < citycount - 1; i++)
        fitnessvalue += Map_City.distance[x[i] - 1][x[i + 1] - 1];
    fitnessvalue += Map_City.distance[x[citycount - 1] - 1][x[0] - 1];
    return fitnessvalue;
}
class Particle
{
public:
    int *x; //粒子的位置
    int *v; //粒子的速度
    double fitness;
    void Init()
    {
        x = new int[citycount];
        v = new int[citycount];
        int *M = Random_N(citycount);
        for (int i = 0; i < citycount; i++)
            x[i] = *(M + i);
        fitness = Evaluate(x);
        for (int i = 0; i < citycount; i++)
        {
            v[i] = (int)distribution1(random);
        }
    }
    void shuchu()
    {
        for (int i = 0; i < citycount; i++)
        {
            if (i == citycount - 1)
                std::cout << x[i] << ") = " << fitness << endl;
            else if (i == 0)
                std::cout << "f(" << x[i] << ",";
            else
                std::cout << x[i] << ",";
        }
    }
};
void Adjuxt_validParticle(Particle p) //调整粒子有效性的函数，使得粒子的位置符合TSP问题解的一个排列
{
    int route[citycount];  // 1-citycount
    bool flag[citycount];  //对应route数组中是否在粒子的位置中存在的数组，参考数组为route
    int biaoji[citycount]; //对粒子每个元素进行标记的数组,参考数组为粒子位置x
    for (int j = 0; j < citycount; j++)
    {
        route[j] = j + 1;
        flag[j] = false;
        biaoji[j] = 0;
    }
    //首先判断粒子p的位置中是否有某个城市且唯一，若有且唯一，则对应flag的值为true,
    for (int j = 0; j < citycount; j++)
    {
        int num = 0;
        for (int k = 0; k < citycount; k++)
        {
            if (p.x[k] == route[j])
            {
                biaoji[k] = 1; //说明粒子中的k号元素对应的城市在route中，并且是第一次出现才进行标记
                num++;
                break;
            }
        }
        if (num == 0)
            flag[j] = false; //粒子路线中没有route[j]这个城市
        else if (num == 1)
            flag[j] = true; //粒子路线中有route[j]这个城市
    }
    for (int k = 0; k < citycount; k++)
    {
        if (flag[k] == false) //粒子路线中没有route[k]这个城市，需要将这个城市加入到粒子路线中
        {
            int i = 0;
            for (; i < citycount; i++)
            {
                if (biaoji[i] != 1)
                    break;
            }
            p.x[i] = route[k]; //对于标记为0的进行替换
            biaoji[i] = 1;
        }
    }
}
class PSO
{
public:
    Particle *oldparticle;
    Particle *pbest, gbest;
    double c1, c2, w;
    int Itetime;
    int popsize;

    void Init(int Pop_Size, int itetime, double C1, double C2, double W)
    {
        Itetime = itetime;
        c1 = C1;
        c2 = C2;
        w = W;
        popsize = Pop_Size;
        oldparticle = new Particle[popsize];
        pbest = new Particle[popsize];
        for (int i = 0; i < popsize; i++)
        {
            oldparticle[i].Init();
            pbest[i].Init();
            for (int j = 0; j < citycount; j++)
            {
                pbest[i].x[j] = oldparticle[i].x[j];
                pbest[i].fitness = oldparticle[i].fitness;
            }
        }
        gbest.Init();
        gbest.fitness = INFINITY; //为全局最优粒子初始化
        for (int i = 0; i < popsize; i++)
        {
            if (pbest[i].fitness < gbest.fitness)
            {
                gbest.fitness = pbest[i].fitness;
                for (int j = 0; j < citycount; j++)
                    gbest.x[j] = pbest[i].x[j];
            }
        }
    }
    void Shuchu()
    {
        for (int i = 0; i < popsize; i++)
        {
            std::cout << "粒子" << i + 1 << "->";
            oldparticle[i].shuchu();
        }
    }
    void PSO_TSP(int Pop_size, int itetime, double C1, double C2, double W, double Vlimitabs, vector<City> filename)
    {
        Map_City.Readcoordinatetxt(filename);
        Map_City.shuchu();
        vmax = Vlimitabs;
        vmin = -Vlimitabs;
        Init(Pop_size, itetime, C1, C2, W);
        std::cout << "初始化后的种群如下：" << endl;
        Shuchu();
        ofstream outfile;
        outfile.open("result.txt", ios::trunc);
        outfile << "城市名称 "
                << "坐标x"
                << " "
                << "坐标y" << endl;
        for (int i = 0; i < citycount; i++)
            outfile << Map_City.city[i].name << " " << Map_City.city[i].x << " " << Map_City.city[i].y << endl;
        outfile << "距离矩阵： " << endl;
        for (int i = 0; i < citycount; i++)
        {
            for (int j = 0; j < citycount; j++)
            {
                if (j == citycount - 1)
                    outfile << Map_City.distance[i][j] << endl;
                else
                    outfile << Map_City.distance[i][j] << "  ";
            }
        }
        outfile << "初始化后的种群如下：" << endl;
        for (int i = 0; i < popsize; i++)
        {
            outfile << "粒子" << i + 1 << "->";
            for (int j = 0; j < citycount; j++)
            {
                if (j == citycount - 1)
                    outfile << oldparticle[i].x[j] << ") = " << oldparticle[i].fitness << endl;
                else if (j == 0)
                    outfile << "f(" << oldparticle[i].x[j] << ",";
                else
                    outfile << oldparticle[i].x[j] << ",";
            }
        }
        for (int ite = 0; ite < Itetime; ite++)
        {
            for (int i = 0; i < popsize; i++)
            {
                //更新粒子速度和位置
                for (int j = 0; j < citycount; j++)
                {
                    oldparticle[i].v[j] = (int)(w * oldparticle[i].v[j] + c1 * distribution(random) * (pbest[i].x[j] - oldparticle[i].x[j]) + c2 * distribution(random) * (gbest.x[j] - oldparticle[i].x[j]));
                    if (oldparticle[i].v[j] > vmax) //粒子速度越界调整
                        oldparticle[i].v[j] = (int)vmax;
                    else if (oldparticle[i].v[j] < vmin)
                        oldparticle[i].v[j] = (int)vmin;
                    oldparticle[i].x[j] += oldparticle[i].v[j];
                    if (oldparticle[i].x[j] > citycount)
                        oldparticle[i].x[j] = citycount; //粒子位置越界调整
                    else if (oldparticle[i].x[j] < 1)
                        oldparticle[i].x[j] = 1;
                }
                //粒子位置有效性调整，必须满足解空间的条件
                Adjuxt_validParticle(oldparticle[i]);
                oldparticle[i].fitness = Evaluate(oldparticle[i].x);
                pbest[i].fitness = Evaluate(pbest[i].x);
                if (oldparticle[i].fitness < pbest[i].fitness)
                {
                    for (int j = 0; j < citycount; j++)
                        pbest[i].x[j] = oldparticle[i].x[j];
                } //更新单个粒子的历史极值
                for (int j = 0; j < citycount; j++)
                    gbest.x[j] = pbest[i].x[j]; //更新全局极值
                for (int k = 0; k < popsize && k != i; k++)
                {
                    if (Evaluate(pbest[k].x) < Evaluate(gbest.x))
                    {
                        for (int j = 0; j < citycount; j++)
                            gbest.x[j] = pbest[k].x[j];
                        gbest.fitness = Evaluate(gbest.x);
                    }
                }
            }
            outfile << "第" << ite + 1 << "次迭代后的种群如下：" << endl;
            for (int i = 0; i < popsize; i++)
            {
                outfile << "粒子" << i + 1 << "->";
                for (int j = 0; j < citycount; j++)
                {
                    if (j == citycount - 1)
                        outfile << oldparticle[i].x[j] << ") = " << oldparticle[i].fitness << endl;
                    else if (j == 0)
                        outfile << "f(" << oldparticle[i].x[j] << ",";
                    else
                        outfile << oldparticle[i].x[j] << ",";
                }
            }
            std::cout << "第" << ite + 1 << "次迭代后的最好粒子：";
            outfile << "第" << ite + 1 << "次迭代后的最好粒子：" << endl;
            for (int j = 0; j < citycount; j++)
            {
                if (j == citycount - 1)
                    outfile << gbest.x[j] << ") = " << gbest.fitness << endl;
                else if (j == 0)
                    outfile << "f(" << gbest.x[j] << ",";
                else
                    outfile << gbest.x[j] << ",";
            }
            gbest.shuchu();
        }
        outfile.close();
    }
};
PSO pso;
int main()
{
    int a, b, c;
    vector<City> data;
    while (cin >> a >> b >> c)
    {
        data.push_back(City(a, b, c));
    }

    pso.PSO_TSP(30, 500, 2, 2, 0.8, 3.0, data);
    system("pause");
    return 0;
}