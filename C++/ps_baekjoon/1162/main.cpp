#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using vertex = pair<ull, ull>;

constexpr ull INF = numeric_limits<ull>::max() / 2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<vertex>> graph(n + 1);
    priority_queue<pair<vertex, int>, vector<pair<vertex, int>>, greater<pair<vertex, int>>> pq;
    vector<vector<ull>> dist(n + 1, vector<ull>(k + 1, INF));
    for (int i = 0; i < m; ++i)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(cost, to);
        graph[to].emplace_back(cost, from);
    }
    pq.emplace(vertex{0, 1}, 0);
    for (int i = 0; i <= k; ++i)
        dist[1][i] = 0;
    while (!pq.empty())
    {
        auto [now, now_cnt] = pq.top();
        auto [now_cost, now_vertex] = now;
        pq.pop();
        if (now_cost > dist[now_vertex][now_cnt])
            continue;
        for (const auto &e : graph[now_vertex])
        {
            auto [next_cost, next_vertex] = e;
            ull total_cost = now_cost + next_cost;
            if (total_cost < dist[next_vertex][now_cnt])
            {
                dist[next_vertex][now_cnt] = total_cost;
                pq.emplace(vertex{total_cost, next_vertex}, now_cnt);
            }
        }
        if (k <= now_cnt)
            continue;
        for (const auto &e : graph[now_vertex])
        {
            auto [next_cost, next_vertex] = e;
            ull total_cost = now_cost;
            if (total_cost < dist[next_vertex][now_cnt + 1])
            {
                dist[next_vertex][now_cnt + 1] = total_cost;
                pq.emplace(vertex{total_cost, next_vertex}, now_cnt + 1);
            }
        }
    }
    cout << *min_element(dist[n].begin(), dist[n].end());
    return 0;
}