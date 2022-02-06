// Assignment 3: Boolean Expression Trees
// Problem Descriptions
// A binary tree can be used to represent a Boolean expression.
// The following shows the example for representing the Boolean expression a&b|c&~d.

// With the constructed tree, we can also evaluate the result of this expression
// after instantiating each Boolean variable with a Boolean value of either true or false.
// For the above example, if a=true, b=false, c=true, and d=false, the evaluation result would be true.

// This assignment requires you to construct a tree from a Boolean expression
// and then evaluate its result according to the instantiation of the contained Boolean variables.

// Display a Boolean Expression Tree
// To output the whole tree, you need to traverse the tree in preorder
// and output each node in one line with different indentations.
// A symbol in a node at level l outputted in each line must be indented by preceding this symbol with ( l − 1 ) tab spaces.
// For the tree given in the above example, the output would be like the following.

// |
//     &
//         a
//         b
//     &
//         c
//         ~
//             d

// ADT Design
// The following is the declarations used for solving problem.

// #pragma once
// #include <string>
// #include <stack>
// #include <queue>
// #include <map>
// #include <iostream>
// using namespace std;
// enum TOKEN {RIGHT_PAREN, OR, AND, NOT, LEFT_PAREN};

// class Node {
// public:
// 	Node(char token) {
// 		this->token = token;
// 		left = right = parent = NULL;
// 		result = -1;
// 	}
// 	char token; // the one-char symbol representing either an operator or an operand
// 	Node* left; // pointer to the left child
// 	Node* right; // pointer to the right child
// 	Node* parent; // pointer to the parent node
// 	bool result; // the evaluated Boolean result for this node/subtree
// };

// class BTree
// {
// public:
// 	Node* root; // pointer to the root node
// 	BTree(string expr); // constructing a tree from a specified expression (in the string format)
// 	bool evaluate(Node* p); // evaluate the node/subtree rooted by the specified node
// 	void setVar(char var, bool val); // instantiate a variable with the specified Boolean value
// 	void show(); // output the constructed tree
// 	map<char, Node*> table; // you can use the map class provided by the C++ STL to maintain a table for looking up the the instantiations of all variables.
// };

// Test Case 1:

// BTree etree = BTree("~a&((~b)|(~c)&d)");
// etree.setVar('a', true);
// etree.setVar('b', false);
// etree.setVar('c', false);
// etree.setVar('d', true);
// etree.evaluate(etree.root);
// etree.show();
// cout << "The evaluated result = " << etree.root->result << endl;
// Expected Output:

// &
//         ~
//                 a
//         |
//                 ~
//                         b
//                 &
//                         ~
//                                 c
//                         d
// The evaluated result = 0
// Test Case 2:

// BTree etree = BTree("~a&((~b)|(~c))");
// etree.setVar('a', false);
// etree.setVar('b', false);
// etree.setVar('c', false);
// etree.evaluate(etree.root);
// etree.show();
// cout << "The evaluated result = " << etree.root->result << endl;
// Expected Output:

// &
//         ~
//                 a
//         |
//                 ~
//                         b
//                 ~
//                         c
// The evaluated result = 1

// #pragma once
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <iostream>
using namespace std;
enum TOKEN
{
    RIGHT_PAREN, // ')'
    OR,          // '|'
    AND,         // '&'
    NOT,         // '~'
    LEFT_PAREN   // '('
};

class Node
{
public:
    Node(char token)
    {
        this->token = token;
        left = right = parent = NULL;
        result = -1;
    }
    char token;   // the one-char symbol representing either an operator or an operand
    Node *left;   // pointer to the left child
    Node *right;  // pointer to the right child
    Node *parent; // pointer to the parent node
    bool result;  // the evaluated Boolean result for this node/subtree
};

class BTree
{
public:
    Node *root;                      // pointer to the root node
    BTree(string expr);              // constructing a tree from a specified expression (in the string format)
    bool evaluate(Node *p);          // evaluate the node/subtree rooted by the specified node
    void setVar(char var, bool val); // instantiate a variable with the specified Boolean value
    void show();                     // output the constructed tree
    map<char, Node *> table;         // you can use the map class provided by the C++ STL to maintain a table for looking up the the instantiations of all variables.
};

int get_pri(char _ch, bool _b = true)
{
    switch (_ch)
    {
    case '|':
        return OR;
    case '&':
        return AND;
    case '~':
        return NOT;
    case '(':
        return _b ? LEFT_PAREN : 0;
    case ')':
        return RIGHT_PAREN;
    }
    return 0;
}

