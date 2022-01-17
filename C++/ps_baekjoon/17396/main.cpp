#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll INF = numeric_limits<ll>::max() / 2;
int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> viewable;
vector<ll> dist;
priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n);
    viewable.resize(n);
    dist.assign(n, INF);
    for (int i = 0; i < n; ++i)
        cin >> viewable[i];
    viewable.back() = 0;
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        if (viewable[from] || viewable[to])
            continue;
        graph[from].emplace_back(cost, to);
        graph[to].emplace_back(cost, from);
    }
    dist[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty())
    {
        auto [now_cost, now] = pq.top();
        pq.pop();
        if (dist[now] < now_cost)
            continue;
        for (const auto& [next_cost, next] : graph[now])
        {
            if (now_cost + next_cost < dist[next])
            {
                dist[next] = now_cost + next_cost;
                pq.emplace(dist[next], next);
            }
        }
    }
    cout << (dist.back() == INF ? -1 : dist.back());
    return 0;
}