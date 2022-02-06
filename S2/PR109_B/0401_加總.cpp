// Description

// 請設計一個 template function 可用於加總 Array 中的資料。 該 function 將定義如下：

// template <typename T>
// T sum(T arr[], int len)
// 你可以確信輸入的資料都支援+和+=。請以左優先([a, b, c, d] => ((a + b) + c) + d)的順序計算出加總後的結果並回傳。

template <typename T>
T sum(T *arr, int len)
{
    if (len == 1)
    {
        return *arr;
    }
    return sum(arr, len - 1) + arr[len - 1];
}