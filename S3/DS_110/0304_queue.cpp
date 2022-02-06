// Description

// 請完成函數 enqueue 跟函數 dequeue

// enqueue 會把 data 放進 queue 的頂端，如果成功回傳 1 ，如果失敗回傳 -1 。

// dequeue 會從 queue 的底端拿一筆資料出來，如共成功就回傳指向該資料的指標，如果失敗就回傳 NULL 指標

// 如果你想要，你可以在類別中加入任何的成員。

// Please finish function enqueue and dequeue

// Function enqueue will insert the data from the top of queue and return 1 on success, return -1 if not.

// Function dequeue will remove one data from the bottom of queue and return a pointer point the data, return NULL if there are on data.

// You can add member to the class if you need.

// #include <iostream>
// #include <string>

// #define SIZE 100

// using namespace std;

// class Node
// {
//     int data;
//     Node *next;
// };

// class Queue
// {
// public:
//     Queue()
//     {
//     }
//     int enqueue(int data)
//     {
//     }
//     int *dequeue()
//     {
//     }

// private:
//     Node *top, *bot;
// };

// int main()
// {
//     int data, *temp;
//     string command;
//     Queue *queue = new Queue();
//     while (1)
//     {
//         cin >> command;
//         if (command.compare("exit") == 0)
//         {
//             break;
//         }
//         else if (command.compare("enqueue") == 0)
//         {
//             cout << "Please input a integer data:";
//             cin >> data;
//             if (queue->enqueue(data) == 1)
//             {
//                 cout << "Successfully enqueue data " << data << " into queue." << endl;
//             }
//             else
//             {
//                 cout << "Failed to enqueue data into queue." << endl;
//             }
//         }
//         else if (command.compare("dequeue") == 0)
//         {
//             temp = queue->dequeue();
//             if (temp == NULL)
//             {
//                 cout << "Failed to dequeue a data from queue.\n";
//             }
//             else
//             {
//                 cout << "Dequeue data " << *temp << " from queue." << endl;
//             }
//         }
//     }
// }

// 如果你完成這兩個函數，你可以拿到100 分

// You can get 100 point if you finish this two function.

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

class Queue
{
public:
    Queue()
    {
    }
    int enqueue(int _data)
    {
        // insert the data from the top of queue and return 1 on success, return -1 if not.
        try
        {
            int a = 0;
            Node *new_ptr = new Node(_data, top);
            throw a;
        }
        catch (int &a)
        {
            a++;
            return -1;
        }
        if (top == nullptr)
            bot = new_ptr;
        top = new_ptr;
        return 1;
    }
    Node *dequeue()
    {
        // remove one data from the bottom of queue and return a pointer point the data,
        // return NULL if there are on data.
        if (bot == nullptr)
            return nullptr;
        Node *cur = bot;
        if (top == bot)
        {
            top = nullptr;
            bot = nullptr;
        }
        else
        {
            bot = find_prev(bot);
            bot->next = nullptr;
        }
        return cur;
    }
    Node *find_prev(Node *&ptr)
    {
        //
        Node *cur = top;
        int i = 0;
        while (cur->next != nullptr && cur->next != ptr)
        {
            cur = cur->next;
        }
        if (cur->next == nullptr)
            return cur;
        else
            return cur;
    }
    void show()
    {
        Node *cur = top;
        while (cur != nullptr)
        {
            cout << cur->data << endl;
            cur = cur->next;
        }
    }

private:
    Node *top = nullptr, *bot = nullptr;
};

int main()
{
    int data;
    Node *temp;
    string command;
    Queue *queue = new Queue();
    while (1)
    {
        cin >> command;
        if (command.compare("exit") == 0)
        {
            break;
        }
        else if (command.compare("enqueue") == 0)
        {
            cout << "Please input a integer data:";
            cin >> data;
            if (queue->enqueue(data) == 1)
            {
                cout << "Successfully enqueue data " << data << " into queue." << endl;
            }
            else
            {
                cout << "Failed to enqueue data into queue." << endl;
            }
        }
        else if (command.compare("dequeue") == 0)
        {
            temp = queue->dequeue();
            if (temp == NULL)
            {
                cout << "Failed to dequeue a data from queue." << endl;
            }
            else
            {
                cout << "Dequeue data " << temp->data << " from queue." << endl;
            }
        }
        else if (command.compare("show") == 0)
        {
            queue->show();
        }
    }
}