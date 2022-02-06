// Description

// 假定09-2已經完成。

// 現在我們有 abstract class 定義如下：
#include "0902_List 3-2.cpp"
template <typename T>
class Container
{
public:
    virtual void push(T) = 0;
    virtual void pop() = 0;
    virtual T top() const = 0;
    virtual bool empty() const = 0;
};
// push 會存入一筆資料。
// pop 會刪除一筆資料，若無資料則會 throw 一個 std::out_of_range 例外。
// top 會回傳下一次將被刪除的資料，若無資料則會 throw 一個 std::out_of_range 例外。
// empty 會判斷 Container 是否保有資料，若無回傳true，否則回傳false。
// Queue 是一種每次都會刪除最先存入的資料的 Container，請利用 List 和 Container 來完成之。(top 的例外訊息為 "This queue is empty.")

template <typename T>
class Queue : public Container<T>, public List<T>
{
public:
    void push(T n)
    {
        List<T>::push_front(n);
    }
    void pop()
    {
        if (empty())
            throw std::out_of_range("This queue is empty.");
        List<T>::pop_back();
    }
    T top() const
    {
        if (empty())
            throw std::out_of_range("This queue is empty.");
        return this->tail->prev->data;
    }
    bool empty() const
    {
        return List<T>::empty();
    }
};
