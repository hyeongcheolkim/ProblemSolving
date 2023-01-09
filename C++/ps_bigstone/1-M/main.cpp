#include <bits/stdc++.h>
using namespace std;

int n, res;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        stack<char> s;
        string str;
        cin >> str;
        for (const auto& c : str)
        {
            if (s.empty())
            {
                s.push(c);
                continue;
            }
            if (s.top() == c)
            {
                s.pop();
                continue;
            }
            s.push(c);
        }
        if (s.empty())
            ++res;
    }
    cout << res;
    return 0;
}