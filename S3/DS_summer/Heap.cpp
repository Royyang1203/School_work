#include "Binary_Tree.cpp"

template <class T>
class MaximumHeap : public BinaryTree<T>
{
public:
    MaximumHeap() : BinaryTree<T>()
    {
    }
    void insert(T d)
    {
        TreeNode<T> *node = new TreeNode<T>(d);
        if (this->root == NULL)
            this->root = node;
        else
        {
            int j = this->count + 1;
            int k = 1;
            TreeNode<T> *cur = this->root;
            while (k <= j)
                k = k << 1;
            k = k >> 2;
            while (1)
            {
                if (*node > *cur)
                {
                    TreeNode<T> *temp = cur;
                    TreeNode<T> *father = this->getFather(cur);
                    if (father == NULL)
                        this->root = node;
                    else if (father->getLeft() == cur)
                        father->setLeft(node);
                    else
                        father->setRight(node);
                    node->setLeft(cur->getLeft());
                    node->setRight(cur->getRight());
                    cur = node;
                    node = temp;
                    node->setLeft(NULL);
                    node->setRight(NULL);
                }
                if (k <= 1)
                    break;
                if (k & j)
                    cur = cur->getRight();
                else
                    cur = cur->getLeft();
                k = k >> 1;
            }
            if (k & j)
                cur->setRight(node);
            else
                cur->setLeft(node);
        }
        this->count++;
    }
    TreeNode<T> *removeRoot()
    {
        if (this->root == NULL)
            return NULL;
        TreeNode<T> *node = this->root;
        this->remove(node);
        TreeNode<T> *cur = this->root;
        if (cur == NULL)
            this->root = NULL;
        while (cur)
        {
            if ((cur->getLeft() != NULL && *cur->getLeft() > *cur && cur->getRight() == NULL) || (cur->getRight() != NULL && cur->getLeft() != NULL && *cur->getLeft() > *cur && *cur->getLeft() > *cur->getRight()))
                this->swapNode(cur, cur->getLeft());
            else if (cur->getRight() != NULL && *cur->getRight() > *cur)
                this->swapNode(cur, cur->getRight());
            else
                break;
        }
        return node;
    }

private:
};