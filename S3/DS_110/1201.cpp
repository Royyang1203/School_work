// Description

// Please finish the class define in template.

// 請完成樣板中的類別。

// #include <cstdlib>
// #include <iostream>
// #include <stdexcept>
// #include <ctime>

// template <class T>
// class Node
// {
// public:
//     Node()
//     {
//         data = new T;
//     }
//     Node(T d)
//     {
//         data = new T;
//         (*data) = d;
//     }
//     Node &operator=(T d)
//     {
//         (*data) = d;
//         return *this;
//     }
//     friend std::ostream &operator<<(std::ostream &out, Node n)
//     {
//         out << *(n.data);
//         return out;
//     }
//     friend std::ostream &operator<<(std::ostream &out, Node *n)
//     {
//         out << *(n->data);
//         return out;
//     }
//     void setData(T d)
//     {
//         *data = d;
//     }
//     T &getData() const
//     {
//         return *data;
//     }

// protected:
//     T *data;
// };

// template <class T>
// class ListNode : public Node<T>
// {
// public:
//     ListNode() : Node<T>()
//     {
//         prev = NULL;
//         next = NULL;
//     }
//     ListNode(T d) : Node<T>(d)
//     {
//         prev = NULL;
//         next = NULL;
//     }
//     ListNode(ListNode *p, ListNode *n) : Node<T>()
//     {
//         prev = p;
//         next = n;
//     }
//     ListNode(T d, ListNode *p, ListNode *n) : Node<T>(d)
//     {
//         prev = p;
//         next = n;
//     }
//     ListNode *getNext() const
//     {
//         return next;
//     }
//     ListNode *getPrev() const
//     {
//         return prev;
//     }
//     void setNext(ListNode *n)
//     {
//         next = n;
//     }
//     void setPrev(ListNode *p)
//     {
//         prev = p;
//     }
//     ListNode &operator=(T d)
//     {
//         this->setData(d);
//         return *this;
//     }

// private:
//     ListNode *prev, *next;
// };

// template <class T>
// class LinkList
// {
// public:
//     LinkList()
//     {
//         head = NULL;
//         tail = NULL;
//     }
//     void addFromHead(T d)
//     {
//         ListNode<T> *node = new ListNode<T>(d);
//         if (head != NULL)
//         {
//             head->setPrev(node);
//         }
//         node->setNext(head);
//         head = node;
//         if (tail == NULL)
//             tail = node;
//     }
//     void addFromTail(T d)
//     {
//         ListNode<T> *node = new ListNode<T>(d);
//         if (tail != NULL)
//         {
//             tail->setNext(node);
//         }
//         node->setPrev(tail);
//         tail = node;
//         if (head == NULL)
//             head = node;
//     }
//     void addAfter(ListNode<T> *at, T d)
//     {
//         if (!exist(at))
//             return;
//         ListNode<T> *node = new ListNode<T>(d);
//         if (at->getNext() != NULL)
//             at->getNext()->setPrev(node);
//         node->setNext(at->getNext());
//         at->setNext(node);
//         node->setPrev(at);
//         if (node->getNext() == NULL)
//             tail = node;
//     }
//     ListNode<T> *removeFromHead()
//     {
//         ListNode<T> *n = head;
//         if (head != NULL)
//         {
//             head = head->getNext();
//             if (head != NULL)
//                 head->setPrev(NULL);
//             else
//                 tail = NULL;
//             n->setNext(NULL);
//         }
//         return n;
//     }
//     ListNode<T> *removeFromTail()
//     {
//         ListNode<T> *n = tail;
//         if (tail != NULL)
//         {
//             tail = tail->getPrev();
//             if (tail != NULL)
//                 tail->setNext(NULL);
//             else
//                 head = NULL;
//             n->setPrev(NULL);
//         }
//         return n;
//     }
//     ListNode<T> *remove(ListNode<T> *n)
//     {
//         if (!exist(n))
//             return NULL;
//         if (n == head)
//             return removeFromHead();
//         if (n == tail)
//             return removeFromTail();
//         n->getPrev()->setNext(n->getNext());
//         n->getNext()->setPrev(n->getPrev());
//         n->setNext(NULL);
//         n->setPrev(NULL);
//         return n;
//     }
//     ListNode<T> *exist(T d)
//     {
//         ListNode<T> *j = head;
//         while (j != NULL)
//         {
//             if (j->getData() == d)
//                 return j;
//             j = j->getNext();
//         }
//         return NULL;
//     }
//     bool exist(ListNode<T> *n)
//     {
//         ListNode<T> *j = head;
//         while (j != NULL)
//         {
//             if (j == n)
//                 return true;
//             j = j->getNext();
//         }
//         return false;
//     }
//     ListNode<T> &operator[](int i)
//     {
//         ListNode<T> *j = head;
//         int k;
//         for (k = 0; k < i && j != NULL; k++)
//             j = j->getNext();
//         if (j == NULL)
//             throw std::invalid_argument("index does not exist.");
//         return *j;
//     }
//     void print() const
//     {
//         ListNode<T> *j;
//         j = head;
//         while (j != NULL)
//         {
//             std::cout << (*j) << " ";
//             j = j->getNext();
//         }
//         std::cout << std::endl;
//     }

