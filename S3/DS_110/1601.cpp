// 我幫你們建好了一個有權重的圖的類別，請完成這個類別裡的 minimumSpanningTree 這個方法。

// I create a class WeightedGraph for you but leaves the methodminimumSpanningTree blank, please finish it.

// #include <cstdlib>
// #include <iostream>
// #include <stdexcept>
// #include <ctime>

// template <class T>
// class Node
// {
// public:
// 	Node()
// 	{
// 		data = new T;
// 	}
// 	Node(T d)
// 	{
// 		data = new T;
// 		(*data) = d;
// 	}
// 	Node &operator=(T d)
// 	{
// 		(*data) = d;
// 		return *this;
// 	}
// 	friend std::ostream &operator<<(std::ostream &out, Node n)
// 	{
// 		out<<*(n.data);
// 		return out;
// 	}
// 	friend std::ostream &operator<<(std::ostream &out, Node *n)
// 	{
// 		out<<*(n->data);
// 		return out;
// 	}
// 	void setData(T d)
// 	{
// 		*data = d;
// 	}
// 	T &getData() const
// 	{
// 		return *data;
// 	}
// protected:
// 	T *data;
// };

// template<class T>
// class ListNode : public Node<T>
// {
// public:
// 	ListNode() : Node<T>()
// 	{
// 		prev = NULL;
// 		next = NULL;
// 	}
// 	ListNode(T d) : Node<T>(d)
// 	{
// 		prev = NULL;
// 		next = NULL;
// 	}
// 	ListNode(ListNode *p, ListNode *n) : Node<T>()
// 	{
// 		prev = p;
// 		next = n;
// 	}
// 	ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
// 	{
// 		prev = p;
// 		next = n;
// 	}
// 	ListNode *getNext() const
// 	{
// 		return next;
// 	}
// 	ListNode *getPrev() const
// 	{
// 		return prev;
// 	}
// 	void setNext(ListNode *n)
// 	{
// 		next = n;
// 	}
// 	void setPrev(ListNode *p)
// 	{
// 		prev = p;
// 	}
// 	ListNode &operator=(T d)
// 	{
// 		this->setData(d);
// 		return *this;
// 	}
// private:
// 	ListNode *prev, *next;
// };

// template<class T>
// class LinkList
// {
// public:
// 	LinkList()
// 	{
// 		head = NULL;
// 		tail = NULL;
// 	}
// 	void addFromHead(T d)
// 	{
// 		ListNode<T> *node = new ListNode<T>(d);
// 		if(head != NULL)
// 		{
// 			head->setPrev(node);
// 		}
// 		node->setNext(head);
// 		head = node;
// 		if(tail == NULL)
// 			tail = node;
// 	}
// 	void addFromTail(T d)
// 	{
// 		ListNode<T> *node = new ListNode<T>(d);
// 		if(tail != NULL)
// 		{
// 			tail->setNext(node);
// 		}
// 		node->setPrev(tail);
// 		tail = node;
// 		if(head == NULL)
// 			head = node;
// 	}
// 	void addAfter(ListNode<T> *at, T d)
// 	{
// 		if(!exist(at))
// 			return;
// 		ListNode<T> *node = new ListNode<T>(d);
// 		if(at->getNext() != NULL)
// 			at->getNext()->setPrev(node);
// 		node->setNext(at->getNext());
// 		at->setNext(node);
// 		node->setPrev(at);
// 		if(node->getNext() == NULL)
// 			tail = node;
// 	}
// 	ListNode<T> *removeFromHead()
// 	{
// 		ListNode<T> *n = head;
// 		if(head != NULL)
// 		{
// 			head = head->getNext();
// 			if(head != NULL)
// 				head->setPrev(NULL);
// 			else
// 				tail = NULL;
// 			n->setNext(NULL);
// 		}
// 		return n;
// 	}
// 	ListNode<T> *removeFromTail()
// 	{
// 		ListNode<T> *n = tail;
// 		if(tail != NULL)
// 		{
// 			tail = tail->getPrev();
// 			if(tail != NULL)
// 				tail->setNext(NULL);
// 			else
// 				head = NULL;
// 			n->setPrev(NULL);
// 		}
// 		return n;
// 	}
// 	ListNode<T> *remove(ListNode<T> *n)
// 	{
// 		if(!exist(n))
// 			return NULL;
// 		if(n == head)
// 			return removeFromHead();
// 		if(n == tail)
// 			return removeFromTail();
// 		n->getPrev()->setNext(n->getNext());
// 		n->getNext()->setPrev(n->getPrev());
// 		n->setNext(NULL);
// 		n->setPrev(NULL);
// 		return n;
// 	}
// 	ListNode<T> *exist(T d)
// 	{
// 		ListNode<T> *j = head;
// 		while(j != NULL)
// 		{
// 			if(j->getData() == d)
// 				return j;
// 			j = j->getNext();
// 		}
// 		return NULL;
// 	}
// 	bool exist(ListNode<T> *n)
// 	{
// 		ListNode<T> *j = head;
// 		while(j != NULL)
// 		{
// 			if(j == n)
// 				return true;
// 			j = j->getNext();
// 		}
// 		return false;
// 	}
// 	ListNode<T> &operator[](int i)
// 	{
// 		ListNode<T> *j = head;
// 		int k;
// 		for(k = 0;k < i && j != NULL;k ++)
// 			j = j->getNext();
// 		if(j == NULL)
// 			throw std::invalid_argument("index does not exist.");
// 		return *j;
// 	}
// 	void print() const
// 	{
// 		ListNode<T> *j;
// 		j = head;
// 		while(j != NULL)
// 		{
// 			std::cout<<(*j)<<" ";
// 			j = j->getNext();
// 		}
// 		std::cout<<std::endl;
// 	}
// protected:
// 	ListNode<T> *head, *tail;
// };

