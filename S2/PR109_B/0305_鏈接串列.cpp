// Description

// 現在有定好的 List 如下：

class ListNode
{
    int data;
    ListNode *next;

public:
    int getData() const
    {
        return data;
    }
    ListNode *getNext() const
    {
        return next;
    }
    ListNode(int num) : data(num), next(nullptr)
    {
    }
    ListNode(int num, ListNode *link) : data(num), next(link)
    {
    }
    ListNode(const ListNode &head);
};
// 請實作其 Copy constructor ，令 ListNode 會複製整段資料，而非單個節點。

ListNode::ListNode(const ListNode &head)
{
    this->data = head.data;
    if (head.next != nullptr)
    {
        this->next = new ListNode(*head.next);
    }
    else
    {
        this->next = nullptr;
    }
} //end