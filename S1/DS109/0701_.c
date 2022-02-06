// 請完成樣板中的 inorder, preorder, postorder 以及 levelorder 四個函數

// Please finish four function in the template, inorder, preorder, postorder and levelorder.

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

void inorder(struct Node *root)
{
}

void preorder(struct Node *root)
{
}

void postorder(struct Node *root)
{
}

void levelorder(struct Node *root)
{
}

int main()
{
    struct Node *tree = NULL, *node;
    int j;
    srand(time(NULL));
    for (j = 0; j < 10; j++)
    {
        node = (struct Node *)malloc(sizeof(struct Node));
        node->data = rand();
        node->left = NULL;
        node->right = NULL;
        insert(&tree, node);
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
