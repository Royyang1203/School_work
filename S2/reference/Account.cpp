#include <iostream>
using namespace std;

class Account{
public:
    int balance=0;
    Account operator ++(); //prefix
    Account operator ++(int); //postfix
    void operator =(const Account& amount2);
    friend const Account operator +(const Account& amount1, const Account& amount2);
    friend const Account operator -(const Account& amount1, const Account& amount2);
    friend ostream& operator <<(ostream& outputStream, const Account& amount);
    friend istream& operator >>(istream& inputStream, Account& amount);
};


int main(void){
    Account a,b,c,yourAccount;
    a.balance=5;
    b.balance=10;

    cout<<"a++:"<<(a++).balance<<endl;
    cout<<"after a++:"<<a.balance<<endl;
    /*
    cout<<"++a:"<<(++a).balance<<endl;
    cout<<"after ++a:"<<a.balance<<endl;
    */
    a=b;
    c=a+b;

    cout<<"a:"<<a<<endl<<"b:"<<b<<endl<<"c:"<<c<<endl;

    cout<<"Please input your balance: ";
    cin>>yourAccount;
    cout<<yourAccount;

    return 0;
}

Account Account::operator++() //prefix
{
    balance++;
    Account temp_account;
    temp_account.balance=balance;

    return temp_account;
}

Account Account::operator++(int ignoreMe) //postfix
{
    int temp1=balance;
    balance++;
    Account temp_account;
    temp_account.balance=temp1;

    return temp_account;
}

void Account::operator =(const Account& amount2)
{
    balance=amount2.balance;
}


const Account operator +(const Account& amount1, const Account& amount2)
{
    int temp_balance=amount1.balance+amount2.balance;
    Account temp_account;
    temp_account.balance=temp_balance;
    return temp_account;
}

const Account operator -(const Account& amount1, const Account& amount2)
{
    int temp_balance=amount1.balance-amount2.balance;
    Account temp_account;
    temp_account.balance=temp_balance;
    return temp_account;
}

ostream& operator <<(ostream& outputStream, const Account& amount){
    outputStream << amount.balance;
    return outputStream;
}

istream& operator >>(istream& inputStream, Account& amount){
    int amount_balance;
    inputStream >> amount_balance;
    amount.balance=amount_balance;
    return inputStream;
}
