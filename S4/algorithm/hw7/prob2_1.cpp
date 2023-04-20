#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random>    // std::default_random_engine
#include <chrono>
#include <math>
using namespace std;

class HeuristicOperator
{
public:
    vector<vector<double>> getCoord(void) //函式1：獲取座標函式
    {
        vector<vector<double>> data;
        double a, b, c;
        while (cin >> a >> b >> c)
        {
            vector<double> t;
            t.push_back(b);
            t.push_back(c);
            data.push_back(t);
        }
        return data;
    }
    vector<vector<double>> getDM(vector<vector<double>> Coord) //函式2：獲取距離矩陣函式
    {
        vector<vector<double>> res;

        for (int i = 0; i < Coord.size(); ++i)
        {
            vector<double> t;
            for (int j = 0; j < Coord.size(); ++j)
            {
                double dis = squr(pow(Coord[i][0] - Coord[j][0], 2) + pow(Coord[i][1] - Coord[j][1], 2));
                t.push_back(dis);
            }
            res.push_back(t);
        }
        return res;
    }
    vector<int> getInitS(int n);                                  //函式3：獲取初始解函式
    double Eval(vector<int> S, vector<vector<double>> DM, int n); //函式4：評價函式

    vector<double> bestS(vector<double> Eval, int Length); //函式5：搜尋範圍內最優評價值及其相應的位置函式

    vector<int> RandPosition(int n);                   //函式6：產生Sharking操作位置函式
    vector<int> Swap(vector<int> S, vector<int> RP);   //函式7：交換運算元
    vector<int> Flip(vector<int> S, vector<int> RP);   //函式8：翻轉運算元
    vector<int> Insert(vector<int> S, vector<int> RP); //函式9：插入運算元
};

#include <iostream>
#include <vector>
#include <numeric> //accumulate
#include <chrono>  //time
using namespace std;
using namespace chrono;

//設定演算法引數
#define POP_SIZE 2
#define MAX_GEN 4000

int main()
{
    //計時開始
    auto start = system_clock::now();

    //生成距離矩陣
    HeuristicOperator ga_dm;
    vector<vector<double>> GA_DM;
    GA_DM = ga_dm.getDM(ga_dm.getCoord());

    int n = int(GA_DM[0].size()); //城市規模

    //初始化演算法
    vector<vector<int>> initPop(POP_SIZE, vector<int>(n)); //初始種群
    vector<vector<int>> Pop(POP_SIZE, vector<int>(n));     //當前種群
    vector<vector<int>> newPop(POP_SIZE, vector<int>(n));  //新種群
    vector<double> popFit(POP_SIZE);                       //記錄種群適應度值
    vector<int> bestIndival(n);                            //最優個體
    vector<double> gs(MAX_GEN + 1);                        //記錄全域性最優解
    gs[0] = 1e9;
    unsigned int seed = (unsigned)std::chrono::system_clock::now().time_since_epoch().count();

    //生成初始種群
    HeuristicOperator s0;
    for (int i = 0; i < POP_SIZE; i++)
    {
        initPop[i] = s0.getInitS(n);
    }
    Pop = initPop;

    //開始進化
    for (int gen = 1; gen <= MAX_GEN; gen++)
    {

        HeuristicOperator eval; //計算種群的適應度值（這裡直接用路徑長度表示）
        for (int i = 0; i < POP_SIZE; i++)
        {
            popFit[i] = eval.Eval(Pop[i], GA_DM, n);
        }

        HeuristicOperator bestEI; //找出種群中個體的最優適應度值並記錄相應的個體編號
        vector<double> bestEvalIndex(2);
        bestEvalIndex = bestEI.bestS(popFit, POP_SIZE);
        double bestEval = bestEvalIndex[0];    //最優適應度值
        int bestIndex = int(bestEvalIndex[1]); //最優適應度值對應的個體編號

        //最優解的更新
        if (bestEval < gs[gen - 1])
        { //比上一代優秀則更新
            gs[gen] = bestEval;
            bestIndival = Pop[bestIndex];
        }
        else
        { //不比上一代優秀則不更新
            gs[gen] = gs[gen - 1];
        }
        if (gen % 100 == 0)
        {
            cout << "第" << gen << "次迭代時全域性最優評價值為" << gs[gen] << endl;
        }

        //擾動操作（產生新種群）
        for (int p = 0; p < POP_SIZE; p++)
        {
            HeuristicOperator shk;
            vector<int> randPosition = shk.RandPosition(n);
            vector<int> tmpS(n);
            double randShk = rand() / double(RAND_MAX);
            if (randShk < 0.33)
            {
                tmpS = shk.Swap(Pop[p], randPosition); //交換操作
            }
            else if (randShk >= 0.67)
            {
                tmpS = shk.Flip(Pop[p], randPosition); //翻轉操作
            }
            else
            {
                tmpS = shk.Insert(Pop[p], randPosition); //插入操作
            }

            HeuristicOperator evl;
            if (evl.Eval(tmpS, GA_DM, n) > evl.Eval(Pop[p], GA_DM, n))
            {
                newPop[p] = Pop[p];
            }
            else
            {
                newPop[p] = tmpS;
            }
        }
        Pop = newPop;

        //選擇操作（輪盤賭）
        vector<double> Cusum(POP_SIZE + 1, 0); //適用於輪盤賭的累加器Cusum（補充了cus[0]=0;
        for (int i = 0; i < POP_SIZE; i++)
        {
            Cusum[i + 1] = Cusum[i] + popFit[i];
        }

        double Sum = accumulate(popFit.begin(), popFit.end(), 0.0); //計算各個體被選擇的概率（歸一化）
        vector<double> cusFit(POP_SIZE + 1);                        //放置種群中個個體被選擇的概率值
        for (int i = 0; i < POP_SIZE + 1; i++)
        {
            cusFit[i] = Cusum[i] / Sum;
        }

        for (int p = 0; p < POP_SIZE; p++)
        { //輪盤賭產生新種群
            double r = rand() / double(RAND_MAX);
            for (int q = 0; q < POP_SIZE; q++)
            {
                if (r > cusFit[q] && r <= cusFit[q + 1])
                {
                    newPop[p] = Pop[q];
                }
            }
        }
        Pop = newPop;
    }

    //計時結束
    auto end = system_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << "花費了"
         << double(duration.count()) * microseconds::period::num / microseconds::period::den
         << "秒" << endl;

    //輸出結果
    double gs0 = 15377.711;
    cout << "最優解為" << gs[MAX_GEN] << endl;
    double e = (gs[MAX_GEN] - gs0) / gs0;
    cout << "誤差為" << e * 100.0 << '%' << endl;
    cout << "最優路徑為" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << bestIndival[i] + 1 << '\t';
    }
}
