// Description

// 請完成 addElement，unions，intersection，equivalent 這四個函數

// addElement 會在集合中增加一個整數的元素，成功的時候回傳真，失敗的時候回傳假。

// unions 會將 兩個集合做聯集的運算，然後將結果回傳。

// intersection 會將 兩個集合做交集的運算，然後將結果回傳。

// equivalent 會判斷兩個集合是否相等，如果相等就回傳真，不相等就回傳假。

// Please finish four function addElement, unions, intersection and equivalent.

// Function addElement will add an element to the set, return true on success and false on not.

// Function unions union two set and return the result.

// Function intersection intersect two set and return the result.

// Function equivalent return true if two set have the same element, return false if not.

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Set
{
    struct Node *element;
};

int addElement(struct Set *set, int e)
{
}

Set *unions(Set *a, Set *b)
{
}

Set *intersetcions(Set *a, Set *b)
{
}

int equivalent(Set *a, Set *b)
{
}

int main()
{
    struct Set *a = (struct Set *)malloc(sizeof(struct Set));
    struct Set *b = (struct Set *)malloc(sizeof(struct Set));
    struct Set *c;
    struct Node *cur;

    addElement(a, 1);
    addElement(a, 2);
    addElement(a, 3);
    addElement(b, 3);
    addElement(b, 4);
    addElement(b, 5);
    addElement(b, 5);

    c = unions(a, b);
    cur = c->element;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    c = intersetcions(a, b);
    cur = c->element;
    while (cur != NULL)
    {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    if (equivalent(a, b) == 0)
        printf("Not equivalent.\n");
    else
        printf("Equivalent!\n");
}
