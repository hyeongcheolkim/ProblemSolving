//baekjoon ps 18258

#include <iostream>
#include <string>
#include <deque>

using namespace std;

class myqueue
{
private:
    deque<int> arr;

public:
    void push(const int &n)
    {
        arr.push_back(n);
    }
    void pop()
    {
        if (arr.empty())
            cout << -1 << '\n';
        else
        {
            cout << arr.front() << '\n';
            arr.pop_front();
        }
    }
    void size()
    {
        cout << arr.size() << '\n';
    }
    void empty()
    {
        cout << arr.empty() << '\n';
    }
    void front()
    {
        if (arr.empty())
            cout << -1 << '\n';
        else
            cout << arr.front() << '\n';
    }
    void back()
    {
        if (arr.empty())
            cout << -1 << '\n';
        else
            cout << arr.back() << '\n';
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    myqueue mq;
    string str;
    for (int i = 0; i < n; i++)
    {
        static int input;
        cin >> str;
        switch (str[0])
        {
        case 'p':
            if (str[1] == 'u')
            {
                cin >> input;
                mq.push(input);
            }
            else
                mq.pop();
            break;
        case 's':
            mq.size();
            break;
        case 'e':
            mq.empty();
            break;
        case 'f':
            mq.front();
            break;
        case 'b':
            mq.back();
            break;
        }
    }
    return 0;
}