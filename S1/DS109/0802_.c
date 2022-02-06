// 請完成樣板中的 remove(removal)跟 inorder 兩個函數。

// 請維持二元搜尋樹的特性。

// Please finish the two function remove and inorder in template.

// Please make sure that tree still be a binary search tree after remove .
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

/*
Function removal will remove all the node tree content data n.
The return value of function removal is a integer represent how many node are removed.
*/
int removal(int root[20][4], int n)
{
}

int main()
{
    int tree[20][4];
    int j, k, l, node;
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
    for (j = 0; j < 5; j++)
    {
        l = rand() % 10;
        k = removal(tree, l);
        printf("Remove %d(%d)\n", l, k);
    }
    inorder(tree);
    printf("\n");
}
