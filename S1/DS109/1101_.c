// 請完成樣板中的最大堆積

// Please finish the maximum heap in template.

// 如果你能完成所有功能你可以得到60分

// If you complete all function then you can get 60 points.

// 如果你在插入時能保持樹的平衡你可以在得到額外的20分

// If you can keep the heap height-balanced while insert, then you can get extract 20 points.

// 如果你在移除節點時也能保持樹的平衡，你可以在得到額外的20分

// If you can keep the heap height-balanced while remove, then you can get extract 20 points.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node
{
    int data;
    struct Node *left, *right;
};

/*
Function getHeight take one parameter represent a tree root
and return an integer as the height of the tree.
*/
int getHeight(struct Node *root)
{
}

/*
Function insert take parament root represent a maximum heap and insert data
into the maximum heap.
*/
void insert(struct Node **root, int data)
{
}

/*
Function remove take parament root represent a maximum heap and remove the root
from heap.
Please keep the heap as a maximum heap while removing the root.
Return the data you removed.
If there is nothing in the heap, return NULL.
*/
struct Node *remove(struct Node **root)
{
}

int main()
{
    int j;
    struct Node *k;
    struct Node *heap = NULL;
    srand(time(NULL));

    for (j = 0; j < 31; j++)
        insert(&heap, rand());

    while (1)
    {
        k = remove(&heap);
        if (k == NULL)
            break;
        printf("%d(%d) ", k->data, getHeight(heap));
    }
}
