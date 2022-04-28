#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
set<string> a, b;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (n--)
    {
        string str;
        cin >> str;
        a.insert(str);
    }
    while (m--)
    {
        string str;
        cin >> str;
        cnt += a.contains(str);
    }
    cout << cnt;
    return 0;
}