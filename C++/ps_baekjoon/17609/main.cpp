#include <bits/stdc++.h>
using namespace std;

int mini;

void solve(const string& str, int lt, int rt, int cnt)
{
    if (lt > rt || cnt >= 2)
    {
        mini = min(mini, cnt);
        return;
    }
    if (str[lt] == str[rt])
        solve(str, lt + 1, rt - 1, cnt);
    else
    {
        solve(str, lt + 1, rt, cnt + 1);
        solve(str, lt, rt - 1, cnt + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        mini = 2;
        solve(str, 0, str.size() - 1, 0);
        if (mini == 0)
            cout << 0 << '\n';
        else if (mini == 1)
            cout << 1 << '\n';
        else if (mini >= 2)
            cout << 2 << '\n';
    }
    return 0;
}