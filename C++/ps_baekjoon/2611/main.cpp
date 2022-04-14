#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> trace;
vector<int> degree, dp;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1);
    trace.resize(n + 1);
    degree.resize(n + 1);
    dp.resize(n + 1);
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(cost, to);
        ++degree[to];
    }
    q.emplace(0, 1);
    trace[1].push_back(1);
    while (!q.empty())
    {
        auto [in_cost, now] = q.front();
        q.pop();
        for (const auto& [out_cost, next] : graph[now])
        {
            if (auto next_cost = in_cost + out_cost; next_cost > dp[next])
            {
                dp[next] = next_cost;
                trace[next] = trace[now];
                trace[next].push_back(next);
            }
            if (--degree[next] == 0)
                q.emplace(dp[next], next);
        }
    }
    cout << dp[1] << '\n';
    for (const auto& e : trace[1])
        cout << e << ' ';
    return 0;
}