// Description

// 假定09-1已經完成了，請利用之完成 template 版的 List。

// 建構子會初始化一個沒有存任何資料的 list。
// 解構子會刪除該 object 所有配置的空間/物件。
// push_front(data) 會於 head 端插入 data。
// push_back(data) 會於 tail 端插入 data。
// pop_front() 會刪除 head 端的物件。
// pop_back() 會判除 tail 端的物件。
// pop_front 或 pop_back 時，若為空請丟出帶有 "This list is empty." 訊息的 out_of_range 例外。
// empty() 會判斷該 object 是否為空，若是則回傳true，否判回傳false。
// operator << 會輸出List<T>中所有的成員，並用,_(底線為空白) 分隔每一筆資料。

#include <iostream>
#include <stdexcept>

template <typename T>
class List
{
protected:
    ListNode<T> *head, *tail;

public:
    List<T>()
    {
        head = tail = nullptr;
    }
    ~List<T>()
    {
        while (head)
            pop_front();
    }
    bool empty() const
    {
        return head == nullptr;
    }
    void push_front(T val)
    {
        head = new ListNode<T>(val, nullptr, head);
        if (tail == nullptr)
            tail = head;
        else
            head->next->prev = head;
    }

    void push_back(T val)
    {
        tail = new ListNode<T>(val, tail, nullptr);
        if (head == nullptr)
            head = tail;
        else
            tail->prev->next = tail;
    }

    void pop_front()
    {
        if (head != nullptr)
        {
            ListNode<T> *temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr)
                tail = nullptr;
        }
        else
        {
            throw std::out_of_range("This list is empty.");
        }
    }

    void pop_back()
    {
        if (tail != nullptr)
        {
            ListNode<T> *temp = tail;
            tail = tail->prev;
            delete temp;
            if (tail == nullptr)
                head = nullptr;
        }
        else
        {
            throw std::out_of_range("This list is empty.");
        }
    }
    friend std::ostream &operator<<(std::ostream &out, const List<T> &list)
    {

        ListNode<T> *ptr = list.head;
        while (ptr != nullptr)
        {
            if (ptr != list.head)
            {
                std::cout << ", ";
            }
            std::cout << ptr->data;
            ptr = ptr->next;
        }
        return out;

        bool first = true;
        for (ListNode<T> *temp = list.head; temp != nullptr; temp = temp->next)
        {
            if (first)
            {
                first = false;
            }
            else
            {
                out << ", ";
            }
            out << temp->data;
        }
        return out;
    }
};