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

protected:
    T *data;
};

template <class T>
class TreeNode : public Node<T>
{
public:
    TreeNode() : Node<T>()
    {
        left = NULL;
        right = NULL;
    }
    TreeNode(T d) : Node<T>(d)
    {
        left = NULL;
        right = NULL;
    }
    TreeNode(TreeNode<T> *l, TreeNode<T> *r) : Node<T>()
    {
        left = l;
        right = r;
    }
    TreeNode(T d, TreeNode<T> *l, TreeNode<T> *r) : Node<T>(d)
    {
        left = l;
        right = r;
    }
    void setLeft(TreeNode<T> *l)
    {
        left = l;
    }
    void setRight(TreeNode<T> *r)
    {
        right = r;
    }
    TreeNode *&getLeft()
    {
        return left;
    }
    TreeNode *&getRight()
    {
        return right;
    }
    bool operator>(TreeNode<T> n)
    {
        if (*(this->data) > *(n.data))
            return true;
        return false;
    }
    bool operator==(TreeNode<T> n)
    {
        if (*(this->data) == *(n.data))
            return true;
        return false;
    }

private:
    TreeNode<T> *left, *right;
};

template <class T>
class BinaryTree
{
public:
    BinaryTree()
    {
        root = NULL;
        count = 0;
    }
    virtual TreeNode<T> *insert(T d)
    {
        TreeNode<T> *node = new TreeNode<T>(d);
        if (root == NULL)
        {
            root = node;
        }
        else
        {
            int j = count + 1;
            int k = 1;
            TreeNode<T> *cur = root;
            while (k <= j)
                k = k << 1;
            k = k >> 2;
            while (k > 1)
            {
                if (k & j)
                    cur = cur->getRight();
                else
                    cur = cur->getLeft();
                k = k >> 1;
            }
            if (k & j)
                cur->setRight(node);
            else
                cur->setLeft(node);
        }
        count++;
    }
    TreeNode<T> *remove(TreeNode<T> *n)
    {
        if (!exist(n))
            return NULL;
        TreeNode<T> *last = getLast();
        if (last == root)
        {
            count--;
            root = NULL;
            return n;
        }
        TreeNode<T> *lastsFather = getFather(last);
        if (lastsFather->getLeft() == last)
            lastsFather->setLeft(NULL);
        else
            lastsFather->setRight(NULL);
        if (last == n)
        {
            count--;
            return n;
        }
        if (n != root)
        {
            TreeNode<T> *father = getFather(n);
            if (father->getLeft() == n)
                father->setLeft(last);
            else
                father->setRight(last);
        }
        else
        {
            root = last;
        }
        last->setLeft(n->getLeft());
        last->setRight(n->getRight());
        n->setLeft(NULL);
        n->setRight(NULL);
        count--;
        return n;
    }
    TreeNode<T> *getFather(TreeNode<T> *n)
    {
        if (n == root || !exist(n))
            return NULL;
        return _getFather(root, n);
    }
    bool exist(TreeNode<T> *n)
    {
        return _exist(root, n);
    }
    TreeNode<T> *getRoot()
    {
        return root;
    }
    void print()
    {
        _print(root, 0);
    }
    void swapNode(TreeNode<T> *node1, TreeNode<T> *node2)
    {
        if (!exist(node1) || !exist(node2))
            return;
        TreeNode<T> *father1 = getFather(node1);
        TreeNode<T> *father2 = getFather(node2);
        if (father1 != NULL)
            if (father1->getLeft() == node1)
                father1->setLeft(node2);
            else
                father1->setRight(node2);
        else
            root = node2;
        if (father2 != NULL)
            if (father2->getLeft() == node2)
                father2->setLeft(node1);
            else
                father2->setRight(node1);
        else
            root = node1;
        TreeNode<T> *node1L = node1->getLeft();
        TreeNode<T> *node1R = node1->getRight();
        TreeNode<T> *node2L = node2->getLeft();
        TreeNode<T> *node2R = node2->getRight();
        node1->setLeft(node2L);
        node1->setRight(node2R);
        node2->setLeft(node1L);
        node2->setRight(node1R);
    }

protected:
    TreeNode<T> *root;
    int count;

private:
    TreeNode<T> *getLast()
    {
        int j = count, k = 1;
        TreeNode<T> *cur = root;
        while (k <= j)
            k = k << 1;
        k = k >> 2;
        while (k > 0)
        {
            if (k & j)
                cur = cur->getRight();
            else
                cur = cur->getLeft();
            k = k >> 1;
        }
        return cur;
    }
    bool _exist(TreeNode<T> *r, TreeNode<T> *n)
    {
        if (n == r)
            return true;
        if (r->getLeft() && _exist(r->getLeft(), n))
            return true;
        if (r->getRight() && _exist(r->getRight(), n))
            return true;
        return false;
    }
    TreeNode<T> *_getFather(TreeNode<T> *r, TreeNode<T> *n)
    {
        if (r == NULL)
            return NULL;
        if (r->getLeft() == n || r->getRight() == n)
            return r;
        TreeNode<T> *temp;
        temp = _getFather(r->getLeft(), n);
        if (temp != NULL)
            return temp;
        temp = _getFather(r->getRight(), n);
        return temp;
    }
    void _print(TreeNode<T> *r, int n)
    {
        if (r == NULL)
            return;
        int j;
        _print(r->getRight(), n + 1);
        for (j = 0; j < n; j++)
            std::cout << "    ";
        std::cout << r << std::endl;
        _print(r->getLeft(), n + 1);
    }
};