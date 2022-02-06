#include <iostream>
#include <queue>
using namespace std;
class Client
{
public:
    int id, start, enter, dur;
    Client() {}
    Client(int number, int start_time, int during_time);
    friend ostream &operator<<(ostream &out, const Client &temp)
    {
        out << temp.id << " " << temp.start << " " << temp.dur;
        return out;
    }
};
Client::Client(int number, int start_time, int during_time)
{
    id = number;
    start = start_time;
    dur = during_time;
    enter = -1;
}
class information_in_shopsysteam
{
public:
    information_in_shopsysteam() {}
    information_in_shopsysteam(char e, int ID, int d, int counter, int en);
    int id, dur, counter_number, enter;
    char event;
};
information_in_shopsysteam::information_in_shopsysteam(char e, int ID, int d, int counter, int en)
{
    event = e;
    id = ID;
    dur = d;
    counter_number = counter;
    enter = en;
}
class shop_system : public Client, information_in_shopsysteam
{
public:
    queue<Client> line;
    queue<information_in_shopsysteam> information;
    queue<Client> counter[10];
    int counter_number, client_number, time, leave_client;
    shop_system() {}
    shop_system(int n, int m);
    void system();
    void print();
    void print_information();
    void E();
    void W();
    void O(int number);
    void L(int number);
};
shop_system::shop_system(int n, int m)
{
    client_number = n;
    counter_number = m;
    time = 0;
    leave_client = 0;
}
void shop_system::system()
{
    int ID, start_time, during_time;
    for (int i = 0; i < client_number; i++)
    {
        cin >> ID >> start_time >> during_time;
        Client temp(ID, start_time, during_time);
        line.push(temp);
    }
    // print();
    while (1)
    {
        E();
        for (int i = 0; i < counter_number; i++)
        {
            if (counter[i].size() != 0)
                L(i);
        }

        if (information.size() != 0)
            print_information();
        time++;
        if (leave_client == client_number)
            break;
    }
}
void shop_system::E()
{
    if (time == line.front().start)
    {
        information_in_shopsysteam temp('E', line.front().id, line.front().dur, -1, -1);
        information.push(temp);
        W();
    }
}
void shop_system::W()
{
    Client tmp = line.front();
    line.pop();
    int min = counter[0].size(), number = 0;
    for (int i = 0; i < counter_number; i++)
    {
        int m = counter[i].size();
        if (m < min)
        {
            min = m;
            number = i;
        }
    }
    counter[number].push(tmp);
    information_in_shopsysteam temp('W', tmp.id, -1, number + 1, -1);
    information.push(temp);

    if (counter[number].front().id != temp.id)
        L(number);

    else if (counter[number].front().id == temp.id)
        O(number);
}
void shop_system::L(int number)
{
    if (counter[number].front().enter == time)
    {
        information_in_shopsysteam temp('L', counter[number].front().id, -1, number + 1, -1);
        information.push(temp);
        counter[number].pop();
        O(number);
        leave_client++;
    }
}
void shop_system::O(int number)
{
    if (counter[number].size() == 0)
        return;
    for (int i = 0; i < counter_number; i++)
        if (counter[i].size() != 0 && (counter[i].front().enter == -1))
            counter[i].front().enter = time + counter[i].front().dur;

    Client temp = counter[number].front();

    information_in_shopsysteam tmp('O', temp.id, -1, number + 1, temp.enter);
    information.push(tmp);
}
void shop_system::print_information() ///輸出資訊
{
    cout << "Time " << time << ": ";
    while (information.size())
    {
        if (information.front().event == 'E')
            cout << "C" << information.front().id << ">>>(D:" << information.front().dur << ")|";
        else if (information.front().event == 'W')
            cout << "C" << information.front().id << "-->"
                 << "Q" << information.front().counter_number << "|";
        else if (information.front().event == 'L')
            cout << "C" << information.front().id << "<--Q" << information.front().counter_number << "|";
        else if (information.front().event == 'O')
            cout << "C" << information.front().id << "@Q" << information.front().counter_number << " (ETL:" << information.front().enter << ")|";
        information.pop();
    }
    cout << endl;
}
void shop_system::print() ///輸出客人
{
    queue<Client> temp = line;
    for (int i = 0; i < client_number; i++)
    {
        cout << temp.front() << endl;
        temp.pop();
    }
    cout << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    shop_system *beef_shop = new shop_system(n, m);
    beef_shop->system();
}
