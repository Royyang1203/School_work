// Description

// my_malloc 和 my_free 是功能等價於 malloc 和 free 的 function。請使用 my_malloc 和 my_free 來動態配置陣列並完成如下定義的整數動態陣列：

// class IntArray {
// private:
//     int *data;
//     int cap;
// public:
//     IntArray(int len); // 配置 len 個 int 給 data 並初始化為 0。
//     ~IntArray(); // 歸還所有配置的空間。
//     int size() const; // 回傳現在的陣列大小。
//     int get(int idx) const; // 回傳位於 idx 位置的值。
//     void set(int idx, int val); // 將位於 idx 的值設為 val。
//     void resize(int newSize); // 將陣列大小變更為 newSize 個 int。
// };
// 於 get 和 set 時，若 idx 超出合法的範圍，請丟出帶有 "out of range" 的 invalid_argument 例外。
// 在實作 resize 時，若空間比原本大，則請把新增的部分都初始化為 0；若空間比原本小，則不保留超出新空間的部分。

// #include <iostream>
// #include <stdexcept>
// class IntArray
// {
// private:
//     int *data;
//     int cap;

// public:
//     IntArray(int len) : cap(len)
//     {
//         data = (int *)my_malloc(sizeof(int) * len);
//     }

//     ~IntArray()
//     {
//         my_free(data);
//     }

//     int get(int idx) const
//     {
//         if (idx >= cap)
//             throw std::out_of_range("invalid index");
//         else
//             return data[idx];
//     }

//     void set(int idx, int val)
//     {
//         if (idx >= cap)
//             throw std::out_of_range("invalid index");
//         else
//             data[idx] = val;
//     }

//     int size() const
//     {
//         return cap;
//     }

//     void resize(int new_size)
//     {
//         int *ptr = (int *)my_malloc(sizeof(int) * new_size);
//         for (int i = 0; i < new_size; ++i)
//         {
//             if (i < cap)
//             {
//                 ptr[i] = data[i];
//             }
//             else
//             {
//                 ptr[i] = 0;
//             }
//         }
//         my_free(data);
//         cap = new_size;
//         data = ptr;
//     }
// };

#include <iostream>
#include <stdexcept>
class IntArray
{
private:
    int *data;
    int cap;

public:
    IntArray(int len) : cap(len)
    {
        data = (int *)malloc(sizeof(int) * len);
    }

    ~IntArray()
    {
        free(data);
    }

    int get(int idx) const
    {
        if (idx >= cap)
            throw std::out_of_range("invalid index");
        else
            return data[idx];
    }

    void set(int idx, int val)
    {
        if (idx >= cap)
            throw std::out_of_range("invalid index");
        else
            data[idx] = val;
    }

    int size() const
    {
        return cap;
    }

    void resize(int new_size)
    {
        int *ptr = (int *)malloc(sizeof(int) * new_size);
        for (int i = 0; i < new_size; ++i)
        {
            if (i < cap)
            {
                ptr[i] = data[i];
            }
            else
            {
                ptr[i] = 0;
            }
        }
        free(data);
        cap = new_size;
        data = ptr;
    }
};

int main()
{
    IntArray arr(5);
    arr.set(0, 66);
    arr.set(1, 67);
    arr.set(2, 68);
    arr.set(3, 69);
    arr.set(4, 70);
    for (int i = 0; i < 5; ++i)
        std::cout << arr.get(i) << std::endl;
    arr.resize(4);
    for (int i = 0; i < 4; ++i)
        std::cout << arr.get(i) << std::endl;

    std::cout << arr.size();
}