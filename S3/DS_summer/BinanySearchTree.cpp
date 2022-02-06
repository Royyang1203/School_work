#include "Binary_Tree.cpp"
#include "LinkLIst.cpp"

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
public:
    BinarySearchTree() : BinaryTree<T>()
    {
    }
    void insertRecursion(T d)
    {
        TreeNode<T> *node = new TreeNode<T>(d);
        _insertRecursion(&(this->root), node);
    }
    TreeNode<T> *insert(T d)
    {
        TreeNode<T> *node = new TreeNode<T>(d);
        if (this->root == NULL)
            this->root = node;
        else
        {
            TreeNode<T> *cur = this->root;
            while (1)
            {
                if (*node > *cur)
                {
                    if (cur->getRight() == NULL)
                    {
                        cur->setRight(node);
                        break;
                    }
                    else
                        cur = cur->getRight();
                }
                else if (*cur > *node)
                {
                    if (cur->getLeft() == NULL)
                    {
                        cur->setLeft(node);
                        break;
                    }
                    else
                        cur = cur->getLeft();
                }
                else
                    break;
            }
        }
        return node;
    }
    void printLoop()
    {
        Stack<TreeNode<T> *> *stack = new Stack<TreeNode<T> *>();
        TreeNode<T> *cur = this->root;
        while (1)
        {
            if (cur == NULL)
            {
                if (stack->isEmpty())
                    break;
                cur = stack->pop()->getData();
                std::cout << cur << " ";
                cur = cur->getRight();
                continue;
            }
            stack->push(cur);
            cur = cur->getLeft();
        }
    }
    TreeNode<T> *search(T d)
    {
        TreeNode<T> *cur = this->root;
        TreeNode<T> *node = new TreeNode<T>(d);
        while (cur)
        {
            if (*cur == *node)
                return cur;
            if (*cur > *node)
                cur = cur->getLeft();
            else
                cur = cur->getRight();
        }
        return NULL;
    }
    TreeNode<T> *remove(T d)
    {
        TreeNode<T> *node = search(d);
        return remove(node);
    }
    TreeNode<T> *remove(TreeNode<T> *node)
    {
        TreeNode<T> *cur;

        if (node != NULL)
        {
            if (node->getLeft() == NULL && node->getRight() == NULL)
            {
                cur = this->getFather(node);
                if (cur->getLeft() == node)
                    cur->setLeft(NULL);
                else
                    cur->setRight(NULL);
            }
            else if (node->getLeft() != NULL)
            {
                cur = node->getLeft();
                while (cur->getRight())
                    cur = cur->getRight();
                this->swapNode(node, cur);
                remove(node);
            }
            else
            {
                cur = node->getRight();
                while (cur->getLeft())
                    cur = cur->getLeft();
                this->swapNode(node, cur);
                remove(node);
            }
        }
        return node;
    }

private:
    void _insertRecursion(TreeNode<T> **r, TreeNode<T> *node)
    {
        if (*r == NULL)
            *r = node;
        else if (**r > *node)
            _insertRecursion(&((*r)->getLeft()), node);
        else if (*node > **r)
            _insertRecursion(&((*r)->getRight()), node);
    }
};

int main()
{
    BinarySearchTree<int> *tree = new BinarySearchTree<int>();
    TreeNode<int> *node;
    //srand(time(NULL));
    int j, k, n;
    std::cin >> n;
    for (j = 0; j < n; j++)
    {
        k = rand() % 100;
        std::cout << k << " ";
        tree->insertRecursion(k);
    }
    std::cout << std::endl;
    tree->print();
    tree->printLoop();
    //tree->print();
    //tree->remove(tree->getRoot()->getLeft());
    //tree->print();
    return 0;
}