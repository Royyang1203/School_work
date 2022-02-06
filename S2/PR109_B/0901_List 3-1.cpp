// Description

// 請將05-1改為 template class, 使其可以存取 int 之外的類別, 並額外提供能將prev,next都設為nullptr的 default constructure。

#include <iostream>
template <typename T>
class ListNode
{
public:
    T data;
    ListNode *prev, *next;
    ListNode() : prev(nullptr), next(nullptr) {}
    ListNode(T Data, ListNode<T> *Prev = nullptr, ListNode<T> *Next = nullptr) : data(Data), prev(Prev), next(Next) {}
    ~ListNode()
    {
        if (next != NULL && prev != NULL)
        {
            next->prev = prev;
            prev->next = next;
        }
        else if (next == NULL && prev != NULL)
        {
            prev->next = NULL;
        }
        else if (next != NULL && prev == NULL)
        {
            next->prev = NULL;
        }
    }
};