#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, k, res = INF;
vector<vector<int>> graph;
vector<vector<int>> vst;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    graph.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> graph[i][j];
    vst.resize(n, vector<int>(1 << n, INF));
    pq.emplace(0, k, 1 << k);
    while (!pq.empty())
    {
        auto [in_cost, in, in_state] = pq.top();
        pq.pop();
        if (in_state == ((1 << n) - 1))
            res = min(res, in_cost);
        if (in_cost > vst[in][in_state])
            continue;
        for (int out = 0; out < n; ++out)
        {
            int out_cost = graph[in][out];
            int out_state = in_state | (1 << out);
            int next_cost = in_cost + out_cost;
            if (vst[out][out_state] <= next_cost)
                continue;
            vst[out][out_state] = next_cost;
            pq.emplace(next_cost, out, out_state);
        }
    }
    cout << res;
    return 0;
}