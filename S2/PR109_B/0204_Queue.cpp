// Description

// Queue 是一個先進後出(FIFO, First In First Out)的儲存結構。

// 現在有一個已經實作好的 Linked-list 節點結構定義如下：

struct QueueNode
{
    int data;
    QueueNode *next;
};
// 請利用 Linked-list 來完成 Queue 的實作。含有 member functions 如下：

// int size() const: 回傳 Queue 中保存的資料數。
// bool is_empty() const: 若 Queue 中沒有保存資料，回傳true；否則回傳false。
// void enqueue(int val): 將 val 插入於 tail 的後面，並維護 head 和 tail。
// void dequeue(): 將 haed 指向的資料結點刪除，並維護 head 和 tail。
// int top() const: 回傳下一筆將被 dequeue 的資料。

class Queue
{
private:
    QueueNode *_head = nullptr, *_tail = nullptr;
    int _size = 0;

public:
    int size() const
    {
        return _size;
    }
    bool is_empty() const
    {
        return !_size;
    }
    void enqueue(int val)
    {
        QueueNode *tmp = (QueueNode *)malloc(sizeof(QueueNode));
        tmp->data = val;
        tmp->next = nullptr;
        if (_size == 0)
        {
            _head = _tail = tmp;
        }
        else
        {
            _tail->next = tmp;
            _tail = tmp;
        }
        _size++;
    }
    bool dequeue()
    {
        if (_size > 0)
        {
            _head = _head->next;
            _size--;
            if (_size == 0)
            {
                _head = _tail = nullptr;
            }
            return 1;
        }
        return 0;
    }
    int top() const
    {
        return _head->data;
    }
};