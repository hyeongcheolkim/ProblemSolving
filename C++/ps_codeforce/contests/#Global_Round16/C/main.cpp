#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    stack<int> s;
    s.push(-1);
    while (t--)
    {
        int n, res = 0;
        string a, b;
        cin >> n;
        cin >> a >> b;
        for (int i = 0; i < n; ++i)
            if (a[i] != b[i])
                s.push(2);
            else if (a[i] == '0')
            {
                if (s.top() == 0)
                {
                    s.pop();
                    s.push(2);
                }
                else
                    s.push(1);
            }
            else if (a[i] == '1')
            {
                if (s.top() == 1)
                {
                    s.pop();
                    s.push(2);
                }
                else
                    s.push(0);
            }
        while (s.size() != 1)
        {
            res += s.top();
            s.pop();
        }
        cout << res << '\n';
    }
    return 0;
}