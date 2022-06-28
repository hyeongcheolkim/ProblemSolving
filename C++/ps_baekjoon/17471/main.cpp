#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, total_population, res = INF;
vector<int> popuplation;
vector<bool> vst;
vector<vector<int>> graph;

int bfs(int node, vector<bool>&& vst)
{
    queue<int> q;
    q.push(node);
    vst[node] = true;
    int ret = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (const auto& next : graph[now])
        {
            if (vst[next])
                continue;
            q.push(next);
            vst[next] = true;
            ++ret;
        }
    }
    return ret;
}

bool is_valid()
{
    vector<int> g1, g2;
    for (int i = 1; i <= n; ++i)
        if (vst[i])
            g1.push_back(i);
        else
            g2.push_back(i);
    auto tmp1 = vst;
    auto tmp2 = vst;
    for (int i = 1; i <= n; ++i)
        tmp1[i] = !tmp1[i];
    auto cnt1 = bfs(g1.front(), move(tmp1));
    auto cnt2 = bfs(g2.front(), move(tmp2));
    return g1.size() == cnt1 && g2.size() == cnt2;
}

void dfs(int level = 1, int acc = 0)
{
    if (level == n + 1)
    {
        if (acc == 0 || acc == total_population)
            return;
        if (is_valid())
            res = min(res, abs(total_population - 2 * acc));
        return;
    }
    dfs(level + 1, acc);
    vst[level] = true;
    dfs(level + 1, acc + popuplation[level]);
    vst[level] = false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    popuplation.resize(n + 1);
    vst.resize(n + 1);
    graph.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        cin >> popuplation[i];
        total_population += popuplation[i];
    }
    for (int from = 1; from <= n; ++from)
    {
        int ea;
        cin >> ea;
        while (ea--)
        {
            int to;
            cin >> to;
            graph[from].push_back(to);
        }
    }
    dfs();
    cout << (res == INF ? -1 : res);
    return 0;
}