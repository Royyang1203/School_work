// 請完成樣板中的 inorder, preorder, postorder 以及 levelorder 四個函數

// Please finish four function in the template, inorder, preorder, postorder and levelorder.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int insert(int root[2000], int node)
{
    int index = 0;
    while (index < 2000 && root[index] != -1)
    {
        if (root[index] < node)
            index = index * 2 + 2;
        else
            index = index * 2 + 1;
    }
    root[index] = node;
}

void inorder(int root[2000])
{
}

void preorder(int root[2000])
{
}

void postorder(int root[2000])
{
}

void levelorder(int root[2000])
{
}

int main()
{
    int tree[2000];
    int j, k, node;
    srand(time(NULL));

    for (j = 0; j < 2000; j++)
        tree[j] = -1;

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
