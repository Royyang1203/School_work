#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <limits>
#include <climits>
#include <ctime>
#include <vector>

using namespace std;

class Randoms
{

private:
    long xpto;

public:
    Randoms(long x) { xpto = -x; }

    double Normal(double avg, double sigma)
    {
        return (avg + sigma * gaussdev(&xpto));
    }

    double Uniforme()
    {
        return ran1(&xpto);
    }

    double sorte(int m)
    {
        return (1.0 * rand()) / (1.0 * RAND_MAX) * 2.0 * m - m;
    }

#define IA 16807
#define IM 2147483647
#define AM (1.0 / IM)
#define IQ 127773
#define IR 2836
#define NTAB 32
#define NDIV (1 + (IM - 1) / NTAB)
#define EPS 1.2e-7
#define RNMX (1.0 - EPS)

    float ran1(long *idum)
    {
        int j;
        long k;
        static long iy = 0;
        static long iv[NTAB];
        float temp;
        if (*idum <= 0 || !iy)
        {
            if (-(*idum) < 1)
                *idum = 1;
            else
                *idum = -(*idum);
            for (j = NTAB + 7; j >= 0; j--)
            {
                k = (*idum) / IQ;
                *idum = IA * (*idum - k * IQ) - IR * k;
                if (*idum < 0)
                    *idum += IM;
                if (j < NTAB)
                    iv[j] = *idum;
            }
            iy = iv[0];
        }
        k = (*idum) / IQ;
        *idum = IA * (*idum - k * IQ) - IR * k;
        if (*idum < 0)
            *idum += IM;
        j = iy / NDIV;
        iy = iv[j];
        iv[j] = *idum;
        if ((temp = AM * iy) > RNMX)
            return RNMX;
        else
            return temp;
    }

    float gaussdev(long *idum)
    {
        //    float ran1(long *idum);

        static int iset = 0;
        static float gset;
        float fac, rsq, v1, v2;
        if (*idum < 0)
            iset = 0;
        if (iset == 0)
        {
            do
            {
                v1 = 2.0 * ran1(idum) - 1.0;
                v2 = 2.0 * ran1(idum) - 1.0;
                rsq = v1 * v1 + v2 * v2;

            } while (rsq >= 1.0 || rsq == 0.0);
            fac = sqrt(-2.0 * log(rsq) / rsq);

            gset = v1 * fac;
            iset = 1;
            return v2 * fac;
        }
        else
        {
            iset = 0;
            return gset;
        }
    }
};

class ACO
{
public:
    ACO(int nAnts, int nCities,
        double alpha, double beta, double q, double ro, double taumax,
        int initCity);
    virtual ~ACO();

    void init();

    void connectCITIES(int cityi, int cityj);
    void setCITYPOSITION(int city, double x, double y);

    void printPHEROMONES();
    void printGRAPH();
    void printRESULTS();

    void optimize(int ITERATIONS);

private:
    double distance(int cityi, int cityj);
    bool exists(int cityi, int cityc);
    bool vizited(int antk, int c);
    double PHI(int cityi, int cityj, int antk);

    double length(int antk);

    int city();
    void route(int antk);
    int valid(int antk, int iteration);

    void updatePHEROMONES();

    int NUMBEROFANTS, NUMBEROFCITIES, INITIALCITY;
    double ALPHA, BETA, Q, RO, TAUMAX;

    double BESTLENGTH;
    int *BESTROUTE;

    int **GRAPH, **ROUTES;
    double **CITIES, **PHEROMONES, **DELTAPHEROMONES, **PROBS;

    Randoms *randoms;
};

