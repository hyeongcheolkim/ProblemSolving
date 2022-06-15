#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 4;
int n;
vector<vector<int>> graph;
vector<unordered_map<int, int>> dp;

int solve(int now = 0, int vst = 1)
{
    int& ret = dp[now][vst];
    if (ret != 0)
        return ret;
    if (vst == ((1 << n) - 1))
        return graph[now][0];
    ret = INF;
    for (int next = 0; next < n; ++next)
    {
        if (graph[now][next] == INF || vst & (1 << next))
            continue;
        ret = min(ret, graph[now][next] + solve(next, vst | (1 << next)));
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    graph.resize(n, vector<int>(n));
    dp.resize(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    cout << solve();
    return 0;
}