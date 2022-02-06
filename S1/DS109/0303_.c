// Description

// 請完成函數 enqueue 跟函數 dequeue

// enqueue 會把 data 放進 queue 的頂端，如果成功回傳 1 ，如果失敗回傳 -1 。

// dequeue 會從 queue 的底端拿一筆資料出來，如共成功就回傳指向該資料的指標，如果失敗就回傳 NULL 指標

// Please finish function enqueue and dequeue

// Function enqueue will insert the data from the top of queue and return 1 on success, return -1 if not.

// Function dequeue will remove one data from the bottom of queue and return a pointer point the data, return NULL if there are on data.

// 如果你完成這兩個函數，你可以拿到100 分

// You can get 100 point if you finish this two function.

#include <stdio.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Queue
{
    struct Node *top, *bot;
};

int enqueue(struct Queue *queue, int data)
{
}

int *dequeue(struct Queue *queue)
{
}

int main()
{
    int data, *temp;
    char command[50];
    Queue queue;
    queue.top = NULL;
    queue.bot = NULL;
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
                printf("Successfully enqueue data %d into queue.\n");
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
