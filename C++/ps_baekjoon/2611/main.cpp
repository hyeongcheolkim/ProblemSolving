#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> degree, trace, dp;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1);
    for (auto& e : vector<reference_wrapper<vector<int>>>{degree, trace, dp})
        e.get().resize(n + 1);
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(cost, to);
        ++degree[to];
    }
    q.emplace(0, 1);
    while (degree[1])
    {
        auto [in_cost, now] = q.front();
        q.pop();
        for (const auto [out_cost, next] : graph[now])
        {
            if (auto next_cost = in_cost + out_cost; next_cost > dp[next])
            {
                dp[next] = next_cost;
                trace[next] = now;
            }
            if (--degree[next] == 0)
                q.emplace(dp[next], next);
        }
    }
    cout << dp[1] << '\n';
    vector<int> res;
    int idx = 1;
    while (res.push_back(idx), trace[idx] != 1)
        idx = trace[idx];
    res.push_back(1);
    for_each(res.rbegin(), res.rend(), [](auto& e) {cout << e << ' '; });
    return 0;
}