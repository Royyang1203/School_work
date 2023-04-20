#include <iostream>
#include <string>
#include <fstream>
#include <random>
#include <time.h>
using namespace std;
const int citycount = 29;
double xmax = citycount, xmin = 1;
std::default_random_engine random((unsigned int)time(NULL));
std::uniform_real_distribution<double> u(0, 1);   //随机数分布对象
std::uniform_real_distribution<double> u1(-1, 1); //随机数分布对象
class City
{
public:
    string name; //城市名称
    double x, y; //城市点的二维坐标
    void shuchu()
    {
        std::cout << name + ":"
                  << "(" << x << "," << y << ")" << endl;
    }
};
class Graph
{
public:
    int Citycount;
    City *city;                                //城市数组
    double distance[citycount][citycount];     //城市间的距离矩阵
    void Readcoordinatetxt(string txtfilename) //读取城市坐标文件的函数
    {
        Citycount = citycount;
        city = new City[Citycount];
        ifstream myfile(txtfilename, ios::in);
        double x = 0, y = 0;
        int z = 0;
        if (!myfile.fail())
        {
            int i = 0;
            while (!myfile.eof() && (myfile >> z >> x >> y))
            {
                city[i].name = to_string(_Longlong(z)); //城市名称转化为字符串
                city[i].x = x;
                city[i].y = y;
                i++;
            }
        }
        else
            cout << "文件不存在";
        myfile.close(); //计算城市距离矩阵
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
        cout << "城市名称 "
             << "坐标x"
             << " "
             << "坐标y" << endl;
        for (int i = 0; i < citycount; i++)
            city[i].shuchu();
        cout << "距离矩阵： " << endl;
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

double round(double r)
{
    return (r > 0.0) ? floor(r + 0.5) : ceil(r - 0.5);
}

void Adjuxt_validParticle(int x[citycount]) //调整蜜源路径有效性的函数，使得蜜源的位置符合TSP问题解的一个排列
{
    int route[citycount];  // 1-citycount
    bool flag[citycount];  //对应route数组中是否在位置中存在的数组，参考数组为route
    int biaoji[citycount]; //对每个元素进行标记的数组,参考数组为粒子位置x
    for (int j = 0; j < citycount; j++)
    {
        route[j] = j + 1;
        flag[j] = false;
        biaoji[j] = 0;
    }
    //首先判断位置中是否有某个城市且唯一，若有且唯一，则对应flag的值为true,
    for (int j = 0; j < citycount; j++)
    {
        int num = 0;
        for (int k = 0; k < citycount; k++)
        {
            if (x[k] == route[j])
            {
                biaoji[k] = 1; //说明k号元素对应的城市在route中，并且是第一次出现才进行标记
                num++;
                break;
            }
        }
        if (num == 0)
            flag[j] = false; //路线中没有route[j]这个城市
        else if (num == 1)
            flag[j] = true; //路线中有route[j]这个城市
    }
    for (int k = 0; k < citycount; k++)
    {
        if (flag[k] == false) //路线中没有route[k]这个城市，需要将这个城市加入到路线中
        {
            int i = 0;
            for (; i < citycount; i++)
            {
                if (biaoji[i] != 1)
                    break;
            }
            x[i] = route[k]; //对于标记为0的进行替换
            biaoji[i] = 1;
        }
    }
}
class Bee
{
public:
    int dimension; //变量的维数
    int *x;
    double fitdegreevalue = 0;
    double selectprobability = 0;
    int limitcishu = 0;
    void Init(int Dimension)
    {
        dimension = Dimension;
        x = new int[dimension];
        for (int j = 0; j < citycount; j++)
        {
            *(x + j) = round(xmin + u(random) * (xmax - xmin)); //随机初始化可行解
        }
        Adjuxt_validParticle(x); //对蜜源路径进行有效性调整，确保是TSP问题的一个可行解
    }
    void shuchu()
    {
        for (int j = 0; j < dimension; j++)
        {
            if (j == dimension - 1)
                std::cout << x[j] << ")" << endl;
            else if (j == 0)
                std::cout << "(" << x[j] << ", ";
            else
                std::cout << x[j] << ", ";
        }
    }
};
class ABC
{
public:
    Bee *miyuan, bestmiyuan, *employedbee, *onlookerbee; //蜜源、最好蜜源、雇佣蜂、观察蜂
    int SN;                                              //雇佣蜂的数量、蜜源的数量、观察蜂的数量相等
    int Dimension;                                       //可行解的维数
    int MCN;                                             //终止代数
    int Limit;                                           //为防止算法陷入局部最优，蜜源最大改进次数
    void Init(int sn, int dimension, int mcn, int limit)
    {
        SN = sn;
        Dimension = dimension;
        MCN = mcn;
        Limit = limit;
        miyuan = new Bee[SN];
        employedbee = new Bee[SN];
        onlookerbee = new Bee[SN];
        for (int i = 0; i < SN; i++)
        {
            (miyuan + i)->Init(Dimension);
            double beefunvalue = CalculateFitValue(*(miyuan + i));
            (miyuan + i)->fitdegreevalue = CalculateFitDegree(beefunvalue);

            (employedbee + i)->Init(Dimension);
            double employedbeefunvalue = CalculateFitValue(*(employedbee + i));
            (employedbee + i)->fitdegreevalue = CalculateFitDegree(employedbeefunvalue);

            (onlookerbee + i)->Init(Dimension);
            double onlookerbeefunvalue = CalculateFitValue(*(onlookerbee + i));
            (onlookerbee + i)->fitdegreevalue = CalculateFitDegree(onlookerbeefunvalue);
        }
        bestmiyuan.Init(Dimension); //最好蜜源初始化
        for (int j = 0; j < Dimension; j++)
        {
            bestmiyuan.x[j] = miyuan->x[j];
        }
        bestmiyuan.fitdegreevalue = miyuan->fitdegreevalue;
    }
    double CalculateFitValue(Bee be) //适应值计算函数，即计算路径长度
    {
        double funvalue = 0;
        for (int i = 0; i < citycount - 1; i++)
            funvalue += Map_City.distance[be.x[i] - 1][be.x[i + 1] - 1];
        funvalue += Map_City.distance[be.x[citycount - 1] - 1][be.x[0] - 1];
        return funvalue;
    }
    double CalculateFitDegree(double fi) //计算适应度的函数
    {
        double fitnessdu = 0;
        if (fi > 0)
            fitnessdu = 1.0 / (1 + fi);
        else
            fitnessdu = 1 + abs(fi);
        return fitnessdu;
    }
    void EmployedBeeOperate() //雇佣蜂操作函数
    {
        std::uniform_int_distribution<int> uD(1, Dimension); //随机数分布对象
        std::uniform_int_distribution<int> uSN(1, SN);       //随机数分布对象
        for (int i = 0; i < SN; i++)
        {
            for (int j = 0; j < Dimension; j++) //雇佣峰利用先前的蜜源信息寻找新的蜜源
            {
                (employedbee + i)->x[j] = (miyuan + i)->x[j];
            }
            int k, jie;            //随机生成且 k≠i k∈[1,SN]
            jie = uD(random) - 1;  // jie为【1，Dimension】上的随机数
            double φ = u1(random); //φ表示[-1,1]之间的随机数
            while (true)
            {
                k = uSN(random) - 1;
                if (k != i)
                    break;
            }
            (employedbee + i)->x[jie] = (miyuan + i)->x[jie] + φ * ((miyuan + i)->x[jie] - (miyuan + k)->x[jie]); //搜索新蜜源
            //保证蜜源位置不越界
            if ((employedbee + i)->x[jie] > xmax)
                (employedbee + i)->x[jie] = xmax;
            else if ((employedbee + i)->x[jie] < xmin)
                (employedbee + i)->x[jie] = xmin;
            Adjuxt_validParticle((employedbee + i)->x);                                                    //对蜜源路径进行有效性调整，确保是TSP问题的一个可行解
            (employedbee + i)->fitdegreevalue = CalculateFitDegree(CalculateFitValue(*(employedbee + i))); //计算适应度值																							  //雇佣蜂根据贪心策略选择蜜源
            if (CalculateFitValue(*(employedbee + i)) < CalculateFitValue(*(miyuan + i)))
            {
                for (int j = 0; j < Dimension; j++)
                    (miyuan + i)->x[j] = (employedbee + i)->x[j];
                (miyuan + i)->limitcishu = 0;
                (miyuan + i)->fitdegreevalue = (employedbee + i)->fitdegreevalue;
            }
            else
                (miyuan + i)->limitcishu++; //蜜源未改进次数加一
        }
    }
    void CalculateProbability() //计算蜜源概率的函数
    {
        for (int i = 0; i < SN; i++)
        {
            (miyuan + i)->fitdegreevalue = CalculateFitDegree(CalculateFitValue(*(miyuan + i)));
        }
        double sumfitdegreevalue = 0;
        for (int i = 0; i < SN; i++)
        {
            sumfitdegreevalue += (miyuan + i)->fitdegreevalue;
        }
        for (int i = 0; i < SN; i++)
        {
            (miyuan + i)->selectprobability = (miyuan + i)->fitdegreevalue / sumfitdegreevalue;
        }
    }
    void OnLookerBeeOperate() //观察蜂操作
    {
        std::uniform_int_distribution<int> uD(1, Dimension); //随机数分布对象
        std::uniform_int_distribution<int> uSN(1, SN);       //随机数分布对象
        int m = 0;
        while (m < SN) //为所有的观察蜂按照概率选择蜜源并搜索新蜜源，计算新蜜源适应值
        {
            double m_choosedprobability = u(random); // 0~1之间的随机数
            for (int i = 0; i < SN; i++)
            {
                if (m_choosedprobability < (miyuan + i)->selectprobability)
                {
                    int k, jie;            //随机生成且 k≠i k∈[1,SN]
                    jie = uD(random) - 1;  // jie为【1，Dimension】上的随机数
                    double φ = u1(random); //φ表示[-1,1]之间的随机数
                    while (true)
                    {
                        k = uSN(random) - 1;
                        if (k != i)
                            break;
                    }
                    for (int j = 0; j < Dimension; j++)
                        (onlookerbee + m)->x[j] = (miyuan + i)->x[j];
                    (onlookerbee + m)->x[jie] = (miyuan + i)->x[jie] + φ * ((miyuan + i)->x[jie] - (miyuan + k)->x[jie]); //搜索新蜜源
                    if ((onlookerbee + m)->x[jie] > xmax)
                        (onlookerbee + m)->x[jie] = xmax;
                    else if ((onlookerbee + m)->x[jie] < xmin)
                        (onlookerbee + m)->x[jie] = xmin;       //判断是否越界
                    Adjuxt_validParticle((onlookerbee + m)->x); //对蜜源路径进行有效性调整，确保是TSP问题的一个可行解
                    (onlookerbee + m)->fitdegreevalue = CalculateFitDegree(CalculateFitValue(*(onlookerbee + m)));
                    //贪心策略选择蜜源
                    if (CalculateFitValue(*(onlookerbee + m)) < CalculateFitValue(*(miyuan + i)))
                    {
                        for (int j = 0; j < Dimension; j++)
                            (miyuan + i)->x[j] = (onlookerbee + m)->x[j];
                        (miyuan + i)->fitdegreevalue = (onlookerbee + m)->fitdegreevalue;
                    }
                    else
                        (miyuan + i)->limitcishu++;
                    m++;
                }
                break;
            }
        }
    }
    void ScoutBeeOperate() //侦查蜂操作,决定蜜源是否放弃，并随机产生新位置替代原蜜源
    {
        for (int i = 0; i < SN; i++)
        {
            if ((miyuan + i)->limitcishu >= Limit)
            {
                for (int j = 0; j < Dimension; j++)
                {
                    (miyuan + i)->x[j] = round(xmin + u(random) * (xmax - xmin)); //随机初始化可行解;//随机产生可行解
                }
                Adjuxt_validParticle((miyuan + i)->x);
                (miyuan + i)->limitcishu = 0;
                (miyuan + i)->fitdegreevalue = CalculateFitDegree(CalculateFitValue(*(miyuan + i)));
            }
        }
    }
    void SaveBestMiyuan() //记录最优解的函数
    {
        for (int i = 0; i < SN; i++)
        {
            if (CalculateFitValue(*(miyuan + i)) < CalculateFitValue(bestmiyuan))
            {
                for (int j = 0; j < Dimension; j++)
                    bestmiyuan.x[j] = (miyuan + i)->x[j];
            }
        }
    }
    void shuchumiyuan()
    {
        for (int i = 0; i < SN; i++)
        {
            std::cout << "蜜源" << i + 1 << "->";
            for (int j = 0; j < Dimension; j++)
            {
                if (j == Dimension - 1)
                    std::cout << (miyuan + i)->x[j] << ")对应的距离为： " << CalculateFitValue(*(miyuan + i)) << endl;
                else if (j == 0)
                    std::cout << "(" << (miyuan + i)->x[j] << ", ";
                else
                    std::cout << (miyuan + i)->x[j] << ", ";
            }
        }
    }
    void ShuchuBestmiyuan()
    {
        for (int j = 0; j < Dimension; j++)
        {
            if (j == Dimension - 1)
                std::cout << bestmiyuan.x[j] << ")"
                          << "对应的距离为：" << CalculateFitValue(bestmiyuan) << endl;
            else if (j == 0)
                std::cout << "(" << bestmiyuan.x[j] << ",";
            else
                std::cout << bestmiyuan.x[j] << ",";
        }
    }
    void DoABC(int sn, int dimension, int mcn, int limit, string filename) //运行人工蜂群算法的函数
    {
        ofstream outfile;
        outfile.open("result.txt", ios::trunc);
        Map_City.Readcoordinatetxt(filename);
        Map_City.shuchu();
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
        Init(sn, dimension, mcn, limit); //初始化
        shuchumiyuan();
        outfile << "初始化后的蜜源如下：" << endl;
        for (int i = 0; i < SN; i++)
        {
            outfile << "蜜源" << i + 1 << "->";
            for (int j = 0; j < citycount; j++)
            {
                if (j == citycount - 1)
                    outfile << (miyuan + i)->x[j] << ") = " << CalculateFitValue(*(miyuan + i)) << endl;
                else if (j == 0)
                    outfile << "f(" << (miyuan + i)->x[j] << ",";
                else
                    outfile << (miyuan + i)->x[j] << ",";
            }
        }
        SaveBestMiyuan(); //保存最好蜜源
        ShuchuBestmiyuan();
        for (int k = 0; k < MCN; k++)
        {
            EmployedBeeOperate();
            CalculateProbability();
            OnLookerBeeOperate();
            SaveBestMiyuan();
            ScoutBeeOperate();
            SaveBestMiyuan();
            std::cout << "第" << k + 1 << "次迭代的最优解为：";
            ShuchuBestmiyuan();
            outfile << "第" << k + 1 << "次迭代后的蜜源如下：" << endl;
            for (int i = 0; i < SN; i++)
            {
                outfile << "蜜源" << i + 1 << "->";
                for (int j = 0; j < citycount; j++)
                {
                    if (j == citycount - 1)
                        outfile << (miyuan + i)->x[j] << ") = " << CalculateFitValue(*(miyuan + i)) << endl;
                    else if (j == 0)
                        outfile << "f(" << (miyuan + i)->x[j] << ",";
                    else
                        outfile << (miyuan + i)->x[j] << ",";
                }
            }
            outfile << "第" << k + 1 << "次迭代的最优蜜源为：";
            for (int j = 0; j < citycount; j++)
            {
                if (j == citycount - 1)
                    outfile << bestmiyuan.x[j] << ") = " << CalculateFitValue(bestmiyuan) << endl;
                else if (j == 0)
                    outfile << "f(" << bestmiyuan.x[j] << ",";
                else
                    outfile << bestmiyuan.x[j] << ",";
            }
        }
        outfile.close();
    }
};
int main()
{
    system("mode con cols=200");
    system("color fc");
    std::cout << "人工蜂群算法求解TSP旅行商问题!" << endl;
    ABC abc;
    abc.DoABC(50, citycount, 200, 20, "D:\\OneDrive - 國立東華大學\\code\\5_School_Work\\S4\\algorithm\\hw7\\City_20_.txt");
    system("pause");
    return 0;
}
