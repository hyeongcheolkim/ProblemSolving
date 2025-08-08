#include <bits/stdc++.h>
using namespace std;

const int INF = numeric_limits<int>::max() / 2;
int n, q;
vector<vector<int>> graph;
vector<vector<pair<int, int>>> edges;

void dfs(const int& root, int now, int acc_mini, vector<bool> &vst)
{
    if(root == now)
    {
        graph[root][root] = 0;
        vst[root] = true;
    }
    
    for (const auto &[next, r] : edges[now])
    {
        if (vst[next])
            continue;
        int mini = min(acc_mini, r);
        graph[root][next] = mini;

        vst[next] = true;
        dfs(root, next, mini, vst);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> q;
    edges.resize(n + 1);
    graph.resize(n + 1, vector<int>(n + 1, INF));

    for (int i = 0; i < n - 1; ++i)
    {
        int from, to, r;
        cin >> from >> to >> r;
        edges[from].emplace_back(to, r);
        edges[to].emplace_back(from, r);
    }

    for (int i = 1; i <= n; ++i)
    {
        vector<bool> vst(n + 1, false);
        dfs(i, i, INF, vst);
    }

    while (q--)
    {
        int k, v;
        cin >> k >> v;
        int cnt = count_if(graph[v].begin() + 1, graph[v].end(), [&](const int& x){return x >= k;});
        cout << cnt << '\n';
    }
    return 0;
}