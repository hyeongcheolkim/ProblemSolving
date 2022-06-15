#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, e, v1, v2;
vector<vector<pos>> graph;

int get_min_dist(int from, int to)
{
    priority_queue<pos, vector<pos>, greater<pos>> pq;
    vector<int> dist;
    dist.resize(n + 1, INF);
    dist[from] = 0;
    pq.emplace(0, from);
    while (!pq.empty())
    {
        auto [in_cost, now] = pq.top();
        pq.pop();
        if (dist[now] < in_cost)
            continue;
        for (const auto& [out_cost, next] : graph[now])
            if (int next_cost = in_cost + out_cost; next_cost < dist[next])
            {
                dist[next] = next_cost;
                pq.emplace(next_cost, next);
            }
    }
    return dist[to];
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> e;
    graph.resize(n + 1);
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(c, b);
        graph[b].emplace_back(c, a);
    }
    cin >> v1 >> v2;
    long long one_v1 = get_min_dist(1, v1);
    long long one_v2 = get_min_dist(1, v2);
    long long v1_v2 = get_min_dist(v1, v2);
    long long v2_n = get_min_dist(v2, n);
    long long v1_n = get_min_dist(v1, n);
    long long res = INF;
    res = min(res, one_v1 + v1_v2 + v2_n);
    res = min(res, one_v2 + v1_v2 + v1_n);
    cout << (res == INF ? -1 : res);
    return 0;
}