// template<class V, class E>
// class WeightedGraphEdge;

// template<class V, class E>
// class WeightedGraphVertex : public Node<V>
// {
// public:
// 	WeightedGraphVertex() :Node<V>()
// 	{
// 		list = new LinkList<E>();
// 	}
// 	WeightedGraphVertex(V d) :Node<V>(d)
// 	{
// 		list = new LinkList<WeightedGraphEdge<V, E> *>();
// 	}
// 	void addEdge(WeightedGraphEdge<V, E> *edge)
// 	{
// 		list->addFromTail(edge);
// 	}
// 	void remove(WeightedGraphEdge<V, E> *node)
// 	{
// 	}
// 	ListNode<WeightedGraphEdge<V, E> *> *operator[](int n)
// 	{
// 		try
// 		{
// 			return (&(*list)[n]);
// 		}
// 		catch(std::invalid_argument e)
// 		{
// 			return NULL;
// 		}
// 	}
// private:
// 	LinkList<WeightedGraphEdge<V, E> *> *list;
// };

// template<class V, class E>
// class WeightedGraphEdge : public Node<E>
// {
// public:
// 	WeightedGraphEdge() : Node<E>()
// 	{
// 		end[0] = NULL;
// 		end[1] = NULL;
// 	}
// 	WeightedGraphEdge(E d) : Node<E>(d)
// 	{
// 		end[0] = NULL;
// 		end[1] = NULL;
// 	}
// 	WeightedGraphEdge(E d, WeightedGraphVertex<V, E> *v1, WeightedGraphVertex<V, E> *v2) : Node<E>(d)
// 	{
// 		end[0] = v1;
// 		end[1] = v2;
// 	}
// 	WeightedGraphVertex<V, E> *&getAnotherEnd(WeightedGraphVertex<V, E> *v)
// 	{
// 		if(v != end[0])
// 			return end[0];
// 		return end[1];
// 	}
// private:
// 	WeightedGraphVertex<V, E> *end[2];
// };

// template<class V, class E>
// class WeightedGraph
// {
// public:
// 	WeightedGraph()
// 	{
// 		vertex = new LinkList<WeightedGraphVertex<V, E> *>();
// 		edge = new LinkList<WeightedGraphEdge<V, E> *>();
// 	}
// 	WeightedGraphVertex<V, E> *operator[](int n)
// 	{
// 		try
// 		{
// 			return (*vertex)[n].getData();
// 		}
// 		catch(std::invalid_argument e)
// 		{
// 			return NULL;
// 		}
// 	}
// 	void addLink(WeightedGraphVertex<V, E> *v1, WeightedGraphVertex<V, E> *v2, E w)
// 	{
// 		WeightedGraphEdge<V, E> *edge = new WeightedGraphEdge<V, E>(w, v1, v2);
// 		v1->addEdge(edge);
// 		if(v1 != v2)
// 			v2->addEdge(edge);
// 	}
// 	WeightedGraphVertex<V, E> *addVertex(V d)
// 	{
// 		WeightedGraphVertex<V, E> *v = new WeightedGraphVertex<V, E>(d);
// 		vertex->addFromTail(v);
// 		vertexCount ++;
// 		return v;
// 	}
// 	void adjList()
// 	{
// 		ListNode<WeightedGraphVertex<V, E> *> *cur = &(*vertex)[0];
// 		while(cur != NULL)
// 		{
// 			WeightedGraphVertex<V, E> *temp = cur->getData();
// 			std::cout<<temp<<": ";
// 			ListNode<WeightedGraphEdge<V, E> *> *e = (*temp)[0];
// 			while(e != NULL)
// 			{
// 				std::cout<<e->getData()->getAnotherEnd(temp)<<"("<<e->getData()<<") ";
// 				e = e->getNext();
// 			}
// 			std::cout<<std::endl;
// 			cur = cur->getNext();
// 		}
// 	}
// 	/*
//         return null if n is not a vertex in this graph
//         return the minimum spanning tree with v as root
// 	*/
// 	WeightedGraph *minimumSpanningTree(WeightedGraphVertex<V, E> *v)
// 	{

