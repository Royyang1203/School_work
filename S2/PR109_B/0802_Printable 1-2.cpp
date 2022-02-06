// Description

// 有一 abstract class 定義如下：

// class Printable {
// public:
//     virtual std::string toString() const = 0;
// };

// 請透過運算子複載，令所有實作 Printable 的 class 之物件都可以透過 std::ostream 來輸出其轉成字串的內容。

// ----------------------------------

std::ostream &operator<<(std::ostream &os, const Printable &that)
{
    os << that.toString();
    return os;
}

// _______________________________________________________________________________

// #include "0801_點 3, Printable 1-1.cpp"

// #include <stdexcept>
// #include <vector>
// class PrintableArray
// {
// public:
//     PrintableArray() = default;
//     PrintableArray(size_t cap) : n(cap) {}
//     ~PrintableArray()
//     {
//         v.clear();
//     }
//     bool full() const
//     {
//         return v.size() >= n;
//     }
//     bool empty() const
//     {
//         return v.empty();
//     }
//     size_t size() const
//     {
//         return v.size();
//     }
//     void append(Printable *item)
//     {
//         if (v.size() >= n)
//             throw std::out_of_range("The array is full");
//         v.push_back(item);
//     }
//     Printable *operator[](size_t index)
//     {
//         return v.at(index);
//     }
//     const Printable *const operator[](size_t index) const
//     {
//         return v.at(index);
//     }
//     std::string getSeperator() const
//     {
//         return seperator;
//     }
//     void setSeperator(std::string s)
//     {
//         seperator = s;
//     }
//     friend std::ostream &operator<<(std::ostream &out, const PrintableArray &arr);

// private:
//     std::vector<Printable *> v;
//     size_t n = 5;
//     std::string seperator = " ";
// };

// std::ostream &operator<<(std::ostream &out, const PrintableArray &arr)
// {
//     for (size_t i = 0; i < arr.n; ++i)
//     {
//         out << arr[i]->toString();
//         if (i != arr.n - 1)
//             out << arr.seperator;
//     }
//     return out;
// }

// using namespace std;

// int main()
// {
//     PPoint2D a1(2, 3), b1(3, 4), c1(a1);
//     PrintableArray arr(3);

//     arr.append(&a1);
//     arr.append(&b1);
//     arr.append(&c1);
//     arr[0] = &a1;

//     const PrintableArray arr2(arr);

//     Printable *ptr = arr[1];

//     ptr->setX(88);
//     cout << ptr->toString();
//     //cout << arr.size();
//     //arr.append(&c1);
//     arr.setSeperator("##\n");
//     //cout << arr.getSeperator();
//     cout << arr;
// }
