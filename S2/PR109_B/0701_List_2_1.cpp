// Description

// 假定05-1已經完成。請完成以下 2 個用來管理ListNode指標的 class。

// // 可存取內容的
// class ListNodePointer {
//     ListNodePointer(ListNode *p = nullptr) { /* 初始化內容 */ }
//     ListNodePointer(const ListNodePointer &p) { /* copy constructure */ }
//     bool operator == (const ListNodePointer &p) const {}
//     bool operator != (const ListNodePointer &p) const {}
//     ListNodePointer& operator ++ () { /* 指向 next，prefix 版 */ }
//     ListNodePointer operator ++ (int) { /* 指向 next, suffix 版 */ }
//     ListNodePointer& operator -- () { /* 指向 prev，prefix 版 */ }
//     ListNodePointer operator -- (int) { /* 指向 prev, suffix 版 */ }
//     int& operator * () { /* 存取 ListNodePointer 指向的 node 的 data */ }
// };
// // 唯讀的
// class ListNodeCPointer {
//     ListNodeCPointer(const ListNode *p = nullptr) { /* 初始化內容 */ }
//     ListNodeCPointer(const ListNodeCPointer &p) { /* copy constructure */ }
//     ListNodeCPointer(const ListNodePointer &p) { /* from ListNodePointer */ }
//     bool operator == (const ListNodeCPointer &p) const {}
//     bool operator != (const ListNodeCPointer &p) const {}
//     ListNodeCPointer& operator ++ () { /* 指向 next，prefix 版 */ }
//     ListNodeCPointer operator ++ (int) { /* 指向 next, suffix 版 */ }
//     ListNodeCPointer& operator -- () { /* 指向 prev，prefix 版 */ }
//     ListNodeCPointer operator -- (int) { /* 指向 prev, suffix 版 */ }
//     const int& operator * () { /* 存取 ListNodePointer 指向的 node 的 data */ }
// };
#include "0501_List_1_1.cpp"
#include "0502_List_1_2.cpp"
// 可存取內容的
class ListNodePointer
{
public:
    ListNodePointer(ListNode *p = nullptr) : ptr(p)
    { /* 初始化內容 */
    }
    ListNodePointer(const ListNodePointer &p) : ptr(p.ptr)
    { /* copy constructure */
    }
    bool operator==(const ListNodePointer &p) const
    {
        return ptr == p.ptr;
    }
    bool operator!=(const ListNodePointer &p) const
    {
        return ptr != p.ptr;
    }
    ListNodePointer &operator++()
    {
        /* 指向 next，prefix 版 */
        ptr = ptr->next;
        return *this;
    }
    ListNodePointer operator++(int)
    {
        /* 指向 next, suffix 版 */
        ListNodePointer t(*this);
        ptr = ptr->next;
        return t;
    }
    ListNodePointer &operator--()
    {
        /* 指向 prev，prefix 版 */
        ptr = ptr->prev;
        return *this;
    }
    ListNodePointer operator--(int)
    {
        /* 指向 prev, suffix 版 */
        ListNodePointer t(*this);
        ptr = ptr->prev;
        return t;
    }
    int &operator*()
    {
        /* 存取 ListNodePointer 指向的 node 的 data */
        return ptr->data;
    }

    ListNode *ptr;
};

// 唯讀的
class ListNodeCPointer
{
public:
    ListNodeCPointer(const ListNode *p = nullptr) : ptr(p)
    { /* 初始化內容 */
    }
    ListNodeCPointer(const ListNodeCPointer &p) : ptr(p.ptr)
    { /* copy constructure */
    }
    ListNodeCPointer(const ListNodePointer &p) : ptr(p.ptr)
    { /* from ListNodePointer */
    }
    bool operator==(const ListNodeCPointer &p) const
    {
        return ptr == p.ptr;
    }
    bool operator!=(const ListNodeCPointer &p) const
    {
        return ptr != p.ptr;
    }
    ListNodeCPointer &operator++() /* 指向 next，prefix 版 */
    {
        ptr = ptr->next;
        return *this;
    }
    ListNodeCPointer operator++(int) /* 指向 next, suffix 版 */
    {
        ListNodeCPointer t(*this);
        ptr = ptr->next;
        return t;
    }
    ListNodeCPointer &operator--() /* 指向 prev，prefix 版 */
    {
        ptr = ptr->prev;
        return *this;
    }
    ListNodeCPointer operator--(int) /* 指向 prev, suffix 版 */
    {
        ListNodeCPointer t(*this);
        ptr = ptr->prev;
        return t;
    }
    const int &operator*() /* 存取 ListNodePointer 指向的 node 的 data */
    {
        return ptr->data;
    }

    const ListNode *ptr;
};