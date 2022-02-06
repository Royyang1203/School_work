// Description

// 請完成函數 push 跟函數 pop

// push 這個函數會把 data push 進 stack 裡，如果成功會回傳 1 ，如果失敗會回傳 -1

// pop 會從 stack 裡 pop 最上面的資料出來，如果成功就回傳指向該資料的指標，如果失敗就回傳 NULL

// 如果你想要，你可以在類別中加入任何的成員。

// Please finish two function push and pop

// Function push will push the data into stack and return 1 if success, return -1 if not.

// Function pop will pop the top data from stack and return a pointer point to the data, return NULL if there is no data.

// You can add member to the class if you need.

// #include <iostream>
// #include <string>

// #define SIZE 100

// using namespace std;

// class Node
// {
// public:
//     int data;
//     Node *next;
// };

// class Stack
// {
// public:
//     Stack()
//     {
//     }
//     int push(int d)
//     {
//     }

//     int *pop()
//     {
//     }

// private:
//     Node *data;
// };

// int main()
// {
//     int data, *temp;
//     string command;
//     Stack *stack = new Stack();
//     while (1)
//     {
//         cin >> command;
//         if (command.compare("exit") == 0)
//         {
//             break;
//         }
//         else if (command.compare("push") == 0)
//         {
//             cout << "Please input a integer data:";
//             cin >> data;
//             if (stack->push(data) == 1)
//             {
//                 cout << "Successfully push data %d into stack.\n";
//             }
//             else
//             {
//                 cout << "Failed to push data into stack.\n";
//             }
//         }
//         else if (command.compare("pop") == 0)
//         {
//             temp = stack->pop();
//             if (temp == NULL)
//             {
//                 cout << "Failed to pop a data from stack.\n";
//             }
//             else
//             {
//                 cout << "Pop data %d from stack.\n"
//                      << *temp;
//             }
//         }
//     }
// }

// 如果你成功的完成了指定的函數，你可以得到100分

// You can get 100 point if finish this two function.

// 這題的期限到2021/10/19

// This assignment due to 2021/10/19

#include <iostream>
#include <string>

#define SIZE 100

using namespace std;

class Node
{
public:
    Node() = default;
    Node(int _data, Node *_next = nullptr) : data(_data), next(_next) {}
    int data = 0;
    Node *next = nullptr;
};

class Stack
{
public:
    Stack()
    {
    }
    int push(int _data)
    {
        // push the data into stack and return 1 if success, return -1 if not.
        Node *new_ptr = new Node(_data, data);
        data = new_ptr;
        return 1;
    }

    Node *pop()
    {
        // pop the top data from stack and return a pointer point to the data,
        // return NULL if there is no data.
        if (data == nullptr)
            return nullptr;
        Node *ptr = data;
        data = data->next;
        return ptr;
    }

private:
    Node *data = nullptr;
};

int main()
{
    int data;
    Node *temp;
    string command;
    Stack *stack = new Stack();
    while (1)
    {
        cin >> command;
        if (command.compare("exit") == 0)
        {
            break;
        }
        else if (command.compare("push") == 0)
        {
            cout << "Please input a integer data:";
            cin >> data;
            if (stack->push(data) == 1)
            {
                cout << "Successfully push data " << data << " into stack.\n";
            }
            else
            {
                cout << "Failed to push data into stack.\n";
            }
        }
        else if (command.compare("pop") == 0)
        {
            temp = stack->pop();
            if (temp == NULL)
            {
                cout << "Failed to pop a data from stack.\n";
            }
            else
            {
                cout << "Pop data " << temp->data << " from stack.\n";
            }
            delete temp;
        }
    }
}