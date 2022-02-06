// Description

// 一般來說儲存結構都會有以下的功能：

// 新增資料
// 刪除資料
// 現在我們有一個 abstract class 定義如下：

class Container
{
public:
    virtual void push(int) = 0;
    virtual void pop() = 0;
    virtual int top() const = 0;
    virtual bool empty() const = 0;
};
// push 會存入一個 int。
// pop 會刪除一個 int，若無資料則會 throw 一個 std::out_of_range 例外。
// top 會回傳下一次將被刪除的資料，若無資料則會 throw 一個 std::out_of_range 例外。
// empty 會判斷 Container 是否保有資料，若無回傳 true，否則回傳 false。
// 現在請你提供兩種不同的 Container 實作，分別是 Stack 和 PriorityQueue。Stack 每次都會刪除最後被新增的資料。PriorityQueue 每次都會則除目前保有的最大的資料。

#include <vector>
#include <queue>
#include <stdexcept>
#include <iostream>
class Stack : public Container
{
public:
    void push(int n)
    {
        v.push_back(n);
    }
    void pop()
    {
        if (empty())
            throw std::out_of_range("invalid.");
        v.pop_back();
    }
    int top() const
    {
        if (empty())
            throw std::out_of_range("invalid.");
        return v.back();
    }
    bool empty() const
    {
        return v.empty();
    }

private:
    std::vector<int> v;
};
class PriorityQueue : public Container
{
public:
    PriorityQueue() = default;
    void push(int n)
    {
        v.push(n);
    }
    void pop()
    {
        if (empty())
            throw std::out_of_range("invalid.");
        v.pop();
    }
    int top() const
    {
        if (empty())
            throw std::out_of_range("invalid.");
        return v.top();
    }
    bool empty() const
    {
        return v.empty();
    }

private:
    std::priority_queue<int> v;
};