ACO::ACO(int nAnts, int nCities,
         double alpha, double beta, double q, double ro, double taumax,
         int initCity)
{
    NUMBEROFANTS = nAnts;
    NUMBEROFCITIES = nCities;
    ALPHA = alpha;
    BETA = beta;
    Q = q;
    RO = ro;
    TAUMAX = taumax;
    INITIALCITY = initCity;

    randoms = new Randoms(21);
}
ACO::~ACO()
{
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        delete[] GRAPH[i];
        delete[] CITIES[i];
        delete[] PHEROMONES[i];
        delete[] DELTAPHEROMONES[i];
        if (i < NUMBEROFCITIES - 1)
        {
            delete[] PROBS[i];
        }
    }
    delete[] GRAPH;
    delete[] CITIES;
    delete[] PHEROMONES;
    delete[] DELTAPHEROMONES;
    delete[] PROBS;
}

void ACO::init()
{
    GRAPH = new int *[NUMBEROFCITIES];
    CITIES = new double *[NUMBEROFCITIES];
    PHEROMONES = new double *[NUMBEROFCITIES];
    DELTAPHEROMONES = new double *[NUMBEROFCITIES];
    PROBS = new double *[NUMBEROFCITIES - 1];
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        GRAPH[i] = new int[NUMBEROFCITIES];
        CITIES[i] = new double[2];
        PHEROMONES[i] = new double[NUMBEROFCITIES];
        DELTAPHEROMONES[i] = new double[NUMBEROFCITIES];
        PROBS[i] = new double[2];
        for (int j = 0; j < 2; j++)
        {
            CITIES[i][j] = -1.0;
            PROBS[i][j] = -1.0;
        }
        for (int j = 0; j < NUMBEROFCITIES; j++)
        {
            GRAPH[i][j] = 0;
            PHEROMONES[i][j] = 0.0;
            DELTAPHEROMONES[i][j] = 0.0;
        }
    }

    ROUTES = new int *[NUMBEROFANTS];
    for (int i = 0; i < NUMBEROFANTS; i++)
    {
        ROUTES[i] = new int[NUMBEROFCITIES];
        for (int j = 0; j < NUMBEROFCITIES; j++)
        {
            ROUTES[i][j] = -1;
        }
    }

    BESTLENGTH = (double)INT_MAX;
    BESTROUTE = new int[NUMBEROFCITIES];
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        BESTROUTE[i] = -1;
    }
}

