// Description

// 現在有一個雙向鏈結串列的節點結構定義如下：

// class ListNode {
// public:
//     int data;
//     ListNode *prev, *next;
//     ListNode(int Data, ListNode* Prev, ListNode *Next);
//     ~ListNode();
// };
// 建構子用於設定 data member 之初值。
// 解構子會在自己被刪除時將 prev, next 兩方的點正確地連接在一起請完成該 class

#include <iostream>
class ListNode
{
public:
    int data;
    ListNode *prev, *next;
    ListNode(int Data, ListNode *Prev, ListNode *Next)
    {
        data = Data;
        prev = Prev;
        next = Next;
    }
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