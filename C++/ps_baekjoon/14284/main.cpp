#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m, s, t;
vector<vector<pos>> graph;
vector<int> dist;
priority_queue<pos, vector<pos>, greater<pos>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1);
    dist.assign(n + 1, INF);
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(cost, to);
        graph[to].emplace_back(cost, from);
    }
    cin >> s >> t;
    dist[s] = 0;
    pq.emplace(0, s);
    while (!pq.empty())
    {
        auto [in_cost, now] = pq.top();
        pq.pop();
        if (dist[now] < in_cost)
            continue;
        for (const auto& [out_cost, next] : graph[now])
            if (int next_cost = in_cost + out_cost; next_cost < dist[next])
                pq.emplace(dist[next] = next_cost, next);
    }
    cout << dist[t];
    return 0;
}