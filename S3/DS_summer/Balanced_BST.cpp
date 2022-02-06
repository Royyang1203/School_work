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
	TreeNode<T> *rotateL(TreeNode<T> *node)
	{
		TreeNode<T> *r = node->getRight();
		if (r == NULL)
			return NULL;
		TreeNode<T> *rl = r->getLeft();
		TreeNode<T> *f = this->getFather(node);
		if (f != NULL)
			if (f->getLeft() == node)
				f->setLeft(r);
			else
				f->setRight(r);
		else
			this->root = r;
		r->setLeft(node);
		node->setRight(rl);
		return r;
	}
	TreeNode<T> *rotateR(TreeNode<T> *node)
	{
		TreeNode<T> *l = node->getLeft();
		if (l == NULL)
			return NULL;
		TreeNode<T> *lr = l->getRight();
		TreeNode<T> *f = this->getFather(node);
		if (f != NULL)
			if (f->getLeft() == node)
				f->setLeft(l);
			else
				f->setRight(l);
		else
			this->root = l;
		l->setRight(node);
		node->setLeft(lr);
		return l;
	}
	void balance()
	{
		_balance(this->root);
	}
	int getHeight(TreeNode<T> *node)
	{
		if (node == NULL)
			return 0;
		int l, r;
		l = getHeight(node->getLeft());
		r = getHeight(node->getRight());
		return 1 + ((l > r) ? l : r);
	}
	int getNodeCount(TreeNode<T> *node)
	{
		if (node == NULL)
			return 0;
		return getNodeCount(node->getRight()) + getNodeCount(node->getLeft()) + 1;
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
	void _balance(TreeNode<T> *node)
	{
		if (node == NULL)
			return;
		int l, r;
		l = getNodeCount(node->getLeft());
		r = getNodeCount(node->getRight());
		while (l - r > 1 || l - r <= -1)
		{
			if (l > r)
			{
				if (getNodeCount(node->getLeft()->getRight()) + getNodeCount(node->getRight()) + 1 > getNodeCount(node->getLeft()->getLeft()))
					rotateL(node->getLeft());
				node = rotateR(node);
			}
			else
			{
				if (getNodeCount(node->getRight()->getLeft()) + getNodeCount(node->getLeft()) + 1 > getNodeCount(node->getRight()->getRight()))
					rotateR(node->getRight());
				node = rotateL(node);
			}
			l = getNodeCount(node->getLeft());
			r = getNodeCount(node->getRight());
		}
		_balance(node->getLeft());
		_balance(node->getRight());
	}

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
		tree->insert(k);
	}
	std::cout << std::endl;
	tree->print();
	std::cout << "-----------------------" << std::endl;
	tree->balance();
	tree->print();
	return 0;
}