// Description

// 堆疊是一先進先出(FILO, First In Last Out)的儲存結構。

// 請實作一個堆疊類別Stack，最多可以儲存16個int，且含有以下 public member functions:

// void clear(): 刪除 stack 中所有的資料。
// bool is_empty() const: 若 Stack 中無資料，回傳true, 否則回傳false。
// bool is_full() const: 若 Stack 無法再存更多資料，回傳true，否則回傳false。
// int size() const: 回傳 Stack 中儲存的資料數。
// int top() const: 回傳頂端(最後被 push)的資料。
// bool push(int val): 將 val 存入 Stack 中。
// bool pop(): 將頂端資料刪除。

class Stack
{
private:
    int _data[16];
    int _size;

public:
    void clear()
    {
        _size = 0;
    }
    bool is_empty() const
    {
        return !_size;
    }
    bool is_full() const
    {
        return _size == 16;
    }
    int size() const
    {
        return _size;
    }
    int top() const
    {
        if (_size > 0)
            return _data[_size - 1];
    }
    bool push(int val)
    {
        if (!is_full())
        {
            _data[_size++] = val;
            return 1;
        }
        return 0;
    }
    bool pop()
    {
        if (!is_empty())
        {
            --_size;
            return 1;
        }
        return 0;
    }
};