// protected:
//     ListNode<T> *head, *tail;
// };

// /*
// 	Please finish the TreeNode class, TreeNode class respresent a node in a general tree.
// 	A general tree is different from binary tree, every node in binary tree have at most two child node, but a node in general tree may have more than two child node.
// */
// template <class T>
// class TreeNode : public Node<T>
// {
// public:
//     TreeNode() : Node<T>()
//     {
//     }
//     TreeNode(T d) : Node<T>(d)
//     {
//     }
//     /*
// 		Add a child to this node.
// 	*/
//     void addChild(TreeNode *n)
//     {
//     }
//     /*
// 		Add a child to this node.
// 	*/
//     void addChild(T d)
//     {
//     }
//     /*
// 		Return the nth child of the node.
// 	*/
//     TreeNode *operator[](int n)
//     {
//     }

// private:
//     LinkList<TreeNode<T> *> *chile;
// };

// /*
// 	Please finish the Tree class. Tree class respresent a general tree, that means node on this tree may have more than two child node.

// */
// template <class T>
// class Tree
// {
// public:
//     Tree()
//     {
//     }
//     /*
// 		return the nth node on this tree with level order.
// 	*/
//     TreeNode<T> *operator[](int n)
//     {
//     }
//     /*
// 		return the number of nodes on this tree.
// 	*/
//     int count()
//     {
//     }
//     /*
// 		print all the node on this tree with level order.
// 	*/
//     void levelOrder()
//     {
//     }
//     /*
// 		print all the node on this tree with preorder.
// 	*/
//     void preorder()
//     {
//     }
//     /*
// 		print all the node on this tree with postorder.
// 	*/
//     void postorder()
//     {
//     }
//     /*
// 		set the root of this tree.
// 	*/
//     void setRoot(T d)
//     {
//     }

// private:
//     TreeNode<T> *root;
// };

// int main()
// {
//     Tree<int> *tree = new Tree<int>();
//     srand(0);
//     int j, k, i;
//     for (j = 0; j < 20; j++)
//     {
//         if (tree->count() == 0)
//             tree->setRoot(rand() % 100);
//         else
//         {
//             k = rand() % tree->count();
//             (*tree)[k]->addChild(rand() % 100);
//         }
//     }
//     tree->levelOrder();
//     tree->preorder();
//     tree->postorder();
// }
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include <queue>

template <class T>
class Node
{
public:
    Node()
    {
        data = new T();
    }
    Node(const T &d)
    {
        data = new T();
        (*data) = d;
    }
    Node &operator=(const T &d)
    {
        (*data) = d;
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

    friend std::ostream &operator<<(std::ostream &out, const Node &n)
    {
        out << *(n.data);
        return out;
    }
    friend std::ostream &operator<<(std::ostream &out, Node *n)
    {
        out << *(n->data);
        return out;
    }

protected:
    T *data;
};

template <class T>
class ListNode : public Node<T>
{
public:
    ListNode() : Node<T>() {}
    ListNode(const T &d) : Node<T>(d) {}
    ListNode(ListNode *p, ListNode *n) : Node<T>(), prev(p), next(n) {}
    ListNode(const T &d, ListNode *p, ListNode *n) : Node<T>(d), prev(p), next(n) {}

    ListNode &operator=(const T &d)
    {
        this->setData(d);
        return *this;
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

private:
    ListNode *prev = nullptr, *next = nullptr;
};

template <class T>
class LinkList
{
public:
    LinkList() = default;

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

    void addFromHead(const T &d)
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
    void addFromTail(const T &d)
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
    void addAfter(ListNode<T> *at, const T &d)
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

    int size()
    {
        if (head == nullptr)
            return 0;
        int n = 1;
        for (ListNode<T> *cur = head; cur != tail; cur = cur->getNext())
        {
            ++n;
        }
        return n;
    }

protected:
    ListNode<T> *head = nullptr, *tail = nullptr;
};

/**
 * @brief Please finish the TreeNode class,
 * TreeNode class respresent a node in a general tree.
 * A general tree is different from binary tree,
 * every node in binary tree have at most two child node,
 * but a node in general tree may have more than two child node.
 * @tparam T
 */
template <class T>
class TreeNode : public Node<T>
{
private:
    LinkList<TreeNode<T> *> *child;

public:
    TreeNode() : Node<T>()
    {
        child = new LinkList<TreeNode<T> *>();
    }
    TreeNode(const T &d) : Node<T>(d)
    {
        child = new LinkList<TreeNode<T> *>();
    }

