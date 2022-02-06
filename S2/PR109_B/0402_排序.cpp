// Description

// 請設計一個 template function 可用於排序 array 中的資料。

// array 中的資料一定可以使用<算子來比較大小。
// 若 array 中有兩個物件一樣大，請不要交換它們的順序。
// 定義如下：

// template <typename T>
// void sort(T arr[], int len);
template <typename T>
void sort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                T t = arr[i];
                for (int k = i; k > j; k--)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = t;
            }
        }
    }
}
