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
//         int j, k;
//         for (j = 0; j < 20; j++)
//             for (k = 0; k < 4; k++)
//                 root[j][k] = -1;
//     }
//     int insert(int node)
//     {
//         int f = 0, index = 0;
//         while (root[index][0] != -1)
//             index++;
//         if (index >= 20)
//             return -1;
//         if (index == 0)
//         {
//             root[0][0] = 1;
//             root[0][1] = node;
//             return 1;
//         }
//         else
//         {
//             root[index][0] = 1;
//             root[index][1] = node;
//             while (1)
//             {
//                 if (root[f][1] < node)
//                 {
//                     if (root[f][3] == -1)
//                     {
//                         root[f][3] = index;
//                         return 1;
//                     }
//                     else
//                     {
//                         f = root[f][3];
//                     }
//                 }
//                 else
//                 {
//                     if (root[f][2] == -1)
//                     {
//                         root[f][2] = index;
//                         return 1;
//                     }
//                     else
//                     {
//                         f = root[f][2];
//                     }
//                 }
//             }
//         }
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
//     int root[20][4];
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
        int j, k;
        for (j = 0; j < 20; j++)
            for (k = 0; k < 4; k++)
                root[j][k] = -1;
    }
    int insert(int node)
    {
        int f = 0, index = 0;
        while (root[index][0] != -1)
            index++;
        if (index >= 20)
            return -1;
        if (index == 0)
        {
            root[0][0] = 1;
            root[0][1] = node;
            return 1;
        }
        else
        {
            root[index][0] = 1;
            root[index][1] = node;
            while (1)
            {
                if (root[f][1] < node) // right
                {
                    if (root[f][3] == -1)
                    {
                        root[f][3] = index;
                        return 1;
                    }
                    else
                    {
                        f = root[f][3];
                    }
                }
                else // left
                {
                    if (root[f][2] == -1)
                    {
                        root[f][2] = index;
                        return 1;
                    }
                    else
                    {
                        f = root[f][2];
                    }
                }
            }
        }
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
            std::cout << root[cur][1] << " ";
            if (root[root[cur][2]][0] == 1)
                q.push(root[cur][2]);
            if (root[root[cur][3]][0] == 1)
                q.push(root[cur][3]);
        }
    }

private:
    int root[20][4]; // 0, 是否有資料, 1, 資料值, 2, 左節點, 3, 右節點
    void _inorder(int cur) const
    {
        if (root[cur][0] == 1 && cur < 20)
        {
            _inorder(root[cur][2]);
            std::cout << root[cur][1] << " ";
            _inorder(root[cur][3]);
        }
    }
    void _preorder(int cur) const
    {
        if (root[cur][0] == 1 && cur < 20)
        {
            std::cout << root[cur][1] << " ";
            _preorder(root[cur][2]);
            _preorder(root[cur][3]);
        }
    }
    void _postorder(int cur) const
    {
        if (root[cur][0] == 1 && cur < 20)
        {
            _postorder(root[cur][2]);
            _postorder(root[cur][3]);
            std::cout << root[cur][1] << " ";
        }
    }
};

int main()
{
    Tree *tree = new Tree();
    int j, node;
    srand(time(NULL));

    int arr[10] = {1, 6, 3, 5, 4, 9, 8, 7, 2, 0};
    for (j = 0; j < 10; j++)
    {
        node = arr[j];
        // node = rand();
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
