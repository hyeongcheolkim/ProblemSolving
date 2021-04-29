//baekjoon ps 10866

#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main()

{
    ios_base::sync_with_stdio(false);
    deque<int> dq;
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        static string str;
        static int input;
        cin >> str;
        if (str == "push_front")
        {
            cin >> input;
            dq.push_front(input);
        }
        else if (str == "push_back")
        {
            cin >> input;
            dq.push_back(input);
        }
        else if (str == "pop_front")
        {
            if (dq.size() == 0)
                cout << -1 << '\n';
            else
            {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if (str == "pop_back")
        {
            if (dq.size() == 0)
                cout << -1 << '\n';
            else
            {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if (str == "size")
            cout << dq.size() << '\n';
        else if (str == "empty")
            cout << dq.empty() << '\n';
        else if (str == "front")
        {
            if (dq.size() == 0)
                cout << -1 << '\n';
            else
            {
                cout << dq.front() << '\n';
                dq.front();
            }
        }
        else if (str == "back")
        {
            if (dq.size() == 0)
                cout << -1 << '\n';
            else
            {
                cout << dq.back() << '\n';
                dq.back();
            }
        }
    }
    return 0;
}