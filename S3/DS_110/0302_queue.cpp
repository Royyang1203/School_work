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
// #include <cstring>

// #define SIZE 100

// using namespace std;

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
//     int data[SIZE];
// };

// int main()
// {
//     int data, *temp;
//     char command[50];
//     Queue *queue = new Queue();
//     while(1)
//     {
//         cin>>command;
//         if(strcmp(command, "exit") == 0)
//         {
//             break;
//         }
//         else if(strcmp(command, "enqueue") == 0)
//         {
//             cout<<"Please input a integer data:";
//             cin>>data;
//             if(queue->enqueue(data) == 1)
//             {
//                 cout<<"Successfully enqueue data "<<data<<" into queue."<<endl;
//             }
//             else
//             {
//                 cout<<"Failed to enqueue data into queue."<<endl;
//             }
//         }
//         else if(strcmp(command, "dequeue") == 0)
//         {
//             temp = queue->dequeue();
//             if(temp == NULL)
//             {
//                 cout<<"Failed to dequeue a data from queue.\n";
//             }
//             else
//             {
//                 cout<<"Dequeue data "<<*temp<<" from queue."<<endl;
//             }
//         }
//     }
// }

// 如果你完成這兩個函數，你可以拿到80 分

// 如果你的 queue 是環狀的，你可以拿到 100 分

// You can get 80 point if you finish this two function.

// You can get 100 point if you queue is circularity.

// 這題的期限到2021/10/19

// This assignment due to 2021/10/19

#include <iostream>
#include <cstring>

#define SIZE 3

using namespace std;

class Queue
{
public:
    Queue()
    {
    }
    int enqueue(int _data)
    {
        // insert the data from the top of queue and return 1 on success, return -1 if not.
        if (full)
            return -1;
        data[head++] = _data;
        head %= SIZE;
        if (head == tail)
            full = true;
        return 1;
    }
    int *dequeue()
    {
        // remove one data from the bottom of queue and return a pointer point the data,
        // return NULL if there are on data.
        if (head == tail && !full)
            return nullptr;
        if (full)
            full = false;
        int *return_ptr = &data[tail++];
        tail %= SIZE;
        return return_ptr;
    }

private:
    int data[SIZE];
    int head = 0;  // point to the next enqueue data's position
    int tail = 0;  // point to the next dequeue data's position
    bool full = 0; // tall whether the queue is fall
};

int main()
{
    int data, *temp;
    char command[50];
    Queue *queue = new Queue();
    while (1)
    {
        cin >> command;
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "enqueue") == 0)
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
        else if (strcmp(command, "dequeue") == 0)
        {
            temp = queue->dequeue();
            if (temp == NULL)
            {
                cout << "Failed to dequeue a data from queue.\n";
            }
            else
            {
                cout << "Dequeue data " << *temp << " from queue." << endl;
            }
        }
    }
}