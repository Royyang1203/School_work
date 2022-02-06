// UVa 508

// Description

// Samuel F. B. Morse is best known for the coding scheme that carries his name. Morse code is still used in international radio communication. The coding of text using Morse code is straightforward. Each character (case is insignificant) is translated to a predefined sequence of dits and dahs (the elements of Morse code). Dits are represented as periods (‘.’) and dahs are represented as hyphens or minus signs (‘-’). Each element is transmitted by sending a signal for some period of time. A dit is rather short, and a dah is, in perfectly formed code, three times as long as a dit. A short silent space appears between elements, with a longer space between characters. A still longer space separates words. This dependence on the spacing and timing of elements means that Morse code operators sometimes do not send perfect code. This results in difficulties for the receiving operator, but frequently the message can be decoded depending on context.In this problem we consider reception of words in Morse code without spacing between letters.Without the spacing, it is possible for multiple words to be coded the same. For example, if the message “dit dit dit” were received, it could be interpreted as “EEE”, “EI”, “IE” or “S” based on the coding scheme shown in the sample input. To decide between these multiple interpretations, we assume a particular context by expecting each received word to appear in a dictionary.For this problem your program will read a table giving the encoding of letters and digits into Morse code, a list of expected words (context), and a sequence of words encoded in Morse code (morse). These morse words may be flawed. For each morse word, your program is to determine the matching word from context, if any. If multiple words from context match morse, or if no word matches perfectly, your program will display the best matching word and a mismatch indicator.If a single word from context matches morse perfectly, it will be displayed on a single line, by itself. If multiple context words match morse perfectly, then select the matching word with the fewest characters. If this still results in an ambiguous match, any of these matches may be displayed. If multiple context words exist for a given morse, the first matching word will be displayed followed byan exclamation point (‘!’).We assume only a simple case of errors in transmission in which elements may be either truncated from the end of a morse word or added to the end of a morse word. When no perfect matches for morse are found, display the word from context that matches the longest prefix of morse, or has the fewest extra elements beyond those in morse. If multiple words in context match using these rules, display the first word appeared . Words that do not match perfectly are displayed with a question mark (‘?’) suffixed.The input data will only contain cases that fall within the preceding rules.

// Input
// The Morse code table will appear first and consists of lines each containing an uppercase letter or a digit C, zero or more blanks, and a sequence of no more than six periods and hyphens giving the Morse code for C. Blanks may precede or follow the items on the line. A line containing a single asterisk (‘*’),possibly preceded or followed by blanks, terminates the Morse code table. You may assume that there will be Morse code given for every character that appears in the context section.The context section appears next, with one word per line, possibly preceded and followed by blanks.Each word in context will contain no more than ten characters. No characters other than upper case letters and digits will appear. The red will be at most 100 context words. A line containing only a single asterisk (‘*’), possibly preceded or followed by blanks, terminates the context section.The remainder of the input contains morse words separated by blanks or end-of-line characters. Aline containing only a single asterisk (“*”), possibly preceded or followed by blanks, terminates the input. No morse word will have more than eighty (80) elements.

// Output
// For each input morse word, display the appropriate matching word from context followed by an exclamation mark (‘!’) or question mark (‘?’) if appropriate. Each word is to appear on a separate lines tarting in column one.

// Sample Input 1

// A .-
// B -...
// C -.-.
// D -..
// E .
// F ..-.
// G --.
// H ....
// I ..
// J .---
// K -.-
// L .-..
// M --
// N -.
// O ---
// P .--.
// Q --.-
// R .-.
// S ...
// T -
// U ..-
// V ...-
// W .--
// X -..-
// Y -.--
// Z --..
// 0 ------
// 1 .-----
// 2 ..---
// 3 ...--
// 4 ....-
// 5 .....
// 6 -....
// 7 --...
// 8 ---..
// 9 ----.
// *
// AN
// EARTHQUAKE
// EAT
// GOD
// HATH
// IM
// READY
// TO
// WHAT
// WROTH
// *
// .--.....-- .....--....
// --.----.. .--.-.----..
// .--.....-- .--.
// ..-.-.-....--.-..-.--.-.
// ..-- .-...--..-.--
// ---- ..--
// *
// Sample Output 1

