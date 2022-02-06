#ifndef GEN_LIST_H_

#define GEN_LIST_H_

#include "GenListNode.h"

template <class T>
class GenList
{
private:
    GenListNode<T> *first; //廣義表頭指針

public:
    GenList();  //構造函數
    ~GenList(); //析構函數

public:
    GenListNode<T> *Head();                     //返回表頭元素
    GenListNode<T> *First();                    //返回第一個元素
    GenListNode<T> *Next(GenListNode<T> *elem); //返回表元素elem的直接後繼元素
    GenList<T> *Tail();                         //返回表尾元素
    void Copy(const GenList<T> &R);             //廣義表的複製
    int Length();                               //計算廣義表的長度
    int Depth();                                //計算一個非遞歸廣義表的深度

public:
    template <class T>
    friend std::istream &operator>>(std::istream &is, GenList<T> &L); //輸入廣義表元素的重載操作>>

private:
    GenListNode<T> *Copy(GenListNode<T> *ls);               //複製一個ls指示的無共享非遞歸表
    int Length(GenListNode<T> *ls);                         //求由ls指示的廣義表的長度
    int Depth(GenListNode<T> *ls);                          //計算由ls指示的非遞歸表的深度
    bool Equal(GenListNode<T> *s, GenListNode<T> *t);       //判以s和t爲表頭的兩個表是否相等
    void Remove(GenListNode<T> *ls);                        //釋放以ls爲附加頭結點的廣義表
    void GreateList(std::istream &is, GenListNode<T> *&ls); //從輸入流對象輸入廣義表的字符串描述，建立一個帶附加頭結點的廣義表結構
};

//構造函數
template <class T>
GenList<T>::GenList()
    : first(new GenListNode<T>)
{
    cout << "$ 執行構造函數" << endl;
}

//析構函數
template <class T>
GenList<T>::~GenList()
{
    cout << "$ 執行析構函數" << endl;
    Remove(first);
}

//返回表頭元素
template <class T>
GenListNode<T> *GenList<T>::Head()
{
    return first;
}

//返回第一個元素
template <class T>
GenListNode<T> *GenList<T>::First()
{
    return first->tlink;
}

//返回表元素elem的直接後繼元素
template <class T>
GenListNode<T> *GenList<T>::Next(GenListNode<T> *elem)
{
    return elem->tlink;
}

//返回表尾元素
template <class T>
GenList<T> *GenList<T>::Tail()
{
    if (first->tlink == NULL)
    {
        return NULL;
    }

    GenList<T> *lt;
    lt->first->tlink = Copy(first->tlink->tlink);
    return lt;
}

//廣義表的複製
template <class T>
void GenList<T>::Copy(const GenList<T> &R)
{
    first = Copy(R.first);
}

//計算廣義表的長度
template <class T>
int GenList<T>::Length()
{
    return Length(first);
}

//計算一個非遞歸廣義表的深度
template <class T>
int GenList<T>::Depth()
{
    return Depth(first);
}

//輸入廣義表元素的重載操作>>
template <class T>
std::istream &operator>>(std::istream &is, GenList<T> &L)
{
    return is;
}

//複製一個ls指示的無共享非遞歸表
template <class T>
GenListNode<T> *GenList<T>::Copy(GenListNode<T> *ls)
{
    GenListNode<T> *q = NULL;
    if (ls != NULL)
    {
        q = new GenListNode<T>; //處理當前的結點q
        q->utype = ls->utype;   //複製結點類型
        switch (ls->utype)      //根據utype傳送信息
        {
        case 0:
        {
            q->info.ref = ls->info.ref; //附加頭結點
            break;
        }
        case 1:
        {
            q->info.value = ls->info.value; //原子結點
            break;
        }
        case 2:
        {
            q->info.hlink = Copy(ls->info.hlink); //表結點
            break;
        }
        default:
        {
            break;
        }
        }
        q->tlink = Copy(ls->tlink); //處理同一層下一結點爲頭的表
    }
    return q;
}

//求由ls指示的廣義表的長度
template <class T>
int GenList<T>::Length(GenListNode<T> *ls)
{
    if (ls != NULL)
    {
        return 1 + Length(ls->tlink);
    }
    else
    {
        return 0;
    }
}

//計算由ls指示的非遞歸表的深度
template <class T>
int GenList<T>::Depth(GenListNode<T> *ls)
{
    if (ls->tlink == NULL)
    {
        return 1;
    }
    GenListNode<T> *temp = ls->tlink;
    int m = 0;
    int n = 0;
    while (temp != NULL)
    {
        if (temp->utype == 2)
        {
            n = Depth(temp->info.hlink);
            if (m < n)
            {
                m = n;
            }
        }
        temp = temp->tlink;
    }
    return m + 1;
}

//判以s和t爲表頭的兩個表是否相等
template <class T>
bool GenList<T>::Equal(GenListNode<T> *s, GenListNode<T> *t)
{
    int x = 0;
    if ((s->tlink == NULL) && (t->tlink == NULL))
    {
        return true;
    }
    if ((s->tlink != NULL) && (t->tlink != NULL) && (s->tlink->utype == t->tlink->utype))
    {
        if (s->tlink->utype == 1)
        {
            x = (s->tlink->info.value == t->tlink->info.value) ? 1 : 0;
        }
        else
        {
            x = Equal(s->tlink->info.hlink, t->tlink->info.hlink);
        }
        if (x == 1)
        {
            return Equal(s->tlink, t->tlink);
        }
    }
    return false;
}

//釋放以ls爲附加頭結點的廣義表
template <class T>
void GenList<T>::Remove(GenListNode<T> *ls)
{
    ls->info.ref--;        //附加頭結點的引用計數減1
    if (ls->info.ref >= 0) //如果減到0
    {
        GenListNode<T> *q;
        while (ls->tlink != NULL) //橫掃表頂層
        {
            q = ls->tlink;     //到第一個結點
            if (q->utype == 2) //遞歸刪除子表
            {
                Remove(q->info.hlink);
                if (q->info.hlink->info.ref <= 0)
                {
                    delete q->info.hlink; //刪除子表附加頭結點
                }
            }
            ls->tlink = q->tlink;
            delete q;
        }
    }
}

//從輸入流對象輸入廣義表的字符串描述，建立一個帶附加頭結點的廣義表結構
template <class T>
void GenList<T>::GreateList(std::istream &is, GenListNode<T> *&ls)
{
}

#endif /* GEN_LIST_H_ */