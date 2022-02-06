// Description

// 請使用 template 語法設計下列 function

// bool same_type(a, b) {
// }
// 如果 a 和 b 同型別會 return true；若否則 return false。

// Input
// NONE

// Output
// NONE

// Sample Input 1

// NONE
// Sample Output 1

// NONE
// Hint

// 同是 2 參數的 template function

// 若 2 參數型別相同，使用 template<typename A> 即可；
// 若 2 參數型別不同，則需使用 template<typename A, typename B>。

// 編譯器是在呼叫時看型別才決定要使用哪一個同名 function 。

template <typename A>
bool same_type(A a, A b)
{
    return true;
}
template <typename A, typename B>
bool same_type(A a, B b)
{
    return false;
}