// 	}
// private:
// 	LinkList<WeightedGraphVertex<V, E> *> *vertex;
// 	LinkList<WeightedGraphEdge<V, E> *> *edge;
// 	int vertexCount, edgeCount;
// };

// int main()
// {
// 	WeightedGraph<char, int> *g = new WeightedGraph<char, int>();
// 	WeightedGraph<char, int> *tree;
// 	int j, k, i, l;
// 	srand(time(NULL));
// 	for(j = 0;j < 5;j++)
// 	{
// 		g->addVertex(j + 'a');
// 	}
// 	for(j = 0;j < 5;j ++)
//     {
//         k = rand() % 5;
//         i = rand() % 5;
//         l = rand() % 100;
//         g->addLink((*g)[k], (*g)[i], l);
//     }
// 	g->adjList();
// 	tree = g->minimumSpanningTree((*g)[0]);
// 	tree->adjList();
// 	return 0;
// }

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>

template <class T>
class Node
{
public:
    Node()
    {
        data = new T;
    }
    Node(T d)
    {
        data = new T;
        (*data) = d;
    }
    Node &operator=(T d)
    {
        (*data) = d;
        return *this;
    }
    friend std::ostream &operator<<(std::ostream &out, Node n)
    {
        out << *(n.data);
        return out;
    }
    // friend std::ostream &operator<<(std::ostream &out, Node *n)
    // {
    //     out << *(n->data);
    //     return out;
    // }
    void setData(T d)
    {
        *data = d;
    }
    T &getData() const
    {
        return *data;
    }

protected:
    T *data;
};

template <class T>
class ListNode : public Node<T>
{
public:
    ListNode() : Node<T>()
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(T d) : Node<T>(d)
    {
        prev = NULL;
        next = NULL;
    }
    ListNode(ListNode *p, ListNode *n) : Node<T>()
    {
        prev = p;
        next = n;
    }
    ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
    {
        prev = p;
        next = n;
    }
    ListNode *getNext() const
    {
        return next;
    }
    ListNode *getPrev() const
    {
        return prev;
    }
    void setNext(ListNode *n)
    {
        next = n;
    }
    void setPrev(ListNode *p)
    {
        prev = p;
    }
    ListNode &operator=(T d)
    {
        this->setData(d);
        return *this;
    }

private:
    ListNode *prev, *next;
};

template <class T>
class LinkList
{
protected:
    ListNode<T> *head, *tail;
    int length = 0;

public:
    LinkList() : head(NULL), tail(NULL), length(0) {}

