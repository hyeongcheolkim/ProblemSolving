#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> vst;
vector<bool> invite;

void dfs(int level = 0, int now = 1)
{
    if (level == 2)
        return;
    for (const auto& next : graph[now])
        if (!vst[next])
        {
            vst[next] = true;
            invite[next] = true;
            dfs(level + 1, next);
            vst[next] = false;
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1);
    vst.resize(n + 1);
    invite.resize(n + 1);
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vst[1] = true;
    dfs();
    cout << count(invite.begin() + 1, invite.end(), true);
    return 0;
}