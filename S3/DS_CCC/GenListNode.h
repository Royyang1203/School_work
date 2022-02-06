#ifndef GEN_LIST_NODE_H_

#define GEN_LIST_NODE_H_

#include <iostream>
#include <string>
#include <strstream>

template <class T>
struct GenListNode //廣義表結點類定義
{
    int utype;             //標誌域，utype={0,1,2}
    GenListNode<T> *tlink; //尾指針域，tlink
    union                  //信息域，info
    {
        int ref;               //當utype=0時，該信息域存放引用計數(ref)
        T value;               //當utype=1時，該信息域存放數據值(value)
        GenListNode<T> *hlink; //當utype=2時，該信息域存放指向子表表頭的指針(hlink)
    } info;
    //構造函數
    GenListNode() : utype(0), tlink(NULL), info.ref(0) {}
    //拷貝構造函數
    GenListNode(const GenListNode<T> &RL)
    {
        utype = RL.utype;
        tlink = RL.tlink;
        info = RL.info;
    }
};

#endif /* GEN_LIST_NODE_H_ */