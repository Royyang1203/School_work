// Assignment 6: DFS and Finding Articulation Points in Graphs

// Descriptions

// 	Given a graph with each vertex identified by a number ID, you are required to implement the algorithm for finding all articulation points which is given by Section 6.2.5 in the textbook. In addition to the found articulation points, your implementation also needs to output the output sequence of a DFS, given a starting vertex. During the DFS traversal, all un-visited adjacent vertexs of any visited vertex should be traversed in the increasing order of their vertex IDs. For example, if vertex 3 is visited and its adjacent vertexs which have not been visited are Vertex 1, Vertex 4, and Vertex 2, then these three vertexs should be traversed in the order of Vertex 1, Vertex 2, and Vertex 4. After detecting all articulation points, please output them in the increasing order of vertex IDs.

// Input Specifications
// N: number of edges
// (v11, v12): Edge 1
// (v21, v22): Edge 2
// ...
// (vN1, vN1): Edge N
// S: starting vertex for DFS

// Output Specifications
// o1 o2 o3 ... oN: DFS output sequence
// AP: ap1, ap2, ...

// Example 1:

// Input:
// 11
// 0 1
// 1 3
// 1 2
// 2 4
// 3 4
// 3 5
// 5 7
// 5 6
// 6 7
// 7 8
// 7 9
// 3
// Output:
// 3 1 0 2 4 5 6 7 8 9
// AP: 1 3 5 7

// Example 2:

// Input:
// 12
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 3 4
// 3 7
// 4 7
// 4 8
// 5 6
// 6 7
// 5 9
// 3
// Output:
// 3 1 2 5 6 7 4 8 9
// AP: 4 5

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <set>
#define SIZE 100

template <class T>
class Node
{
protected:
    T *data;

public:
    Node()
    {
        data = new T;
    }
    Node(const T &d)
    {
        data = new T;
        setData(d);
    }

    Node &operator=(const T &d)
    {
        setData(d);
        return *this;
    }

    void setData(const T &d)
    {
        *data = d;
    }
    T &getData() const
    {
        return *data;
    }
};

template <class T>
class ListNode : public Node<T>
{
private:
    ListNode *prev, *next;

public:
    ListNode(ListNode *p = NULL, ListNode *n = NULL) : Node<T>(), prev(p), next(n) {}
    ListNode(const T &d, ListNode *p = NULL, ListNode *n = NULL) : Node<T>(d), prev(p), next(n) {}

    ListNode &operator=(const T &d)
    {
        this->setData(d);
        return *this;
    }

    void setNext(ListNode *n)
    {
        next = n;
    }
    void setPrev(ListNode *p)
    {
        prev = p;
    }
    ListNode *getNext()
    {
        return next;
    }
    ListNode *getPrev()
    {
        return prev;
    }
};

template <class T>
class LinkList
{
protected:
    ListNode<T> *head, *tail;
    int length;

public:
    LinkList() : head(NULL), tail(NULL), length(0) {}

    ListNode<T> &operator[](const int &i)
    {
        ListNode<T> *j = head;
        for (int k = 0; k < i && j != NULL; ++k)
            j = j->getNext();
        if (j == NULL)
            throw std::invalid_argument("index does not exist.");
        return *j;
    }

    void addFromHead(const T &d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (head != NULL)
        {
            head->setPrev(node);
        }
        node->setNext(head);
        head = node;
        ++length;
        if (tail == NULL)
            tail = node;
    }
    void addFromTail(const T &d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (tail != NULL)
        {
            tail->setNext(node);
        }
        node->setPrev(tail);
        tail = node;
        ++length;
        if (head == NULL)
            head = node;
    }
    void add_prior(const T &d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (head == NULL)
        {
            head = node;
            tail = node;
            ++length;
            return;
        }
        if (head->getData()->getData() > d->getData())
        {
            head->setPrev(node);
            node->setNext(head);
            head = node;
            ++length;
            return;
        }
        ListNode<T> *cur = head;
        while (cur->getNext() != NULL && cur->getNext()->getData()->getData() < d->getData())
        {
            cur = cur->getNext();
        }
        if (cur == tail)
        {
            tail = node;
        }
        node->setPrev(cur);
        node->setNext(cur->getNext());
        if (cur->getNext() != NULL)
            cur->getNext()->setPrev(node);
        cur->setNext(node);
        ++length;
        return;
    }
    ListNode<T> *removeFromHead()
    {
        ListNode<T> *n = head;
        if (head != NULL)
        {
            head = head->getNext();
            if (head != NULL)
                head->setPrev(NULL);
            else
                tail = NULL;
            n->setNext(NULL);
        }
        --length;
        return n;
    }
    ListNode<T> *removeFromTail()
    {
        ListNode<T> *n = tail;
        if (tail != NULL)
        {
            tail = tail->getPrev();
            if (tail != NULL)
                tail->setNext(NULL);
            else
                head = NULL;
            n->setPrev(NULL);
        }
        --length;
        return n;
    }

    ListNode<T> *exist(const T &d)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j->getData() == d)
                return j;
            j = j->getNext();
        }
        return NULL;
    }
    bool exist(ListNode<T> *n)
    {
        ListNode<T> *j = head;
        while (j != NULL)
        {
            if (j == n)
                return true;
            j = j->getNext();
        }
        return false;
    }
    int get_length()
    {
        return length;
    }
    void print() const
    {
        ListNode<T> *j;
        j = head;
        while (j != NULL)
        {
            std::cout << (*j) << " ";
            j = j->getNext();
        }
        std::cout << std::endl;
    }
};

