// 請完成樣板中的 remove(removal) 跟 inorder 兩個函數。

// 請維持二元搜尋樹的特性。

// Please finish the two function remove and inorder in template.

// Please make sure that tree still be a binary search tree after remove .
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data, level;
    struct Node *left, *right;
};

void insert(struct Node **root, struct Node *node)
{
    if (*root == NULL)
        *root = node;
    else if (node->data > (*root)->data)
        insert(&((*root)->right), node);
    else
        insert(&((*root)->left), node);
}

/*
Function removal will remove all the node tree content data n.
The return value of function removal is a integer represent how many node are removed.
*/
int removal(struct Node **root, int n)
{
}

void inorder(struct Node *root)
{
}

int main()
{
    struct Node *tree = NULL, *node;
    int j, k, l;
    srand(time(NULL));
    for (j = 0; j < 10; j++)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = rand() % 10;
        node->left = NULL;
        node->right = NULL;
        insert(&tree, node);
    }
    inorder(tree);
    printf("\n");
    for (j = 0; j < 5; j++)
    {
        l = rand() % 10;
        k = removal(&tree, l);
        printf("Remove %d(%d)\n", l, k);
    }
    inorder(tree);
    printf("\n");
}
