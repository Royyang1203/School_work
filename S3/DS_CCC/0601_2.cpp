#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <set>
#include <deque>

using namespace std;

template <class T>
class ListNode
{
public:
    T data;
    ListNode *next;
    ListNode()
    {
        next = NULL;
    }
    ListNode(T d)
    {
        data = d;
        next = NULL;
    }
};

template <class T>
class LinkList
{
public:
    ListNode<T> *head;
    ListNode<T> *tail;
    int count;
    LinkList()
    {
        head = new ListNode();
        tail = head;
        count = 0;
    }
    ListNode<T> *add_node(T d)
    {
        ListNode<T> *cur = head;
        while (cur->next != NULL && cur->next->data < d)
        {
            cur = cur->next;
        }
        ListNode<T> *node = new ListNode<T>(d);
        node->next = cur->next;
        cur->next = node;
        return node;
    }
};

class Graph
{
public:
    LinkList int count;

    Graph()
    {
        count = 0;
        for (int i = 0; i < 100; ++i)
        {
            for (int j = 0; j < 100; ++j)
            {
                m[i][j] = 0;
            }
            ver[i] = 0;
        }
    }
    int find_vertex(int d)
    {
        for (int i = 0; i < count; ++i)
        {
            if (ver[i] == d)
                return i;
        }
        return -1;
    }
    int add_vertex(int d)
    {
        if (count == 100)
        {
            cout << "out of range";
            return -1;
        }
        ver[count++] = d;
        return count - 1;
    }
    void addedge(int a, int b)
    {
        int i1 = find_vertex(a);
        int i2 = find_vertex(b);
        if (i1 == -1)
        {
            i1 = add_vertex(a);
        }
        if (i2 == -1)
        {
            i2 = add_vertex(b);
        }
        m[i1][i2] = 1;
        m[i2][i1] = 1;
    }
};

class GraphNode
{
public:
    int data;
};

int main()
{
    int n;
    cin >> n;
    Graph g;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g.addedge(a, b);
    }
}