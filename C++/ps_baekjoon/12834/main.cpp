#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, v, e, A, B, res;
vector<int> members;
vector<vector<pair<int, int>>> graph;

vector<int> get_min_distance(int start_node)
{
    vector<int> dist(v + 1, INF);
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.emplace(0, start_node);
    dist[start_node] = 0;
    while (!pq.empty())
    {
        auto [in_cost, now_node] = pq.top();
        pq.pop();
        if (dist[now_node] < in_cost)
            continue;
        for (const auto& [out_cost, next_node] : graph[now_node])
            if (int next_cost = in_cost + out_cost; next_cost < dist[next_node])
            {
                dist[next_node] = next_cost;
                pq.emplace(next_cost, next_node);
            }
    }
    for_each(dist.begin(), dist.end(), [](auto& x) {return x == INF ? -1 : x; });
    return dist;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> v >> e >> A >> B;
    members.reserve(n);
    graph.resize(v + 1);
    while (n--)
    {
        int member;
        cin >> member;
        members.push_back(member);
    }
    while (e--)
    {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].emplace_back(l, b);
        graph[b].emplace_back(l, a);
    }
    auto dist_from_A = get_min_distance(A);
    auto dist_from_B = get_min_distance(B);
    for (const auto& member : members)
        res += dist_from_A[member] + dist_from_B[member];
    cout << res;
    return 0;
}