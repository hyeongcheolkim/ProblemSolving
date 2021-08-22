#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e2;
int n, m, dp[mxN + 1][mxN + 1], degree[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n + 1);
    vector<int> foundation;
    queue<int> q;
    while (m--)
    {
        int to, from, ea;
        cin >> to >> from >> ea;
        graph[from].emplace_back(to, ea);
        ++degree[to];
    }
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
        {
            q.push(i);
            dp[i][i] = 1;
            foundation.push_back(i);
        }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (const auto &e : graph[now])
        {
            auto [next, ea] = e;
            for (const auto &num : foundation)
                dp[next][num] += dp[now][num] * ea;
            if (--degree[next] == 0)
                q.push(next);
        }
    }
    for (const auto &num : foundation)
        cout << num << ' ' << dp[n][num] << '\n';
    return 0;
}