template <class T>
class GraphNode : public Node<T>
{
private:
    LinkList<GraphNode<T> *> *list;

public:
    GraphNode() : Node<T>()
    {
        list = new LinkList<GraphNode<T> *>();
    }
    GraphNode(const T &d) : Node<T>(d)
    {
        list = new LinkList<GraphNode<T> *>();
    }

    ListNode<GraphNode<T> *> *operator[](const int &n)
    {
        try
        {
            return &(*list)[n];
        }
        catch (std::invalid_argument e)
        {
            return NULL;
        }
    }

    void addLink(GraphNode<T> *node)
    {
        list->add_prior(node);
        // list->addFromTail(node);
    }
    bool exist(GraphNode<T> *node)
    {
        if (list->exist(node))
            return true;
        return false;
    }

    int degree()
    {
        return list->get_length();
    }
};

template <class T>
class Graph
{
private:
    LinkList<GraphNode<T> *> *vertex;
    int count;

public:
    Graph()
    {
        vertex = new LinkList<GraphNode<T> *>();
        count = 0;
    }

    GraphNode<T> *operator[](const int &n)
    {
        try
        {
            return (*vertex)[n].getData();
        }
        catch (std::invalid_argument e)
        {
            return NULL;
        }
    }

    GraphNode<T> *addVertex(const T &d)
    {
        GraphNode<T> *node = new GraphNode<T>(d);
        vertex->addFromTail(node);
        ++count;
        return node;
    }
    void addLink(GraphNode<T> *node1, GraphNode<T> *node2)
    {
        node1->addLink(node2);
        node2->addLink(node1);
    }
    bool isLinked(GraphNode<T> *node1, GraphNode<T> *node2)
    {
        return node1->exist(node2);
    }

    void adjList()
    {
        int j, k;
        for (j = 0; j < count; j++)
        {
            std::cout << j << ":";
            for (k = 0; k < count; k++)
            {
                if (isLinked((*vertex)[j].getData(), (*vertex)[k].getData()))
                    std::cout << k << " ";
            }
            std::cout << std::endl;
        }
    }

    LinkList<T> *DFS(GraphNode<T> *node)
    {
        LinkList<T> *res = new LinkList<T>();
        LinkList<GraphNode<T> *> *stk = new LinkList<GraphNode<T> *>();
        stk->addFromTail(node);
        ListNode<GraphNode<T> *> *cur = stk->removeFromTail();

        while (cur != NULL)
        {
            if (!res->exist(cur->getData()->getData()))
            {
                res->addFromTail(cur->getData()->getData());
                for (int i = cur->getData()->degree() - 1; i >= 0; --i)
                {
                    stk->addFromTail((*cur->getData())[i]->getData());
                }
            }
            cur = stk->removeFromTail();
        }
        return res;
    }
    void articulation_vertex(GraphNode<T> *node, const int &n)
    {
        int order[SIZE] = {0};
        int parent[SIZE] = {0};
        int visit[SIZE] = {0};
        int trace[SIZE] = {0};
        int ap[SIZE] = {0};

        int t = 0;
        LinkList<int> stk;
        stk.addFromTail(node->getData());
        parent[node->getData()] = node->getData();

        while (!stk.get_length() == 0)
        {
            int cur = stk.removeFromTail()->getData();
            if (visit[cur])
                continue;

            visit[cur] = t + 1;
            order[t] = cur;
            ++t;

            for (int i = (*this)[cur]->degree() - 1; i >= 0; --i)
            {
                if (!visit[(*(*this)[cur])[i]->getData()->getData()])
                {
                    stk.addFromTail((*(*this)[cur])[i]->getData()->getData());
                    parent[(*(*this)[cur])[i]->getData()->getData()] = cur;
                }
            }
        }

        for (int t = n - 1; t >= 0; --t)
        {
            int i = order[t];
            trace[i] = i;
            for (int j = (*this)[i]->degree() - 1; j >= 0; --j)
            {
                int k = (*(*this)[i])[j]->getData()->getData();
                if (visit[i] < visit[k] && i == parent[k])
                {
                    if (visit[trace[k]] < visit[trace[i]])
                        trace[i] = trace[k];
                }
                else if (visit[i] > visit[k] && parent[i] != k)
                {
                    if (visit[k] < visit[trace[i]])
                        trace[i] = k;
                }
            }
        }

        for (int i = 0; i < SIZE; ++i)
            if (i == parent[i])
            {
                int child = 0;
                for (int j = (*this)[i]->degree() - 1; j >= 0; --j)
                {
                    if (i == parent[(*(*this)[i])[j]->getData()->getData()])
                        ++child;
                }
                ap[i] = (child > 1);
            }
            else
            {
                ap[i] = false;

                for (int j = (*this)[i]->degree() - 1; j >= 0; --j)
                {
                    int k = (*(*this)[i])[j]->getData()->getData();
                    if (i == parent[k])
                    {
                        if (visit[trace[k]] >= visit[i])
                        {
                            ap[i] = true;
                            break;
                        }
                    }
                }
            }
        for (int i = 0; i < n; ++i)
        {
            std::cout << order[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "AP: ";
        for (int i = 0; i < SIZE; ++i)
        {
            if (ap[i])
                std::cout << i << " ";
        }
        std::cout << std::endl;
    }
};

using namespace std;

int main()
{
    int n;
    cin >> n;
    Graph<int> g;

    for (int i = 0; i < SIZE; ++i)
    {
        g.addVertex(i);
    }
    std::set<int> gset;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        gset.insert(a);
        gset.insert(b);
        g.addLink(g[a], g[b]);
    }
    // g.adjList();
    int m;
    cin >> m;
    g.articulation_vertex(g[m], gset.size());
}