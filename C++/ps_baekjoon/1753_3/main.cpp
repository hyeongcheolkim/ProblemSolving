#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 10;
int v, e, k;

auto cmp = [](const pair<int, int> a, const pair<int, int> &b) -> bool
{
    return a.second > b.second;
};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
vector<vector<pair<int, int>>> graph;
vector<int> dist;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> v >> e >> k;

    graph.resize(v + 1);
    dist.resize(v + 1, INF);

    while (e--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
    }

    pq.emplace(k, 0);
    dist[k] = 0;

    while (!pq.empty())
    {
        auto [in, in_cost] = pq.top();
        pq.pop();
        if (dist[in] < in_cost)
            continue;

        for (const auto &[out, out_cost] : graph[in])
        {
            if (in_cost + out_cost > dist[out])
                continue;
            dist[out] = in_cost + out_cost;
            pq.emplace(out, dist[out]);
        }
    }
    for (int i = 1; i <= v; ++i)
    {
        if (dist[i] == INF)
            cout << "INF" << '\n';
        else
            cout << dist[i] << '\n';
    }
    return 0;
}