    /**
     * @brief Return the nth child of the node.
     *
     * @param n
     * @return TreeNode*
     */
    TreeNode<T> *operator[](int n)
    {
        // std::cout << "tree node operator " << n << std::endl;
        return ((*child)[n]).getData();
    }

    /**
     * @brief Add a child to this node.
     *
     * @param n
     */
    void addChild(TreeNode *n)
    {
        child->addFromTail(n);
    }

    /**
     * @brief Add a child to this node.
     *
     * @param d
     */
    void addChild(const T &d)
    {
        addChild(new TreeNode<T>(d));
    }

    int size()
    {
        // std::cout << "tree node size -> " << child->size() << std::endl;
        return child->size();
    }
};

/*
	Please finish the Tree class.
    Tree class respresent a general tree,
    that means node on this tree may have more than two child node.

*/
template <class T>
class Tree
{
private:
    TreeNode<T> *root = nullptr;

public:
    Tree() = default;

    /**
     * @brief return the nth node on this tree with level order.
     *
     * @param n
     * @return TreeNode<T>*
     */
    TreeNode<T> *operator[](int k)
    {
        if (root == nullptr)
            return nullptr;
        std::queue<TreeNode<T> *> q;
        q.push(this->root);
        int n = 0;
        while (!q.empty())
        {
            TreeNode<T> *cur = q.front();
            q.pop();
            if (n++ == k)
                return cur;
            for (int i = 0; i < cur->size(); ++i)
            {
                q.push((*cur)[i]);
            }
        }
        return nullptr;
    }

    /**
     * @brief Get the Root node
     *
     * @return TreeNode<T>*
     */
    TreeNode<T> *getRoot() const
    {
        return root;
    }

    /**
     * @brief set the root of this tree.
     *
     * @param d
     */
    void setRoot(const T &d)
    {
        root = new TreeNode<T>(d);
    }

    /**
     * @brief return the number of nodes on this tree.
     *
     * @return int
     */
    int count()
    {
        if (root == nullptr)
            return 0;

        std::queue<TreeNode<T> *> q;
        q.push(this->root);
        int n = 0;

        while (!q.empty())
        {
            TreeNode<T> *cur = q.front();
            q.pop();
            ++n;
            // std::cout << "in count node size -> " << cur->size() << std::endl;
            for (int i = 0; i < cur->size(); ++i)
            {
                try
                {
                    q.push((*cur)[i]);
                }
                catch (const std::exception &e)
                {
                    std::cerr << e.what() << '\n';
                }
            }
        }
        return n;
    }

    /**
     * @brief print all the node on this tree with level order.
     *
     */
    void levelOrder()
    {
        std::queue<TreeNode<T> *> q;
        q.push(this->root);

        while (!q.empty())
        {
            TreeNode<T> *cur = q.front();
            q.pop();
            std::cout << cur << " ";
            for (int i = 0; i < cur->size(); ++i)
            {
                q.push((*cur)[i]);
            }
        }
    }

    /**
     * @brief print all the node on this tree with preorder.
     *
     */
    void preorder()
    {
        _preorder(root);
    }

    /**
     * @brief print all the node on this tree with postorder.
     *
     */
    void postorder()
    {
        _postorder(root);
    }

private:
    void _preorder(TreeNode<T> *cur)
    {
        std::cout << cur << " ";
        for (int i = 0; i < cur->size(); ++i)
        {
            _preorder((*cur)[i]);
        }
    }
    void _postorder(TreeNode<T> *cur)
    {
        for (int i = 0; i < cur->size(); ++i)
        {
            _postorder((*cur)[i]);
        }
        std::cout << cur << " ";
    }
};

using namespace std;
int main()
{
    Tree<int> *tree = new Tree<int>();
    srand(0);
    int j, k, i;
    for (j = 0; j < 20; j++)
    {
        // cout << "main j -> " << j << endl;
        // cout << "tree count -> " << tree->count() << endl;
        if (tree->count() == 0)
            tree->setRoot(rand() % 100);
        else
        {
            k = rand() % tree->count();
            std::cout << k << ", " << (*tree)[k] << ", " << j << std::endl;
            (*tree)[k]->addChild(rand() % 100);
        }
    }

    tree->levelOrder();
    cout << endl;
    tree->preorder();
    cout << endl;
    tree->postorder();
    cout << endl;
}
