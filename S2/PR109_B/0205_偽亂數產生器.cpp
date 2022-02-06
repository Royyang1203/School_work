// Description

// 偽亂數產生器(PRNG, Pseudo Random Number Generator) 是一個產生類亂數的方法。其方法很簡單。

// 指定 seed
// 將算出的亂數回存 seed
// 以 seed 算出下一筆亂數
// 今天請你使用(seed * 1103515245 + 12345) MOD 2 ^ 31
// 來完成 class Random

// 請注意乘法會 overflow 的問題。 所有運算請轉型成 unsigned long long 型別來執行
class Random
{
private:
    unsigned long long seed;

public:
    void set_seed(int seed)
    {
        this->seed = seed;
    }
    int next_int()
    {
        seed = ((unsigned long long)seed * 1103515245 + 12345) % (1ULL << 31);
        return seed;
    }
};
