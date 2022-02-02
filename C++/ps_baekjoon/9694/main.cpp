#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int INF = numeric_limits<int>::max() / 2;
int t, n, m;
vector<int> dist, trace;
priority_queue<pos, vector<pos>, greater<pos>> pq;
vector<vector<pos>> graph;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case)
    {
        cin >> n >> m;
        dist.assign(m, INF);
        trace.assign(m, -1);
        graph.assign(m, vector<pos>());
        while (n--)
        {
            int x, y, z;
            cin >> x >> y >> z;
            graph[x].emplace_back(z, y);
            graph[y].emplace_back(z, x);
        }
        dist[0] = 0;
        pq.emplace(0, 0);
        while (!pq.empty())
        {
            auto [in_cost, now] = pq.top();
            pq.pop();
            if (dist[now] < in_cost)
                continue;
            for (const auto& [out_cost, next] : graph[now])
                if (int next_cost = in_cost + out_cost; next_cost < dist[next])
                {
                    trace[next] = now;
                    dist[next] = next_cost;
                    pq.emplace(next_cost, next);
                }
        }
        cout << "Case #" << test_case << ": ";
        if (dist[m - 1] == INF)
            cout << -1;
        else
        {
            vector<int> res;
            for (int node = m - 1; node != -1; node = trace[node])
                res.push_back(node);
            reverse(res.begin(), res.end());
            for (const auto& e : res)
                cout << e << ' ';
        }
        cout << '\n';
    }
    return 0;
}