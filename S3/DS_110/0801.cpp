// Description

// 請完成樣板中的 inorder, preorder, postorder 以及 levelorder 四個函數

// Please finish four function in the template, inorder, preorder, postorder and levelorder.

// 請務必在 2021/12/02 前上傳你的程式碼並且找 TA demo 完。

// The submission and demonstration due to 2021/12/02.

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// class Node
// {
// public:
//     int level, data;
//     Node *left, *right;
// };

// class Tree
// {
// public:
//     Tree()
//     {
//         root = NULL;
//     }
//     int insert(Node *n)
//     {
//         insert(&root, n);
//     }
//     void inorder()
//     {
//     }
//     void preorder()
//     {
//     }
//     void postorder()
//     {
//     }
//     void levelorder()
//     {
//     }

// private:
//     Node *root;
//     void insert(struct Node **r, struct Node *n)
//     {
//         if (*r == NULL)
//             *r = n;
//         else if (n->data > (*r)->data)
//             insert(&((*r)->right), n);
//         else
//             insert(&((*r)->left), n);
//     }
// };

// int main()
// {
//     Tree *tree = new Tree();
//     Node *node;
//     int j;
//     srand(time(NULL));
//     for (j = 0; j < 10; j++)
//     {
//         node = new Node();
//         node->data = rand();
//         node->left = NULL;
//         node->right = NULL;
//         tree->insert(node);
//     }
//     tree->inorder();
//     printf("\n");
//     tree->preorder();
//     printf("\n");
//     tree->postorder();
//     printf("\n");
//     tree->levelorder();
//     printf("\n");
// }

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

class Node
{
public:
    int level, data;
    Node *left, *right;
    friend std::ostream &operator<<(std::ostream &os, const Node *that);
};
std::ostream &operator<<(std::ostream &os, const Node *that)
{
    os << that->data;
    return os;
}

class Tree
{
public:
    Tree()
    {
        root = NULL;
    }
    int insert(Node *n)
    {
        insert(&root, n);
        return 1;
    }
    void inorder() const
    {
        _inorder(root);
    }
    void preorder() const
    {
        _preorder(root);
    }
    void postorder() const
    {
        _postorder(root);
    }
    void levelorder() const
    {
        std::queue<Node *> q;
        q.push(this->root);

        while (!q.empty())
        {
            Node *cur = q.front();
            q.pop();
            std::cout << cur << " ";
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

private:
    Node *root;
    void insert(struct Node **r, struct Node *n)
    {
        if (*r == NULL)
            *r = n;
        else if (n->data > (*r)->data)
            insert(&((*r)->right), n);
        else
            insert(&((*r)->left), n);
    }
    void _inorder(Node *cur) const
    {
        if (cur)
        {
            _inorder(cur->left);
            std::cout << cur << " ";
            _inorder(cur->right);
        }
    }
    void _preorder(Node *cur) const
    {
        if (cur)
        {
            std::cout << cur << " ";
            _preorder(cur->left);
            _preorder(cur->right);
        }
    }
    void _postorder(Node *cur) const
    {
        if (cur)
        {
            _postorder(cur->left);
            _postorder(cur->right);
            std::cout << cur << " ";
        }
    }
};

int main()
{
    Tree *tree = new Tree();
    Node *node;
    int j;
    srand(time(NULL));

    // int arr[10] = {1, 6, 3, 5, 4, 9, 8, 7, 2, 0};
    for (j = 0; j < 10; j++)
    {
        node = new Node();
        // node->data = arr[j];
        node->data = rand();
        node->left = NULL;
        node->right = NULL;
        tree->insert(node);
    }
    tree->inorder();
    printf("\n");
    tree->preorder();
    printf("\n");
    tree->postorder();
    printf("\n");
    tree->levelorder();
    printf("\n");
}
