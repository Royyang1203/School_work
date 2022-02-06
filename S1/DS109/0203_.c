// Description

// 請完成函數 enqueue 跟函數 dequeue

// enqueue 會把 data 放進 queue 的頂端，如果成功回傳 1 ，如果失敗回傳 -1

// dequeue 會從 queue 的底端拿一筆資料出來，如共成功就回傳指向該資料的指標，如果失敗就回傳 NULL 指標

// Please finish function enqueue and dequeue

// Function enqueue will insert the data from the top of queue and return 1 on success, return -1 if not .

// Function dequeue will remove one data from the bottom of queue and return a pointer point the data,
// return NULL if there are on data.

// #include <stdio.h>
// #include <string.h>

// #define SIZE 100

//     struct Queue
// {
//     int data[SIZE];
//     int top, bot;
// };

// int enqueue(struct Queue *queue, int data)
// {
// }

// int *dequeue(struct Queue *queue)
// {
// }

// int main()
// {
//     int data, *temp;
//     char command[50];
//     struct Queue queue;
//     queue.top = 0;
//     queue.but = 0;
//     while (1)
//     {
//         scanf("%s", command);
//         if (strcmp(command, "exit") == 0)
//         {
//             break;
//         }
//         else if (strcmp(command, "enqueue") == 0)
//         {
//             printf("Please input a integer data:");
//             scanf("%d", &data);
//             if (enqueue(&queue, data) == 1)
//             {
//                 printf("Successfully enqueue data %d into queue.\n");
//             }
//             else
//             {
//                 printf("Failed to enqueue data into queue.\n");
//             }
//         }
//         else if (strcmp(command, "dequeue") == 0)
//         {
//             temp = dequeue(&queue);
//             if (temp == NULL)
//             {
//                 printf("Failed to dequeue a data from queue.\n");
//             }
//             else
//             {
//                 printf("Dequeue data %d from queue.\n", *temp);
//             }
//         }
//     }
// }

// 如果你完成這兩個函數，你可以拿到80 分

// 如果你的 queue 是環狀的，你可以拿到 100 分

// You can get 80 point if you finish this two function.

// You can get 100 point if you queue iscircularity.

#include <stdio.h>
#include <string.h>

#define SIZE 100

struct Queue
{
    int data[SIZE];
    int top, bot, tag; // 如果全滿 tag 的值為 1 ，反之為 0
};

int enqueue(struct Queue *queue, int data)
{
    if (queue->tag)
        return -1;
    queue->data[queue->bot] = data;
    queue->bot = (queue->bot + 1) % SIZE;
    // printf("%d, %d\n", queue->top, queue->bot);
    if (queue->top == queue->bot)
        queue->tag = 1;
    return 1;
}

int *dequeue(struct Queue *queue)
{
    if (queue->top == queue->bot && !queue->tag)
        return NULL;
    static int *ptr;
    ptr = &queue->data[queue->top];
    queue->top = (queue->top + 1) % SIZE;
    queue->tag = 0;
    return ptr;
}

int main()
{
    int data, *temp;
    char command[50];
    struct Queue queue;
    queue.top = 0;
    queue.bot = 0;
    queue.tag = 0;
    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "enqueue") == 0)
        {
            printf("Please input a integer data:");
            scanf("%d", &data);
            if (enqueue(&queue, data) == 1)
            {
                printf("Successfully enqueue data %d into queue.\n", queue.data[queue.bot - 1 < 0 ? SIZE - 1 : queue.bot - 1]);
            }
            else
            {
                printf("Failed to enqueue data into queue.\n");
            }
        }
        else if (strcmp(command, "dequeue") == 0)
        {
            temp = dequeue(&queue);
            if (temp == NULL)
            {
                printf("Failed to dequeue a data from queue.\n");
            }
            else
            {
                printf("Dequeue data %d from queue.\n", *temp);
            }
        }
    }
}