void ACO::connectCITIES(int cityi, int cityj)
{
    GRAPH[cityi][cityj] = 1;
    PHEROMONES[cityi][cityj] = randoms->Uniforme() * TAUMAX;
    GRAPH[cityj][cityi] = 1;
    PHEROMONES[cityj][cityi] = PHEROMONES[cityi][cityj];
}
void ACO::setCITYPOSITION(int city, double x, double y)
{
    CITIES[city][0] = x;
    CITIES[city][1] = y;
}
void ACO::printPHEROMONES()
{
    cout << " PHEROMONES: " << endl;
    cout << "  | ";
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        printf("%5d   ", i);
    }
    cout << endl
         << "- | ";
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        cout << "--------";
    }
    cout << endl;
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < NUMBEROFCITIES; j++)
        {
            if (i == j)
            {
                printf("%5s   ", "x");
                continue;
            }
            if (exists(i, j))
            {
                printf("%7.3f ", PHEROMONES[i][j]);
            }
            else
            {
                if (PHEROMONES[i][j] == 0.0)
                {
                    printf("%5.0f   ", PHEROMONES[i][j]);
                }
                else
                {
                    printf("%7.3f ", PHEROMONES[i][j]);
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

double ACO::distance(int cityi, int cityj)
{
    return (double)
        sqrt(pow(CITIES[cityi][0] - CITIES[cityj][0], 2) +
             pow(CITIES[cityi][1] - CITIES[cityj][1], 2));
}

bool ACO::exists(int cityi, int cityc)
{
    return (GRAPH[cityi][cityc] == 1);
}

bool ACO::vizited(int antk, int c)
{
    for (int l = 0; l < NUMBEROFCITIES; l++)
    {
        if (ROUTES[antk][l] == -1)
        {
            break;
        }
        if (ROUTES[antk][l] == c)
        {
            return true;
        }
    }
    return false;
}
double ACO::PHI(int cityi, int cityj, int antk)
{
    double ETAij = (double)pow(1 / distance(cityi, cityj), BETA);
    double TAUij = (double)pow(PHEROMONES[cityi][cityj], ALPHA);

    double sum = 0.0;
    for (int c = 0; c < NUMBEROFCITIES; c++)
    {
        if (exists(cityi, c))
        {
            if (!vizited(antk, c))
            {
                double ETA = (double)pow(1 / distance(cityi, c), BETA);
                double TAU = (double)pow(PHEROMONES[cityi][c], ALPHA);
                sum += ETA * TAU;
            }
        }
    }
    return (ETAij * TAUij) / sum;
}

double ACO::length(int antk)
{
    double sum = 0.0;
    for (int j = 0; j < NUMBEROFCITIES - 1; j++)
    {
        sum += distance(ROUTES[antk][j], ROUTES[antk][j + 1]);
    }
    return sum;
}

int ACO::city()
{
    double xi = randoms->Uniforme();
    int i = 0;
    double sum = PROBS[i][0];
    while (sum < xi)
    {
        i++;
        sum += PROBS[i][0];
    }
    return (int)PROBS[i][1];
}

void ACO::route(int antk)
{
    ROUTES[antk][0] = INITIALCITY;
    for (int i = 0; i < NUMBEROFCITIES - 1; i++)
    {
        int cityi = ROUTES[antk][i];
        int count = 0;
        for (int c = 0; c < NUMBEROFCITIES; c++)
        {
            if (cityi == c)
            {
                continue;
            }
            if (exists(cityi, c))
            {
                if (!vizited(antk, c))
                {
                    PROBS[count][0] = PHI(cityi, c, antk);
                    PROBS[count][1] = (double)c;
                    count++;
                }
            }
        }

        // deadlock
        if (0 == count)
        {
            return;
        }

        ROUTES[antk][i + 1] = city();
    }
}
int ACO::valid(int antk, int iteration)
{
    for (int i = 0; i < NUMBEROFCITIES - 1; i++)
    {
        int cityi = ROUTES[antk][i];
        int cityj = ROUTES[antk][i + 1];
        if (cityi < 0 || cityj < 0)
        {
            return -1;
        }
        if (!exists(cityi, cityj))
        {
            return -2;
        }
        for (int j = 0; j < i - 1; j++)
        {
            if (ROUTES[antk][i] == ROUTES[antk][j])
            {
                return -3;
            }
        }
    }

    if (!exists(INITIALCITY, ROUTES[antk][NUMBEROFCITIES - 1]))
    {
        return -4;
    }

    return 0;
}

void ACO::printGRAPH()
{
    cout << " GRAPH: " << endl;
    cout << "  | ";
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        cout << i << " ";
    }
    cout << endl
         << "- | ";
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        cout << "- ";
    }
    cout << endl;
    int count = 0;
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        cout << i << " | ";
        for (int j = 0; j < NUMBEROFCITIES; j++)
        {
            if (i == j)
            {
                cout << "x ";
            }
            else
            {
                cout << GRAPH[i][j] << " ";
            }
            if (GRAPH[i][j] == 1)
            {
                count++;
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << "Number of connections: " << count << endl
         << endl;
}
void ACO::printRESULTS()
{
    BESTLENGTH += distance(BESTROUTE[NUMBEROFCITIES - 1], INITIALCITY);
    // cout << "BEST ROUTE:" << endl;
    // for (int i = 0; i < NUMBEROFCITIES; i++)
    // {
    //     cout << BESTROUTE[i] << " ";
    // }
    // cout << endl;
    cout << BESTLENGTH << endl;

    // cout << endl
    //      << " IDEAL ROUTE:" << endl;
    // cout << "0 7 6 2 4 5 1 3" << endl;
    // cout << "length: 127.509" << endl;
}

void ACO::updatePHEROMONES()
{
    for (int k = 0; k < NUMBEROFANTS; k++)
    {
        double rlength = length(k);
        for (int r = 0; r < NUMBEROFCITIES - 1; r++)
        {
            int cityi = ROUTES[k][r];
            int cityj = ROUTES[k][r + 1];
            DELTAPHEROMONES[cityi][cityj] += Q / rlength;
            DELTAPHEROMONES[cityj][cityi] += Q / rlength;
        }
    }
    for (int i = 0; i < NUMBEROFCITIES; i++)
    {
        for (int j = 0; j < NUMBEROFCITIES; j++)
        {
            PHEROMONES[i][j] = (1 - RO) * PHEROMONES[i][j] + DELTAPHEROMONES[i][j];
            DELTAPHEROMONES[i][j] = 0.0;
        }
    }
}

void ACO::optimize(int ITERATIONS)
{
    for (int iterations = 1; iterations <= ITERATIONS; iterations++)
    {
        // cout << flush;
        // cout << "ITERATION " << iterations << " HAS STARTED!" << endl
        //      << endl;

        for (int k = 0; k < NUMBEROFANTS; k++)
        {
            // cout << " : ant " << k << " has been released!" << endl;
            while (0 != valid(k, iterations))
            {
                // cout << "  :: releasing ant " << k << " again!" << endl;
                for (int i = 0; i < NUMBEROFCITIES; i++)
                {
                    ROUTES[k][i] = -1;
                }
                route(k);
            }

            // for (int i = 0; i < NUMBEROFCITIES; i++)
            // {
            //     cout << ROUTES[k][i] << " ";
            // }
            // cout << endl;

            // cout << "  :: route done" << endl;
            double rlength = length(k);

            if (rlength < BESTLENGTH)
            {
                BESTLENGTH = rlength;
                for (int i = 0; i < NUMBEROFCITIES; i++)
                {
                    BESTROUTE[i] = ROUTES[k][i];
                }
            }
            // cout << " : ant " << k << " has ended!" << endl;
        }

        // cout << endl << "updating PHEROMONES . . .";
        updatePHEROMONES();
        // cout << " done!" << endl
        //      << endl;
        // printPHEROMONES();

        for (int i = 0; i < NUMBEROFANTS; i++)
        {
            for (int j = 0; j < NUMBEROFCITIES; j++)
            {
                ROUTES[i][j] = -1;
            }
        }

        // cout << endl
        //      << "ITERATION " << iterations << " HAS ENDED!" << endl
        //      << endl;
    }
}

//  200 45
#define ITERATIONS (int)200
#define NUMBEROFANTS (int)45
#define NUMBEROFCITIES (int)20

// if (ALPHA == 0) { stochastic search & sub-optimal route }
#define ALPHA (double)0.4
// if (BETA  == 0) { sub-optimal route }
#define BETA (double)2.5
// Estimation of the suspected best route.
#define Q (double)80
// Pheromones evaporation.
#define RO (double)0.2
// Maximum pheromone random number.
#define TAUMAX (int)1

#define INITIALCITY (int)0

int main()
{
    vector<vector<double>> data;
    double a, b, c;
    while (cin >> a >> b >> c)
    {
        vector<double> t;
        t.push_back(a);
        t.push_back(b);
        t.push_back(c);
        data.push_back(t);
    }
    // cout << data.size() << endl;
    // CITY_NUM = data.size();

    ACO *ANTS = new ACO(NUMBEROFANTS, data.size(),
                        ALPHA, BETA, Q, RO, TAUMAX,
                        INITIALCITY);

    ANTS->init();

    for (int i = 0; i < data.size(); ++i)
    {
        for (int j = i + 1; j < data.size(); ++j)
        {
            ANTS->connectCITIES(i, j);
        }
    }

    for (int i = 0; i < data.size(); ++i)
    {
        ANTS->setCITYPOSITION(i, data[i][1], data[i][2]);
    }

    clock_t start_time = clock();
    // ANTS->printGRAPH();

    // ANTS->printPHEROMONES();

    ANTS->optimize(ITERATIONS);

    ANTS->printRESULTS();

    clock_t end_time = clock();
    cout << "Running time : " << static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
    return 0;
}