    ListNode<T> &operator[](int i)
    {
        ListNode<T> *j = head;
        int k;
        for (k = 0; k < i && j != NULL; k++)
            j = j->getNext();
        if (j == NULL)
        {
            throw std::invalid_argument("index does not exist.");
        }
        return *j;
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
        ++length;
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
        ++length;
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
        ++length;
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
        --length;
        return n;
    }
    ListNode<T> *remove(T d)
    {
        ListNode<T> *res = head;
        while (res != nullptr && res->getData() != d)
        {
            res = res->getNext();
        }
        if (res == head)
            return removeFromHead();
        if (res == tail)
            return removeFromTail();
        res->getPrev()->setNext(res->getNext());
        res->getNext()->setPrev(res->getPrev());
        res->setNext(nullptr);
        res->setPrev(nullptr);
        --length;
        return res;
    }
    int get_length()
    {
        return length;
    }
    bool empty()
    {
        return length == 0;
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
    void print() const
    {
        ListNode<T> *j;
        j = head;
        while (j != NULL)
        {
            std::cout << *j->getData() << " ";
            j = j->getNext();
        }
        std::cout << std::endl;
    }
};

template <class V, class E>
class WeightedGraphEdge;
template <class V, class E>
class WeightedGraph;

template <class V, class E>
class WeightedGraphVertex : public Node<V>
{
private:
    LinkList<WeightedGraphEdge<V, E> *> *list;

public:
    WeightedGraphVertex() : Node<V>()
    {
        list = new LinkList<E>();
    }
    WeightedGraphVertex(V d) : Node<V>(d)
    {
        list = new LinkList<WeightedGraphEdge<V, E> *>();
    }
    void addEdge(WeightedGraphEdge<V, E> *edge)
    {
        list->addFromTail(edge);
    }
    void remove(WeightedGraphEdge<V, E> *node)
    {
    }
    ListNode<WeightedGraphEdge<V, E> *> *operator[](int n)
    {
        if (n >= list->get_length())
        {
            return nullptr;
        }
        try
        {
            // std::cout << "[]" << n << std::endl;
            return (&(*list)[n]);
        }
        catch (std::invalid_argument e)
        {
            // std::cout << "catch" << std::endl;
            return nullptr;
        }
    }
};

template <class V, class E>
class WeightedGraphEdge : public Node<E>
{
    friend class WeightedGraph<V, E>;

private:
    WeightedGraphVertex<V, E> *end[2];

public:
    WeightedGraphEdge() : Node<E>()
    {
        end[0] = NULL;
        end[1] = NULL;
    }
    WeightedGraphEdge(E d) : Node<E>(d)
    {
        end[0] = NULL;
        end[1] = NULL;
    }
    WeightedGraphEdge(E d, WeightedGraphVertex<V, E> *v1, WeightedGraphVertex<V, E> *v2) : Node<E>(d)
    {
        end[0] = v1;
        end[1] = v2;
    }
    WeightedGraphVertex<V, E> *&getAnotherEnd(WeightedGraphVertex<V, E> *v)
    {
        if (v != end[0])
            return end[0];
        return end[1];
    }
};

template <class V, class E>
class WeightedGraph
{
private:
    LinkList<WeightedGraphVertex<V, E> *> *vertex;
    LinkList<WeightedGraphEdge<V, E> *> *edge;
    int vertexCount = 0, edgeCount = 0;

public:
    WeightedGraph()
    {
        vertex = new LinkList<WeightedGraphVertex<V, E> *>();
        edge = new LinkList<WeightedGraphEdge<V, E> *>();
    }
    WeightedGraphVertex<V, E> *operator[](int n)
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

    void addLink(WeightedGraphVertex<V, E> *v1, WeightedGraphVertex<V, E> *v2, E w)
    {
        WeightedGraphEdge<V, E> *edge = new WeightedGraphEdge<V, E>(w, v1, v2);
        v1->addEdge(edge);
        if (v1 != v2)
            v2->addEdge(edge);
        ++edgeCount;
    }
    void addLink(V d1, V d2, E w)
    {
        WeightedGraphVertex<V, E> *v1 = get_vertex(d1);
        WeightedGraphVertex<V, E> *v2 = get_vertex(d2);
        // std::cout << d1 << " " << v1 << std::endl;
        // std::cout << d2 << " " << v2 << std::endl;
        WeightedGraphEdge<V, E> *edge = new WeightedGraphEdge<V, E>(w, v1, v2);
        v1->addEdge(edge);
        if (v1 != v2)
            v2->addEdge(edge);
        ++edgeCount;
    }
    WeightedGraphVertex<V, E> *addVertex(V d)
    {
        WeightedGraphVertex<V, E> *v = new WeightedGraphVertex<V, E>(d);
        // std::cout << d << " " << v << std::endl;
        vertex->addFromTail(v);
        ++vertexCount;
        return v;
    }

    WeightedGraphVertex<V, E> *get_vertex(V d)
    {
        for (int i = 0; i < vertexCount; ++i)
        {
            if ((*vertex)[i].getData()->getData() == d)
                return (*vertex)[i].getData();
        }
        return nullptr;
    }

    bool exist(V d)
    {
        for (int i = 0; i < vertexCount; ++i)
        {
            if ((*vertex)[i].getData()->getData() == d)
                return true;
        }
        return false;
    }

