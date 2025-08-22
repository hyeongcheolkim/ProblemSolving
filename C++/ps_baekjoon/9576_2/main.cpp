#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m, res = 0;
    cin >> n >> m;
    vector<pair<int, int>> arr;
    arr.reserve(m);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        arr.emplace_back(a, b);
    }

    sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.second < b.second; });

    vector<bool> vst(n + 1, false);
    for (const auto &[a, b] : arr)
    {
        for (int i = a; i <= b; ++i)
        {
            if (vst[i])
                continue;
            vst[i] = true;
            ++res;
            break;
        }
    }
    cout << res << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}