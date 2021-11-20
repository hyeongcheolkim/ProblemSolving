#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mxN = 1e4;
int n, tank[mxN + 1], surface[mxN + 1], height[mxN + 1];
ll res[mxN + 1];
vector<vector<pair<int, int>>> graph;

ll dfs(int node = 1, ll acc = 0)
{
    ll bottom = 0;
    for (const auto& e : graph[node])
    {
        auto [h, v] = e;
        ll time = (h - bottom) * surface[node];
        acc = dfs(v, acc + time);
        bottom = h;
    }
    acc += (height[node] - bottom) * surface[node];
    return res[node] = acc;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    graph.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> surface[i] >> height[i];
        tank[i] = surface[i] * height[i];
    }
    for (int i = 0; i < n - 1; ++i)
    {
        int u, v, h;
        cin >> u >> v >> h;
        graph[u].emplace_back(h, v);
    }
    for (auto& e : graph)
        sort(e.begin(), e.end());
    dfs();
    for (int i = 1; i <= n; ++i)
        cout << res[i] << '\n';
    return 0;
}