// Description

// 將偽亂數產生器中的 seed 改為靜態變數。

class Random
{
private:
    static int seed;

public:
    void static set_seed(int _s)
    {
        seed = _s;
    }
    static int next_int()
    {
        int x;
        x = ((seed) * (1103515245U) + (12345U)) % 2147483648;
        set_seed(x);
        return x;
    }
};
int Random::seed = 0;