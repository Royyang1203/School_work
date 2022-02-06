// Description

// 我們可以利用 static data member 的特性來保証執行期間，同時存在最多 1 個實體，方法如下：

// 宣告一個指向自身的靜態指標變數。
// 將該靜態指標初始為nullptr。
// 在建構時，如果該靜態指標為nullptr，則將其指向this。
// 在解構時，如果該靜態指標指向this，則將其指向nullptr。
// 在本題中，如果初始化失敗(3. 時該標不為nullptr)，則拋出帶有 "Occupied" 訊息的 runtime_error 例外。
#include <iostream>
#include <stdexcept>
using namespace std;
class Singleton
{
    static Singleton *ptr;

public:
    Singleton()
    {
        if (ptr == nullptr)
        {
            ptr = this;
        }
        else
        {
            throw runtime_error("Occupied");
        }
    }
    ~Singleton()
    {
        if (ptr == this)
        {
            ptr = nullptr;
        }
    }
};
Singleton *Singleton::ptr = nullptr;