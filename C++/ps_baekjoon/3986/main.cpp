#include <bits/stdc++.h>
using namespace std;

int n, cnt;
char buff;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin.ignore();
    while (n--)
    {
        stack<char> s;
        while ((buff = cin.get()) != '\n')
        {
            if (s.empty())
            {
                s.push(buff);
                continue;
            }
            if (s.top() == buff)
            {
                s.pop();
                continue;
            }
            s.push(buff);
        }
        if (s.empty())
            ++cnt;
    }
    cout << cnt;
    return 0;
}