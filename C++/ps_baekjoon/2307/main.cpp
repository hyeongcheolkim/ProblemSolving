#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m, min_time_with_lock;
vector<vector<pair<int, int>>> graph;
vector<int> dist, trace;
map<int, map<int, bool>> lock_edge;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int min_dist(bool chase_trace)
{
    if (chase_trace)
        trace.assign(n + 1, 0);
    dist.assign(n + 1, INF);
    pq.emplace(0, 1);
    dist[1] = 0;
    while (!pq.empty())
    {
        auto [now_cost, now] = pq.top();
        pq.pop();
        if (dist[now] < now_cost)
            continue;
        for (const auto& [next_cost, next] : graph[now])
            if (now_cost + next_cost < dist[next])
            {
                if (lock_edge[now][next])
                    continue;
                if (chase_trace)
                    trace[next] = now;
                dist[next] = now_cost + next_cost;
                pq.emplace(dist[next], next);
            }
    }
    return dist[n];
}

void min_dist_lock(int& ret, int num = n)
{
    if (num == 1)
        return;
    int to = num;
    int from = trace[num];
    lock_edge[from][to] = lock_edge[to][from] = true;
    ret = max(ret, min_dist(false));
    lock_edge[from][to] = lock_edge[to][from] = false;
    min_dist_lock(ret, from);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1);
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(cost, to);
        graph[to].emplace_back(cost, from);
    }
    int min_time_no_lock = min_dist(true);
    min_dist_lock(min_time_with_lock);
    cout << (min_time_with_lock == INF ? -1 : min_time_with_lock - min_time_no_lock);
    return 0;
}