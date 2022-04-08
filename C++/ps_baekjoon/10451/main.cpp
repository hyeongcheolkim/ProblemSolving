#include <bits/stdc++.h>
using namespace std;

vector<int> cycle;
vector<bool> vst;

bool dfs(int from)
{
    vst[from] = true;
    if (vst[cycle[from]])
        return true;
    return dfs(cycle[from]);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, cnt = 0;
        cin >> n;
        cycle.resize(n + 1);
        vst.assign(n + 1, false);
        for (int i = 1; i <= n; ++i)
            cin >> cycle[i];
        for (int i = 1; i <= n; ++i)
            if (!vst[i] && dfs(i))
                ++cnt;
        cout << cnt << '\n';
    }
    return 0;
}