Node *bind_tree(Node *_root, Node *_l, Node *_r)
{
    // cout << _root << " " << _l << " " << _r << endl;
    _root->left = _l;
    _root->right = _r;
    _l->parent = _root;
    if (_r != NULL)
        _r->parent = _root;
    return _root;
}

/**
 * @brief constructing a tree from a specified expression (in the string format)
 *
 * @param expr
 */
BTree::BTree(string expr)
{
    int n = 0;
    std::stack<Node *> oprd;
    std::stack<Node *> oprt;
    while (expr[n] != '\0')
    {

        // cout << oprt.size() << endl;
        // cout << expr[n] << endl;
        Node *ptr = new Node(expr[n]);
        // cout << ptr << endl;
        if (isalpha(expr[n]))
        {
            oprd.push(ptr);
            table[expr[n]] = ptr;
        }
        else
        {
            if (oprt.empty() || get_pri(expr[n]) > get_pri(oprt.top()->token, false))
            {
                oprt.push(ptr);
            }
            else
            {
                while (!oprt.empty() && get_pri(expr[n]) <= get_pri(oprt.top()->token, false))
                {
                    if (expr[n] == ')' && oprt.top()->token == '(')
                    {
                        oprt.pop();
                        break;
                    }
                    else if (oprt.top()->token == '~')
                    {
                        Node *tmp = oprd.top();
                        oprd.pop();
                        oprd.push(bind_tree(oprt.top(), tmp, NULL));
                        oprt.pop();
                    }
                    else
                    {
                        Node *tmpl = oprd.top();
                        oprd.pop();
                        Node *tmpr = oprd.top();
                        oprd.pop();
                        oprd.push(bind_tree(oprt.top(), tmpr, tmpl));
                        oprt.pop();
                    }
                }
                if (expr[n] != ')')
                {
                    oprt.push(ptr);
                }
            }
        }
        ++n;
    }
    // cout << oprt.size();
    while (!oprt.empty())
    {
        if (oprt.size() == 1)
        {
            root = oprt.top();
        }
        if (oprt.top()->token == '~')
        {
            Node *tmp = oprd.top();
            oprd.pop();
            oprd.push(bind_tree(oprt.top(), tmp, NULL));
            oprt.pop();
        }
        else
        {
            Node *tmpl = oprd.top();
            oprd.pop();
            Node *tmpr = oprd.top();
            oprd.pop();
            oprd.push(bind_tree(oprt.top(), tmpr, tmpl));
            oprt.pop();
        }
    }
}

void BTree::setVar(char _ch, bool _b)
{
    table[_ch]->result = _b;
}

bool BTree::evaluate(Node *p)
{
    if (isalpha(p->token))
        p->result = table[p->token]->result;
    else if (p->token == '&')
        p->result = (evaluate(p->left) && evaluate(p->right));
    else if (p->token == '|')
        p->result = (evaluate(p->left) || evaluate(p->right));
    else if (p->token == '~')
        p->result = !(evaluate(p->left));
    return p->result;
}

void BTree::show()
{
    stack<Node *> stk;
    Node *cur = root;
    int deeps = -1;
    while (1)
    {

        while (cur)
        {
            // cout << cur->token << cur << endl;
            // int a;
            // cin >> a;
            ++deeps;
            for (int i = 0; i < deeps; ++i)
                cout << "\t";
            cout << cur->token << endl;
            stk.push(cur);
            cur = cur->left;
        }
        if (stk.empty())
            return;
        cur = stk.top()->right;
        stk.pop();
        if (!cur)
            --deeps;
    }
}

int main()
{
    BTree etree = BTree("~a&((~b)|(~c)&d)&(~(e|f&g))");
    // cout << "eeee";
    etree.setVar('a', true);
    etree.setVar('b', false);
    etree.setVar('c', false);
    etree.setVar('d', true);
    etree.setVar('e', true);
    etree.setVar('f', false);
    etree.setVar('g', true);
    // cout << "asdf";
    // int f;
    // cin >> f;
    etree.evaluate(etree.root);
    // cout << "eva";
    etree.show();
    // cout << "shoe";
    cout << "The evaluated result = " << etree.root->result << endl;

    // BTree etree = BTree("~a&((~b)|(~c))");
    // etree.setVar('a', false);
    // etree.setVar('b', false);
    // etree.setVar('c', false);
    // etree.evaluate(etree.root);
    // etree.show();
    // cout << "The evaluated result = " << etree.root->result << endl;
    return 0;
}