    void adjList()
    {
        ListNode<WeightedGraphVertex<V, E> *> *cur = &(*vertex)[0];
        while (cur != NULL)
        {
            WeightedGraphVertex<V, E> *temp = cur->getData();
            std::cout << *temp << ": ";
            ListNode<WeightedGraphEdge<V, E> *> *e = (*temp)[0];
            while (e != NULL)
            {
                std::cout << *(e->getData()->getAnotherEnd(temp)) << "(" << *(e->getData()) << ") ";
                e = e->getNext();
            }
            std::cout << std::endl;
            cur = cur->getNext();
        }
    }
    /*
        return null if n is not a vertex in this graph
        return the minimum spanning tree with v as root
	*/
    WeightedGraph *minimumSpanningTree(WeightedGraphVertex<V, E> *v)
    {
        if (!this->vertex->exist(v))
        {
            return nullptr;
        }
        WeightedGraph<V, E> *res = new WeightedGraph<V, E>();
        LinkList<WeightedGraphEdge<V, E> *> *stk_e = new LinkList<WeightedGraphEdge<V, E> *>();

        res->addVertex(v->getData());

        _add_edge(v, stk_e);

        while (!stk_e->empty())
        {

            WeightedGraphEdge<V, E> *cur_edge = find_min_edge(stk_e);
            // res->adjList();
            // std::cout << "min -> " << cur_edge->getData() << std::endl;
            // 邊的兩端皆在圖中，選了會有迴圈
            if (res->exist(cur_edge->end[0]->getData()) && res->exist(cur_edge->end[1]->getData()))
            {
                stk_e->remove(cur_edge);
            }
            else
            {
                if (res->exist(cur_edge->end[0]->getData()))
                {
                    res->addVertex(cur_edge->end[1]->getData());
                    _add_edge(cur_edge->end[1], stk_e);
                }
                else
                {
                    res->addVertex(cur_edge->end[0]->getData());
                    _add_edge(cur_edge->end[0], stk_e);
                }
                res->addLink(cur_edge->end[1]->getData(), cur_edge->end[0]->getData(), cur_edge->getData());
                stk_e->remove(cur_edge);
            }
        }
        return res;
    }
    void _add_edge(WeightedGraphVertex<V, E> *v, LinkList<WeightedGraphEdge<V, E> *> *stk)
    {
        // std::cout << "add edge" << std::endl;
        for (int i = 0; (*v)[i] != nullptr; ++i)
        {
            // std::cout << *(*v)[i]->getData() << " " << &(*v)[i]->getData() << std::endl;
            stk->addFromTail((*v)[i]->getData());
        }
        // std::cout << "add edge end" << std::endl;
        return;
    }
    WeightedGraphEdge<V, E> *find_min_edge(LinkList<WeightedGraphEdge<V, E> *> *stk)
    {
        // std::cout << "stk ->" << std::endl;
        // stk->print();
        // std::cout << "stk end" << std::endl;
        WeightedGraphEdge<V, E> *res = (*stk)[0].getData();
        for (int i = 1; i < stk->get_length(); ++i)
        {
            if ((*stk)[i].getData()->getData() < res->getData())
            {
                res = (*stk)[i].getData();
            }
        }
        return res;
    }
};

using namespace std;

int main()
{
    // WeightedGraph<char, int> *g = new WeightedGraph<char, int>();
    // WeightedGraph<char, int> *tree;
    // int j, k, i, l;
    // srand(time(NULL));

    // int test_size = 6;
    // int edge_num = test_size * 2;

    // for (j = 0; j < test_size; j++)
    // {
    //     g->addVertex(j + 'a');
    // }

    // // random test case
    // for (j = 0; j < edge_num; j++)
    // {
    //     k = rand() % test_size;
    //     i = rand() % test_size;
    //     l = rand() % 100;
    //     g->addLink((*g)[k], (*g)[i], l);
    // }

    // // test_case 1
    // // g->addLink((*g)[0], (*g)[1], 3);
    // // g->addLink((*g)[0], (*g)[2], 5);
    // // g->addLink((*g)[1], (*g)[4], 7);
    // // g->addLink((*g)[2], (*g)[3], 1);
    // // g->addLink((*g)[2], (*g)[4], 4);
    // // g->addLink((*g)[3], (*g)[4], 2);

    // g->adjList();
    // cout << endl;
    // tree = g->minimumSpanningTree((*g)[0]);
    // tree->adjList();
    return 0;
}
