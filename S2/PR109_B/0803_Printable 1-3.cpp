// Description

// 假定08-2已經完成，並且已存在多種不同的繼承 Printable 的 class 之實作。請設計 class PrintableArray，該 class 能夠保存多個實作 Printable 的物品，功能詳述如下：

// 由建構子來設定可保存之個數，如未設定(即使用 default constructure), 則可以保存至多 5 個物件，分隔符號預設為一空格。
// bool full() const: 如空間已滿，回傳 true，否則回傳 false。
// bool empty() const: 如未保存任何物件，回傳 true，否則回傳 false。
// size_t size() const: 回傳所保存之物件數。
// void append(Printable *item): 於尾端插入待保存之物件 item，如無法 append，請 throw 帶有錯誤訊息 `The array is full` 的 out_of_range 例外
// Printable* operator [] (size_t index): 透過 object[index] 的方式來存取第 index 號物件 (編號規則同普通陣列)。
// Printable* const operator [] (size_t index) const : 透過 object[index] 的方式來讀取第 index 號唯讀物件 (編號規則同普通陣列)。
// std::string getSeperator() const: 回傳列舉所有保存之物件時的分隔符號。
// void setSeperator(std::string): 設定列舉所有保存之物件時的分隔符號。
// 多載 << 運算子，使 PrintableArray 可以透過 std::ostream 來輸出所有保存之物件。輸出時兩兩間以所設定之分隔符隔開 (首尾無分隔符)。

#include <stdexcept>
#include <vector>
class PrintableArray
{
public:
    PrintableArray() = default;
    PrintableArray(size_t cap) : n(cap) {}
    ~PrintableArray()
    {
        v.clear();
    }
    bool full() const
    {
        return v.size() >= n;
    }
    bool empty() const
    {
        return v.empty();
    }
    size_t size() const
    {
        return v.size();
    }
    void append(Printable *item)
    {
        if (v.size() >= n)
            throw std::out_of_range("The array is full");
        v.push_back(item);
    }
    Printable *operator[](size_t index)
    {
        return v.at(index);
    }
    const Printable *const operator[](size_t index) const
    {
        return v.at(index);
    }
    std::string getSeperator() const
    {
        return seperator;
    }
    void setSeperator(std::string s)
    {
        seperator = s;
    }
    friend std::ostream &operator<<(std::ostream &out, const PrintableArray &arr);

private:
    std::vector<Printable *> v;
    size_t n = 5;
    std::string seperator = " ";
};

std::ostream &operator<<(std::ostream &out, const PrintableArray &arr)
{
    for (size_t i = 0; i < arr.n; ++i)
    {
        out << arr[i]->toString();
        if (i != arr.n - 1)
            out << arr.seperator;
    }
    return out;
}