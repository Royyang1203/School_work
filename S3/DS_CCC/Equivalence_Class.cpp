#include <iostream>
#include <cstdlib>

using namespace std;

class ListNode;
class Equivalence;

class Node
{
    friend class ListNode;
    friend class Equivalence;

private:
    int data = 0;
    Node *next = nullptr;

public:
    Node() = default;
    Node(int _d, Node *_n) : data(_d), next(_n) {}
    ~Node() {}
};

class ListNode
{
    friend class Equivalence;

private:
    Node *ptr = nullptr;
    ListNode *next = nullptr;

public:
    ListNode() = default;
    ListNode(int _d)
    {
        Node *t = new Node(_d);
        Add_node(t);
    }

    ListNode &Add_node(Node *_d)
    {
        while (ptr)
        {
            ++ptr;
        }
        ptr->
    }

    ~ListNode() {}
};
class Equivalence
{
private:
    ListNode *data = nullptr;
    bool *out = nullptr;

public:
    Equivalence() = default;
    Equivalence &Add_data(int _d)
    {
        ListNode *t = new ListNode(_d);
    }
    ~Equivalence() {}
};