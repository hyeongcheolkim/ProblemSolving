//baekjoon ps 1939

#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max() / 2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m, start, end;
    cin >> n >> m;
    vector<unordered_map<int, int>> graph(n + 1);
    vector<int> dist(n + 1);
    while (m--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = max(graph[from][to], cost);
        graph[to][from] = max(graph[to][from], cost);
    }
    cin >> start >> end;
    priority_queue<pair<int, int>> pq;
    pq.emplace(INF, start);
    while (!pq.empty())
    {
        auto [now_cost, now_vertex] = pq.top();
        pq.pop();
        dist[now_vertex] = now_cost;
        if (now_vertex == end)
            break;
        for (const auto &e : graph[now_vertex])
        {
            auto [next_vertex, next_cost] = e;
            if (dist[next_vertex])
                continue;
            pq.emplace(min(next_cost, now_cost), next_vertex);
        }
    }
    cout << dist[end];
    return 0;
}