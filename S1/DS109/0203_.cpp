// Description

// 請完成函數 enqueue 跟函數 dequeue

// enqueue 會把 data 放進 queue 的頂端，如果成功回傳 1 ，如果失敗回傳 -1
// dequeue 會從 queue 的底端拿一筆資料出來，如共成功就回傳指向該資料的指標，如果失敗就回傳 NULL 指標

// Please finish function enqueue and dequeue

// Function enqueue will insert the data from the top of queue and return 1 on success, return -1 if not .

// Function dequeue will remove one data from the bottom of queue and return a pointer point the data,
// return NULL if there are on data.

// #include <iostream>
// #include <cstring>

// #define SIZE 100

// using namespace std;

// class Queue
// {
// public:
//     Queue()
//     {
//         top = 0;
//         bot = -1;
//     }
//     int enqueue(int data)
//     {
//     }
//     int *dequeue()
//     {
//     }

// private:
//     int data[SIZE];
//     int top, bot;
// };

// int main()
// {
//     int data, *temp;
//     char command[50];
//     Queue *queue = new Queue();
//     while (1)
//     {
//         cin >> command;
//         if (strcmp(command, "exit") == 0)
//         {
//             break;
//         }
//         else if (strcmp(command, "enqueue") == 0)
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
//         else if (strcmp(command, "dequeue") == 0)
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

// 如果你完成這兩個函數，你可以拿到80 分

//     如果你的 queue 是環狀的，你可以拿到 100 分

//         You can get 80 point if you finish this two function.

//     You can get 100 point if you queue is circularity.