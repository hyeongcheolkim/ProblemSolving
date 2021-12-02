#include <bits/stdc++.h>
using namespace std;

int n, m;
string s, t;
vector<int> pre, suf;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s >> m >> t;
    pre.resize(n);
    suf.resize(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            if (i + j > n || s[i + j] != t[j])
                break;
            pre[i] = j + 1;
        }
    for (int i = n - 1; i >= 0; --i)
        for (int j = 0; j < m; ++j)
        {
            if (i - j < 0 || s[i - j] != t[m - 1 - j])
                break;
            suf[i] = j + 1;
        }
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (j - i + 1 >= m && pre[i] + suf[j] >= m)
            {
                cout << "YES";
                exit(0);
            }
    cout << "NO";
    return 0;
}