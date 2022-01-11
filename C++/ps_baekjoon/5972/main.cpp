#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m;
vector<vector<pair<int, int>>> graph;
vector<int> dist;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

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
        graph[from].emplace_back(to, cost);
        graph[to].emplace_back(from, cost);
    }
    dist[1] = 0;
    pq.emplace(0, 1);
    while (!pq.empty())
    {
        auto [now_cost, now] = pq.top();
        pq.pop();
        if (now_cost > dist[now])
            continue;
        for (const auto& e : graph[now])
        {
            auto [next, next_cost] = e;
            if (now_cost + next_cost < dist[next])
            {
                dist[next] = now_cost + next_cost;
                pq.emplace(dist[next], next);
            }
        }
    }
    cout << dist[n];
    return 0;
}