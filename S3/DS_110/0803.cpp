// Description

// 請完成樣板中的 inorder, preorder, postorder 以及 levelorder 四個函數

// Please finish four function in the template, inorder, preorder, postorder and levelorder.

// 請務必在 2021/12/02 前上傳你的程式碼並且找 TA demo 完。

// The submission and demonstration due to 2021/12/02.

// #include <iostream>
// #include <cstdlib>
// #include <ctime>

// using namespace std;

// class Tree
// {
// public:
//     Tree()
//     {
//         int j;
//         for (j = 0; j < 2000; j++)
//             root[j] = -1;
//     }
//     int insert(int node)
//     {
//         int index = 0;
//         while (index < 2000 && root[index] != -1)
//         {
//             if (root[index] < node)
//                 index = index * 2 + 2;
//             else
//                 index = index * 2 + 1;
//         }
//         root[index] = node;
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
//     int root[2000];
// };

// int main()
// {
//     Tree *tree = new Tree();
//     int j, node;
//     srand(time(NULL));
//     for (j = 0; j < 10; j++)
//     {
//         node = rand();
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

class Tree
{
public:
    Tree()
    {
        int j;
        for (j = 0; j < 2000; j++)
            root[j] = -1;
    }
    int insert(int node)
    {
        int index = 0;
        while (index < 2000 && root[index] != -1)
        {
            if (root[index] < node) // right
                index = index * 2 + 2;
            else // left
                index = index * 2 + 1;
        }
        root[index] = node;
        return 1;
    }
    void inorder() const
    {
        _inorder(0);
    }
    void preorder() const
    {
        _preorder(0);
    }
    void postorder() const
    {
        _postorder(0);
    }
    void levelorder()
    {
        std::queue<int> q;
        q.push(0);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            std::cout << root[cur] << " ";
            if (root[cur * 2 + 1] != -1)
                q.push(cur * 2 + 1);
            if (root[cur * 2 + 2] != -1)
                q.push(cur * 2 + 2);
        }
    }

private:
    int root[2000];
    void _inorder(int cur) const
    {
        if (root[cur] != -1 && cur < 2000)
        {
            _inorder(cur * 2 + 1);
            std::cout << root[cur] << " ";
            _inorder(cur * 2 + 2);
        }
    }
    void _preorder(int cur) const
    {
        if (root[cur] != -1 && cur < 2000)
        {
            std::cout << root[cur] << " ";
            _preorder(cur * 2 + 1);
            _preorder(cur * 2 + 2);
        }
    }
    void _postorder(int cur) const
    {
        if (root[cur] != -1 && cur < 2000)
        {
            _postorder(cur * 2 + 1);
            _postorder(cur * 2 + 2);
            std::cout << root[cur] << " ";
        }
    }
};

int main()
{
    Tree *tree = new Tree();
    int j, node;
    srand(time(NULL));

    // int arr[10] = {1, 6, 3, 5, 4, 9, 8, 7, 2, 0};
    for (j = 0; j < 10; j++)
    {
        // node = arr[j];
        node = rand();
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
