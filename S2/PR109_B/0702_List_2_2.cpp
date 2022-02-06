// Description

// 假定05-2,07-1都已經完成了。 05-2 中的 data members 在實作中都被改為 protected。

// 請設計一個class IterableList。此 class 將繼承 List，並多了以下的功能：

// IterableList(): 呼叫 List 的 default constructure 來進行初使化
// ListNodePointer begin(): 回傳第一筆資料的指標。
// ListNodeCPointer begin() const: 上者的唯讀版。
// ListNodePointer end(): 回傳資料結尾 (nullptr)
// ListNodeCPointer end() const: 上者的唯讀版。

#include "0701_List_2_1.cpp"

class IterableList : public List
{
public:
    IterableList() : List() {}
    ListNodePointer begin() { return ListNodePointer(head); }
    ListNodePointer end() { return ListNodePointer(); }
    ListNodeCPointer begin() const { return ListNodeCPointer(head); }
    ListNodeCPointer end() const { return ListNodeCPointer(); }
};