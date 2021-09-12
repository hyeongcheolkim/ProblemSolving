#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    stack<char> s;
    while (t--)
    {
        string str;
        cin >> str;
        s.push('1');
        for (int i = 0, len = str.size(); i < len; ++i)
        {
            const auto &c = str[i];
            switch (c)
            {
            case '1':
                if (s.top() == '1')
                    continue;
                else
                    s.push('1');
                break;
            case '0':
                if (s.top() == '0')
                    continue;
                else
                    s.push('0');
                break;
            default:
                break;
            }
        }
        if (s.size() == 1)
            cout << 0 << '\n';
        else if (s.size() == 2)
            cout << 1 << '\n';
        else if (s.size() == 3)
            cout << 1 << '\n';
        else if (s.size() >= 4)
            cout << 2 << '\n';
        while (!s.empty())
            s.pop();
    }
    return 0;
}