// Description

// 假定05-1已經完成了。現有用於管理 ListNode 的類別定義如下：

// class List {
// private:
//     ListNode *head, *tail;
// public:
//     List();
//     ~List();
//     void push_front(int val);
//     void push_back(int val);
//     void pop_front();
//     void pop_back();
//     void pop_index(int idx);
//     friend std::ostream& operator << (std::ostream&, const List&);
// };
// List() 將 head, tail 設為 NULL
// ~List() 將所有的 ListNode 刪除
// push_front 將值為 val 的節點插入於串列頭。
// push_back 將值為 val 的節點插入於串列尾。
// pop_front 將位於串列頭的節點刪除，若串列為空則丟出帶有"The list is empty." 訊息的 out_of_range 例外。
// pop_back 將位於串列尾的節點刪除，若串列為空處理同 pop_front。
// pop_index(int idx) 將位於 idx 的節點刪除(編號規則同陣列)，若該節點不存在則丟出帶有 "The node is not exists." 訊息的 out_of_range 例外。
// 請完成該類別之實作(不含 friend)。
#include "0501_List_1_1.cpp"
#include <iostream>
#include <stdexcept>
using namespace std;
class List
{
private:
    ListNode *head, *tail;

public:
    List()
    {
        head = tail = NULL;
    }
    ~List()
    {
        while (head)
            pop_front();
    }

    void push_front(int val)
    {
        head = new ListNode(val, nullptr, head);
        if (tail == nullptr)
            tail = head;
        else
            head->next->prev = head;
    }

    void push_back(int val)
    {
        tail = new ListNode(val, tail, nullptr);
        if (head == nullptr)
            head = tail;
        else
            tail->prev->next = tail;
    }

    void pop_front()
    {
        if (head != NULL)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr)
                tail = nullptr;
        }
        else
        {
            throw out_of_range("The list is empty.");
        }
    }

    void pop_back()
    {
        if (tail != NULL)
        {
            ListNode *temp = tail;
            tail = tail->prev;
            delete temp;
            if (tail == nullptr)
                head = nullptr;
        }
        else
        {
            throw out_of_range("The list is empty.");
        }
    }

    void pop_index(int n)
    {
        if (head == nullptr)
            throw out_of_range("The node is not exists.");
        ListNode *tar = head;
        for (int i = 0; i < n; ++i)
        {
            if (tar == nullptr)
                throw out_of_range("The node is not exists.");
            tar = tar->next;
        }
        if (tar->prev == nullptr)
            pop_front();
        else if (tar->next == nullptr)
            pop_back();
        else
            delete tar;
    }

    friend std::ostream &operator<<(std::ostream &out, const List &list);
};