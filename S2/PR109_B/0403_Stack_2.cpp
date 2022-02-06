// Description

// 請實作02-3中的 Stack，但請於

// 在 stack 已滿又 push 時， throw 帶有錯誤訊息 `Stack is full` 的 out_of_range 例外
// 在 stack 為空又要求 top 時， throw 帶有錯誤訊息 `Stack is empty` 的 out_of_range 例外
// 在 stack 為空又要求 pop 時，throw 帶有錯誤訊息 `Stack is empty` 的 out_of_range 例外

#include <stdexcept>

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

public:
    bool is_empty() const
    {
        if (_size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    bool is_full() const
    {
        if (_size == 16)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

public:
    int size() const
    {
        return _size;
    }

public:
    int top() const
    {
        if (_size == 0)
        {
            throw std::out_of_range("Stack is empty");
        }
        else
        {
            return _data[_size - 1];
        }
    }

public:
    bool push(int val)
    {
        if (_size == 16)
        {
            throw std::out_of_range("Stack is full");
        }
        else
        {
            _data[_size] = val;
            _size++;
            return true;
        }
    }

public:
    bool pop()
    {
        if (_size == 0)
        {
            throw std::out_of_range("Stack is empty");
        }
        else
        {
            _size--;
            return true;
        }
    }
};