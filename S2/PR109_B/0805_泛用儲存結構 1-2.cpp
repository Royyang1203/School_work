// Description

// 假定08-4中的兩個 class 都已經完成了，現在請你寫一個 function 來判別傳入的實體之型別。

// 所傳入的實體一定是 Stack 或 PriorityQueue 其中之一。若為 Stack 則回傳 1，若為 PriorityQueue 則請回傳 2。

#include "0804_泛用儲存結構 1-1.cpp"

int judge(Container *c)
{
    c->push(2);
    c->push(1);
    return c->top();
}