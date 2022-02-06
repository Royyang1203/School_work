// 請完成樣板中的 inorder, preorder, postorder 以及 levelorder 四個函數

// Please finish four function in the template, inorder, preorder, postorder and levelorder.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insert(int root[20][4], int node)
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
            if (root[f][1] < node)
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
            else
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

void inorder(int root[20][4])
{
}

void preorder(int root[20][4])
{
}

void postorder(int root[20][4])
{
}

void levelorder(int root[20][4])
{
}

int main()
{
    int tree[20][4];
    int j, k, node;
    srand(time(NULL));

    for (j = 0; j < 20; j++)
        for (k = 0; k < 4; k++)
            tree[j][k] = -1;

    for (j = 0; j < 10; j++)
    {
        node = rand() % 100;
        insert(tree, node);
    }
    inorder(tree);
    printf("\n");
    preorder(tree);
    printf("\n");
    postorder(tree);
    printf("\n");
    levelorder(tree);
    printf("\n");
}
