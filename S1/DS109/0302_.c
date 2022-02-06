// Description

// 請完成函數 push 跟函數 pop

// push 這個函數會把 data push 進 stack 裡，如果成功會回傳 1 ，如果失敗會回傳 -1

// pop 會從 stack 裡 pop 最上面的資料出來，如果成功就回傳指向該資料的指標，如果失敗就回傳 NULL

// Please finish two function push and pop

// Function push will push the data into stack and return 1 if success, return -1 if not.

// Function pop will pop the top data from stack and return a pointer point to the data, return NULL if there is no data.

// 如果你成功的完成了指定的函數，你可以得到100分

// You can get 100 point if finish this two function.

#include <stdio.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Stack
{
    struct Node *head, *top;
};

int push(struct Stack *stack, int data)
{
}

int *pop(struct Stack *stack)
{
}

int main()
{
    int data, *temp;
    char command[50];
    struct Stack stack;
    stack.head = NULL;
    stack.top = NULL;
    while (1)
    {
        scanf("%s", command);
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "push") == 0)
        {
            printf("Please input a integer data:");
            scanf("%d", &data);
            if (push(&stack, data) == 1)
            {
                printf("Successfully push data %d into stack.\n");
            }
            else
            {
                printf("Failed to push data into stack.\n");
            }
        }
        else if (strcmp(command, "pop") == 0)
        {
            temp = pop(&stack);
            if (temp == NULL)
            {
                printf("Failed to pop a data from stack.\n");
            }
            else
            {
                printf("Pop data %d from stack.\n", *temp);
            }
        }
    }
}