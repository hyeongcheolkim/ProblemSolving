#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m, k, res = 0;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    graph.resize(n + 1);
    dp = vector<vector<int>>(m, vector<int>(n + 1, -INF));
    dp[0][1] = 0;
    while (k--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (!(a < b))
            continue;
        graph[a].emplace_back(b, c);
    }
    for (int from = 0; from <= n; ++from)
        for (const auto& edge : graph[from])
        {
            auto [to, cost] = edge;
            for (int cnt = 1; cnt < m; ++cnt)
                dp[cnt][to] = max(dp[cnt][to], dp[cnt - 1][from] + cost);
        }
    for (int i = 1; i < m; ++i)
        res = max(res, dp[i][n]);
    cout << res;
    return 0;
}