#include <bits/stdc++.h>
using namespace std;

int n, dist_sum;
vector<vector<int>> graph;
vector<bool> vst;

void solve(int node = 1, int dist = 0)
{
    if (all_of(graph[node].begin(), graph[node].end(), [](auto& e) {return vst[e]; }))
    {
        dist_sum += dist;
        return;
    }
    for (const auto& next_node : graph[node])
    {
        if (vst[next_node])
            continue;
        vst[next_node] = true;
        solve(next_node, dist + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    graph.resize(n + 1);
    vst.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vst[1] = true;
    solve();
    cout << (dist_sum % 2 == 0 ? "No" : "Yes");
    return 0;
}