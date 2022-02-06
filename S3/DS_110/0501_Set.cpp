// Description

// 請完成 addElement，unions，intersection，equivalent 這四個函數

// addElement 會在集合中增加一個整數的元素，成功的時候回傳真，失敗的時候回傳假。

// unions 會將 兩個集合做聯集的運算，然後將結果回傳。

// intersection 會將 兩個集合做交集的運算，然後將結果回傳。

// equivalent 會判斷兩個集合是否相等，如果相等就回傳真，不相等就回傳假。

// 這題的期限到 2021/10/28。

// Please finish four function addElement, unions, intersection and equivalent.

// Function addElement will add an element to the set, return true on success and false on not.

// Function unions union two set and return the result.

// Function intersection intersect two set and return the result.

// Function equivalent return true if two set have the same element, return false if not.

// This question due to 2021/10/28

// #include<iostream>
// #include<cstdlib>

// using namespace std;

// struct Node
// {
// 	Node()
// 	{
// 		data = 0;
// 		next = NULL;
// 	}
// 	int data;
// 	Node *next;
// };

// class Set
// {d
// public:
// 	Set()
// 	{
// 	}

// 	int addElement(int e)
// 	{
// 	}

// 	Set *unions(const Set *b) const
// 	{
// 	}

// 	Set *intersections(const Set *b) const
// 	{
// 	}

// 	bool equivalent(const Set *b) const
// 	{
// 	}

// 	void listAll() const
// 	{
// 		Node *cur = element;
// 		while(cur != NULL)
// 		{
// 			cout<<cur->data<<" ";
// 			cur = cur->next;
// 		}
// 	}
// private:
// 	Node *element;
// };

// int main()
// {
// 	Set *a = new Set();
// 	Set *b = new Set();
// 	Set *c;
// 	Node *cur;

// 	a->addElement(1);
// 	a->addElement(2);
// 	a->addElement(3);
// 	b->addElement(3);
// 	b->addElement(4);
// 	b->addElement(5);
// 	b->addElement(5);

// 	c = a->unions(b);
// 	c->listAll();

// 	c = a->intersetcions(b);
// 	c->listAll();

// 	if(a->equivalent(b) == 0)
// 		cout<<"Not equivalent.\n";
// 	else
// 		cout<<"Equivalent!\n";
// }

#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
    Node() = default;
    Node(int _data, Node *_next = nullptr) : data(_data), next(_next) {}
    int data = 0;
    Node *next = nullptr;
};

class Set
{
public:
    Set() = default;
    Set(const Set *that) : count(that->count)
    {
        Node *cur = that->element;
        while (cur != nullptr)
        {

            this->addElement(cur->data);
            cur = cur->next;
        }
    }
    Set(Set *that) : count(that->count)
    {
        Node *cur = that->element;
        while (cur != nullptr)
        {
            this->addElement(cur->data);
            cur = cur->next;
        }
    }

    bool addElement(const int e)
    {
        Node *cur = element;
        while (cur != nullptr)
        {

            if (cur->data == e)
                return false;
            cur = cur->next;
        }
        try
        {
            Node *ptr = new Node(e, element);
            element = ptr;
            ++count;
        }
        catch (const std::exception &err)
        {
            std::cerr << err.what() << '\n';
            return false;
        }
        return true;
    }

    Set *unions(const Set *that) const
    {
        Set *temp = new Set(this);

        for (Node *cur = that->element; cur != nullptr; cur = cur->next)
        {
            temp->addElement(cur->data);
        }
        temp->set_count();
        return temp;
    }

    Set *intersections(const Set *that) const
    {
        Set *reg = new Set();
        Set *copy_this = new Set(this);
        Set *copy_that = new Set(that);

        for (Node *cur = that->element; cur != nullptr; cur = cur->next)
        {
            if (!copy_this->addElement(cur->data))
            {
                reg->addElement(cur->data);
            }
        }
        reg->set_count();
        return reg;
        // Set *temp = new Set();

        // for (Node *cur = this->element; cur != nullptr; cur = cur->next)
        // {
        //     bool b = 0;

        //     while (!b && ptr != nullptr)
        //     {
        //         if (cur->data == ptr->data)
        //             b = true;
        //         ptr = ptr->next;
        //     }
        //     if (b)
        //     {
        //         temp->addElement(cur->data);
        //     }
        // }
        // return temp;
    }

    bool equivalent(const Set *that) const
    {
        if (this->count != that->count)
            return false;
        Set *temp = new Set(this);
        return temp->intersections(that)->count == this->count;
        // Node *cur = this->element;
        // while (cur != nullptr)
        // {
        //     bool b = 1;
        //     Node *ptr = that->element;
        //     while (b && ptr != nullptr)
        //     {
        //         if (cur == ptr)
        //             b = false;
        //         ptr = ptr->next;
        //     }
        //     if (b)
        //         return false;
        //     cur = cur->next;
        // }
        // return true;
    }

    int set_count()
    {
        this->count = 0;
        for (Node *cur = element; cur != nullptr; cur = cur->next)
        {
            ++count;
        }
        return this->count;
    }

    void listAll() const
    {
        Node *cur = element;
        while (cur != NULL)
        {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

private:
    Node *element = nullptr;
    int count = 0;
};

int main()
{
    Set *a = new Set();
    Set *b = new Set();
    Set *c;
    Node *cur;

    a->addElement(1);
    a->addElement(2);
    a->addElement(3);
    b->addElement(3);
    b->addElement(4);
    b->addElement(5);
    b->addElement(5);

    // a->listAll();
    // cout << endl;
    // b->listAll();
    // cout << endl;
    c = a->unions(b);
    c->listAll();
    cout << endl;
    c = a->intersections(b);
    c->listAll();
    cout << endl;
    cout << c->set_count() << endl;

    if (a->equivalent(b) == 0)
        cout << "Not equivalent.\n";
    else
        cout << "Equivalent!\n";
}
