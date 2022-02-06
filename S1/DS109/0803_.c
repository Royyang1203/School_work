// 請完成樣板中的 remove(removal)跟 inorder 兩個函數。

// 請維持二元搜尋樹的特性。

// Please finish the two function remove and inorder in template.

// Please make sure that tree still be a binary search tree after remove .
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

/*
Function removal will remove all the node tree content data n.
The return value of function removal is a integer represent how many node are removed.
*/
int removal(int root[2000], int n)
{
}

int main()
{
    int tree[2000];
    int j, k, l, node;
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
    for (j = 0; j < 5; j++)
    {
        l = rand() % 10;
        k = removal(tree, l);
        printf("Remove %d(%d)\n", l, k);
    }
    inorder(tree);
    printf("\n");
}
