// Description

// 假定7-2所需的所有部件已經完成了。 在 C++ 中，對於有提供 begin(), end() 兩個方法的容器都可以使用 for each 迴圈存取其內容。

// 請使用 for each 或7-1, 7-2 定義的 class，多載下列兩個 operators 並完成其指定的功能。

// // 列印 list 中所有的 data，並以 ' ' 隔開，但頭尾都不含空白。
// std::ostream& operator << (std::ostream& out, const IterableList &list) {
// }

// // 將 list 中的每個 data 都加上 num
// IterableList& operator += (IterableList &list, int num) {
// }

#include "0702_List_2_2.cpp"

std::ostream &operator<<(std::ostream &out, const IterableList &list)
{
    for (ListNodeCPointer a = list.begin(); a != list.end(); a++)
    {
        if (a != list.begin())
        {
            out << " ";
        }
        out << *a;
    }
    return out;

    // Way2
    bool first = true;
    for (int data : list)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            out << " ";
        }
        out << data;
    }
    return out;
}

IterableList &operator+=(IterableList &list, int num)
{
    for (int &data : list)
    {
        data += num;
    }
    return list;
}