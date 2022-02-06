#include "BTree.h"
enum TOKEN { RIGHT_PAREN, OR, AND, NOT, LEFT_PAREN };

int getPriority(char token, bool instack) {
	switch (token) {
	case '|':
		return OR;
	case '&':
		return AND;
	case '~':
		return NOT;
	case '(':
		if (!instack)
			return LEFT_PAREN;
		else
			return 0;
	case ')':
		return RIGHT_PAREN;
	}
	return 0;
}

Node* createTree(Node* op, stack<Node*>* opnd) {
	if ((op->token == '&') || (op->token == '|')) {
		Node* n1, * n2;
		n2 = opnd->top();
		opnd->pop();
		n1 = opnd->top();
		opnd->pop();
		op->left = n1;
		op->right = n2;
		n1->parent = n2->parent = op;
	}
	else if (op->token == '~') {
		Node* n = opnd->top();
		opnd->pop();
		op->left = n;
		n->parent = op;
	}
	else
		op = NULL;
	return op;
}

void constructSubtree(Node* newOptrNode, stack<Node*>* optr, stack<Node*>* opnd) {
	Node* top = optr->top();
	// optr->pop();
	int priority1 = getPriority(newOptrNode->token, false);
	int priority2 = getPriority(top->token, true);

	while (top && priority1 <= priority2) {
		Node* subtree_root = createTree(top, opnd);
		if (subtree_root)
			opnd->push(subtree_root);
		optr->pop();
		if (optr->empty() || !subtree_root)
			break;
		top = optr->top();
		priority2 = getPriority(top->token, true);
	}
}

void traverse(Node* p, int level) {
	for (int i = 0; i < level; i++)
		cout << "\t";
	cout << p->token << endl;
	if (!p->left && !p->right) {
		return;
	}
	else {
		if (p->left)
			traverse(p->left, level + 1);
		if (p->right)
			traverse(p->right, level + 1);
	}
}

BTree::BTree(string expr) {
	Node* p;
	stack<Node*> optr;
	stack<Node*> opnd;
	for (int i = 0; i < (int)expr.length(); i++) {
		p = new Node(expr[i]);
		if (isalpha(expr[i])) {
			opnd.push(p);
			table[expr[i]] = p;
		}
		else {
			int priority1 = getPriority(expr[i], false);
			int priority2 = 0;
			if (!optr.empty()) {
				priority2 = getPriority(optr.top()->token, true);
				if (priority1 <= priority2)
					constructSubtree(p, &optr, &opnd);
			}
			if (p->token != ')')
				optr.push(p);
		}
	}
	while (!optr.empty()) {
		p = optr.top();
		optr.pop();
		opnd.push(createTree(p, &opnd));
	}
	root = opnd.top();
}

void BTree::show() {
	traverse(root, 0);
}

void BTree::setVar(char var, bool val) {
	table[var]->result = val;
}

bool BTree::evaluate(Node* p) {
	if (isalpha(p->token)) {
		p->result = (bool)table[p->token]->result;
		return p->result;
	}
	else if (p && p->token == '&')
		p->result = (evaluate(p->left) && evaluate(p->right));
	else if (p && p->token == '|')
		p->result = (evaluate(p->left) || evaluate(p->right));
	else if (p && p->token == '~')
		p->result = !(evaluate(p->left));
	return p->result;
}
