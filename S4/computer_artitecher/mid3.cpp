#include <stdio.h> /*包含標頭檔案*/
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 1024 /*陣列長度*/

int insert_operand(int *operand, int *top_num, int num) /*資料壓入資料棧*/
{
    (*top_num)++;
    operand[*top_num] = num; /*儲存資料*/

    return 0; /*正常退出*/
}

int insert_oper(char *oper, int *top_oper, char ch) /*操作符壓入符號棧*/
{
    (*top_oper)++;
    oper[*top_oper] = ch; /*儲存操作符*/
    return 0;             /*正常退出*/
}

int compare(char *oper, int *top_oper, char ch) /*比較操作服優先順序*/
{
    if ((oper[*top_oper] == '-' || oper[*top_oper] == '+') /*判斷當前優先順序是否比棧頂操作符優先順序高*/
        && (ch == '*' || ch == '/' || ch == '%' || ch == '^'))
    {
        return 0; /*操作符壓入棧*/
    }
    else if ((oper[*top_oper] == '*' || oper[*top_oper] == '/' || oper[*top_oper] == '%' || oper[*top_oper] == '^') /*判斷當前優先順序是否比棧頂操作符優先順序高*/
             && ch == '^')
    {
        return 0; /*操作符壓入棧*/
    }
    else if (*top_oper == -1 || ch == '(' || (oper[*top_oper] == '(' && ch != ')')) /*判斷操作符棧是否為空；棧頂操作   符是否為'('*/
    {
        return 0; /*操作符壓入棧*/
    }
    else if (oper[*top_oper] == '(' && ch == ')') /*判斷括號內的表示式是否計算完畢*/
    {
        // cout << "1" << endl;
        return 1; /*對（）進行處理*/
    }
    else
    {
        // cout << "-1" << endl;
        return -1; /*進行操作符的運算*/
    }
}

void deal_date(int *operand, char *oper, int *top_num, int *top_oper) /*進行資料運算*/
{
    int num_1 = operand[*top_num]; /*取出資料棧中兩個資料*/
    int num_2 = operand[*top_num - 1];

    int value = 0;

    if (oper[*top_oper] == '+') /*加法操作*/
    {
        value = num_1 + num_2;
    }

    else if (oper[*top_oper] == '-') /*減法操作*/
    {
        value = num_2 - num_1;
    }

    else if (oper[*top_oper] == '*') /*乘法操作*/
    {
        value = num_2 * num_1;
    }

    else if (oper[*top_oper] == '/') /*除法操作*/
    {
        value = num_2 / num_1;
    }

    else if (oper[*top_oper] == '%') /*取餘數*/
    {
        value = num_2 % num_1;
    }
    else if (oper[*top_oper] == '^')
    {
        value = pow(num_2, num_1);
    }
    (*top_num)--;              /*將資料棧頂下移一位*/
    operand[*top_num] = value; /*將得到的值壓入資料棧*/
    (*top_oper)--;             /*將操作符棧頂下移一位*/
}

int main()
{
    int operand[MAX_SIZE] = {0}; /*資料棧，初始化*/
    int top_num = -1;

    char oper[MAX_SIZE] = {0}; /*操作符棧，初始化*/
    int top_oper = -1;
    char *str = (char *)malloc(sizeof(char) * 100); /*獲取表示式(不帶＝)*/

    scanf("%s", str);
    char *temp;
    char dest[MAX_SIZE];

    int num = 0;
    int i = 0;

    while (*str != '\0')
    {
        temp = dest;
        while (*str >= '0' && *str <= '9') /*判斷是否是資料*/
        {
            *temp = *str;
            str++;
            temp++;
        } /*遇到符號退出*/

        if (*str != '(' && *(temp - 1) != '\0') /*判斷符號是否為'('*/
        {
            *temp = '\0';
            num = atoi(dest);                       /*將字串轉為數字*/
            insert_operand(operand, &top_num, num); /*將資料壓入資料棧*/
        }

        while (1)
        {
            i = compare(oper, &top_oper, *str); /*判斷操作符優先順序*/
            if (i == 0)
            {
                insert_oper(oper, &top_oper, *str); /*壓入操作符*/
                break;
            }

            else if (i == 1) /*判斷括號內的表示式是否結束*/
            {
                --top_oper;
                str++;
            }

            else if (i == -1) /*進行資料處理*/
            {
                deal_date(operand, oper, &top_num, &top_oper);
            }
        }
        str++; /*指向表示式下一個字元*/
    }

    printf("num = %d\n", operand[0]); /*輸出結果*/
    return 0;                         /*正常退出*/
}