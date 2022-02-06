// Description
// 請完成樣板中的三種排序函數，泡沫排序、選擇排序、插入排序。

// Please finish the three sorting function in template, bubble sort, selection sort and insertion sort.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

struct Node
{
    int data;
    struct Node *pre, *next;
};

void bubbleSort(struct Node **head)
{
}

void selectionSort(struct Node **head)
{
}

void insertionSort(struct Node **head)
{
}

int main()
{
    int j;
    struct Node *head, *buf, *cur;

    srand(time(NULL));

    head = NULL;
    for (j = 0; j < SIZE; j++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand();
        buf->next = head;
        buf->pre = NULL;
        if (head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    bubbleSort(&head);

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    head = NULL;
    for (j = 0; j < SIZE; j++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand();
        buf->next = head;
        buf->pre = NULL;
        if (head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    selectionSort(&head);

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    head = NULL;
    for (j = 0; j < SIZE; j++)
    {
        buf = (struct Node *)malloc(sizeof(struct Node));
        buf->data = rand();
        buf->next = head;
        buf->pre = NULL;
        if (head != NULL)
            head->pre = buf;
        head = buf;
    }

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");

    insertionSort(&head);

    cur = head;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}
