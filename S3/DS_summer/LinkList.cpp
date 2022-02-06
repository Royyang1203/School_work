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
	friend std::ostream &operator<<(std::ostream &out, Node *n)
	{
		out << *(n->data);
		return out;
	}
	void setData(T d)
	{
		*data = d;
	}
	T &getData() const
	{
		return *data;
	}

private:
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
		n->setNext(nullptr);
		n->setPrev(nullptr);
		// remove n from list here
		// if (n->getNext() != nullptr)
		// 	n->getNext()->setPrev() = n->getPrev();
		// if (n->getPrev() != nullptr)
		// 	n->getPrev()->setNext() = n->getNext();
		// free n;
		// delete n;
		return n;
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

private:
	ListNode<T> *head, *tail;
};

template <class T>
class Queue : LinkList<T>
{
public:
	Queue() : LinkList<T>()
	{
	}
	void enqueue(T d)
	{
		this->addFromTail(d);
	}
	ListNode<T> *dequeue()
	{
		return this->removeFromHead();
	}

private:
};

template <class T>
class Stack : LinkList<T>
{
public:
	Stack() : LinkList<T>()
	{
	}
	void push(T d)
	{
		this->addFromTail(d);
	}
	ListNode<T> *pop()
	{
		return this->removeFromTail();
	}

private:
};

// int main()
// {
// 	Queue<int> *q = new Queue<int>();
// 	ListNode<int>
// 		srand(time(nullptr));
// 	int j, k;

// 	return 0;
// }
