#include <bits/stdc++.h>
using namespace std;

int n, node1, node2, m, res = -1;
vector<vector<int>> graph;
vector<bool> vst;

void dfs(int now = node1, int cnt = 0)
{
    if (now == node2)
    {
        res = cnt;
        return;
    }
    for (const auto& e : graph[now])
        if (!vst[e])
        {
            vst[e] = true;
            dfs(e, cnt + 1);
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> node1 >> node2 >> m;
    graph.resize(n + 1);
    vst.resize(n + 1);
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vst[node1] = true;
    dfs();
    cout << res;
    return 0;
}