// WHAT
// HATH
// GOD
// WROTH?
// WHAT
// AN
// EARTHQUAKE
// EAT!
// READY
// TO
// EAT!

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<char, string> morse;

unordered_map<string, vector<string>> context;

int main()
{
    char c;
    string s;

    //先將基礎摩斯密碼與對應的Key值存在一起
    while (cin >> c && c != '*')
    {
        cin >> s;
        morse[c] = s;
    }

    //將單字以對應的摩斯密碼為Key值存成辭典，有可能同一組摩斯密碼可以解碼成兩個單字
    while (cin >> s && s != "*")
    {
        string t;
        for (char c : s)
        {
            t += morse[c];
        }
        context[t].push_back(s);
    }

    while (cin >> s && s != "*")
    {

        //如果在辭典中可以找到符合 s 的Key值，直接輸出辭典裡的對應單字，如果兩個以上單字在這個節點中，則多輸出一個 "!"
        if (context.count(s))
        {
            cout << context[s].front();
            if (context[s].size() > 1)
                cout << "!";
            cout << endl;
            continue;
        }

        //在辭典中對每個節點的Key值和 s 做比較，找出最相似的
        //令 n 為相似度，越小越像，如果可以將辭典中的Key值加上一些字符後匹配 s ，
        //則 n 為Key值長度減掉 s 的長度，此時兩字串比較的長度為 i ，會和 s 的長度相等
        //如果可以將辭典中的Key值刪除一些字符後匹配 s ，則 n 為 s 的長度減掉 i
        else
        {
            map<int, string> temp;
            for (auto t : context)
            {
                string str = t.first;
                for (int i = s.size(); i > 0; --i)
                {
                    if (s.compare(0, i, str, 0, i) == 0)
                    {
                        int n;
                        if (i == s.size())
                            n = str.size() - s.size();
                        else
                            n = s.size() - i;
                        //cout << n << t.first << t.second.front() << endl;
                        temp[n] = context[str].front();
                        break;
                    }
                }
            }
            cout << temp.begin()->second << "?" << endl;
        }
    }
}

// _____________________________________________________________________________

// #include <iostream>
// #include <cstring>
// #include <algorithm>
// #include <vector>
// #include <map>
// #include <unordered_map>
// using namespace std;

// unordered_map<char, string> morse;
// unordered_map<string, vector<string>> context;

// // a是b的前缀
// bool isPrefixOf(const string &a, const string &b)
// {
//     // a是b的前缀：a长度小于b 且 b的前a.size()个字符与a相同
//     return a.size() < b.size() && b.compare(0, a.size(), a) == 0;
// }

// void solve(string m)
// {
//     if (context.count(m))
//     {
//         auto v = context[m];
//         cout << v.front();
//         if (v.size() > 1)
//             cout << "!";
//         cout << endl;
//         return;
//     }

//     map<int, string> ans;
//     for (auto p : context)
//     {
//         string cm = p.first;
//         if (isPrefixOf(m, cm))
//             ans[(int)(cm.size() - m.size())] = p.second.front();
//         else if (isPrefixOf(cm, m))
//             ans[(int)(m.size() - cm.size())] = p.second.front();
//     }
//     cout << ans.begin()->second << "?" << endl;
// }

// int main()
// {
//     ios::sync_with_stdio(false);
//     string C, M;
//     while (cin >> C && C != "*")
//     {
//         cin >> M;
//         morse[C[0]] = M;
//     }

//     while (cin >> C && C != "*")
//     {
//         M.clear();
//         for (auto c : C)
//             M += morse[c];
//         context[M].push_back(C);
//     }

//     while (cin >> M && M != "*")
//         solve(M);

//     return 0;
// }
