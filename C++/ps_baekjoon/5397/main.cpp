#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        string pw;
        cin >> pw;
        stack<char> lt, rt;
        for (const auto& e : pw)
            switch (e)
            {
                case '<':
                    if (lt.empty())
                        continue;
                    rt.push(lt.top());
                    lt.pop();
                    break;
                case '>':
                    if (rt.empty())
                        continue;
                    lt.push(rt.top());
                    rt.pop();
                    break;
                case '-':
                    if (lt.empty())
                        continue;
                    lt.pop();
                    break;
                default:
                    lt.push(e);
                    break;
            }
        while (!lt.empty())
        {
            rt.push(lt.top());
            lt.pop();
        }
        while (!rt.empty())
        {
            cout << rt.top();
            rt.pop();
        }
        cout << '\n';
    }
    return 0;
}