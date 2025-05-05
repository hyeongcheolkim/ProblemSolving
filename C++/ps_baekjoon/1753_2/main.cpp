#include <bits/stdc++.h>
using namespace std;

int v, e, k;
vector<map<int, int>> graph;
vector<int> dist;
const int INF = numeric_limits<int>::max() / 10;

bool comparator(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> v >> e;
    cin >> k;

    graph.resize(v + 1);
    dist.resize(v + 1, INF);
    dist[k] = 0;

    for (int i = 0; i < e; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = min(graph[u][v] == 0 ? INF : graph[u][v], w);
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&comparator)> pq(comparator);
    dist[k] = 0;
    pq.emplace(k, dist[k]);

    while (!pq.empty())
    {
        auto [in, in_cost] = pq.top();
        pq.pop();
        if (dist[in] < in_cost)
            continue;
        for (const auto &[out, out_cost] : graph[in])
        {
            int cost = in_cost + out_cost;
            if (dist[out] < cost)
                continue;
            dist[out] = cost;
            pq.emplace(out, cost);
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