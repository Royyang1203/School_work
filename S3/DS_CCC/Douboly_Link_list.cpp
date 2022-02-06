#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>

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
    Node(const T &_d)
    {
        data = new T;
        *data = _d;
    }

    void setData(const T &_d)
    {
        *data = _d;
    }
    T getData() const
    {
        return *data;
    }

    Node &operator=(const T &_d)
    {
        *data = _d;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &_n)
    {
        os << *(_n.data);
        return os;
    }
    friend std::ostream &operator<<(std::ostream &os, Node *n)
    {
        os << *(n->data);
        return os;
    }
};

template <class T>
class ListNode : public Node<T>
{
private:
    ListNode *prev = nullptr;
    ListNode *next = nullptr;

public:
    ListNode() : Node<T>() {}
    ListNode(const T &_d) : Node<T>(_d) {}
    ListNode(ListNode *_p, ListNode *_n) : Node<T>(), prev(_p), next(_n) {}
    ListNode(const T &_d, ListNode *_p, ListNode *_n) : Node<T>(_d), prev(_p), next(_n) {}

    ListNode *get_next() const
    {
        return next;
    }
    ListNode *get_prev() const
    {
        return prev;
    }
    void set_next(ListNode *_n)
    {
        next = _n;
    }
    void set_prev(ListNode *_p)
    {
        prev = _p;
    }

    ListNode &operator=(const T &_d)
    {
        this->setData(_d);
        return *this;
    }
};

template <class T>
class LinkList
{
public:
    LinkList()
    {
        head = NULL;
        tail = NULL;
    }
    void addFromHead(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (head != NULL)
        {
            head->setPrev(node);
        }
        node->setNext(head);
        head = node;
        if (tail == NULL)
            tail = node;
    }
    void addFromTail(T d)
    {
        ListNode<T> *node = new ListNode<T>(d);
        if (tail != NULL)
        {
            tail->setNext(node);
        }
        node->setPrev(tail);
        tail = node;
        if (head == NULL)
            head = node;
    }
    void addAfter(ListNode<T> *at, T d)
    {
        if (!exist(at))
            return;
        ListNode<T> *node = new ListNode<T>(d);
        if (at->getNext() != NULL)
            at->getNext()->setPrev(node);
        node->setNext(at->getNext());
        at->setNext(node);
        node->setPrev(at);
        if (node->getNext() == NULL)
            tail = node;
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
        return n;
    }
    ListNode<T> *remove(ListNode<T> *n)
    {
        if (!exist(n))
            return NULL;
        if (n == head)
            return removeFromHead();
        if (n == tail)
            return removeFromTail();
        n->getPrev()->setNext(n->getNext());
        n->getNext()->setPrev(n->getPrev());
        n->setNext(NULL);
        n->setPrev(NULL);
        return n;
    }
    ListNode<T> *exist(T d)
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
    ListNode<T> &operator[](int i)
    {
        ListNode<T> *j = head;
        int k;
        for (k = 0; k < i && j != NULL; k++)
            j = j->getNext();
        if (j == NULL)
            throw std::invalid_argument("index does not exist.");
        return *j;
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

protected:
    ListNode<T> *head, *tail;
};

template <typename T>
class Douboly_Link_List
{
private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

public:
    Douboly_Link_List(){
        ListNode} Douboly_Link_List(T &data)
};
