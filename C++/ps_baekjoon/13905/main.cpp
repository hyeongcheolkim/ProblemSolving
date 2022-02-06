#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m, s, e, cnt;
vector<vector<pair<int, int>>> graph;
priority_queue<tuple<int, int, int>> pq;
vector<int> uf;
vector<bool> vst;

int find(int num)
{
    if (num == uf[num])
        return num;
    return uf[num] = find(uf[num]);
}

bool uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        uf[a] = b;
        return true;
    }
    else
        return false;
}

void dfs(int& ret, int now_cost = INF, int now_node = s, int target = e)
{
    if (ret != INF)
        return;
    if (now_node == target)
    {
        ret = now_cost;
        return;
    }
    for (const auto& [next_cost, next_node] : graph[now_node])
        if (!vst[next_node])
        {
            vst[next_node] = true;
            dfs(ret, min(now_cost, next_cost), next_node, target);
            vst[next_node] = false;
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> s >> e;
    graph.resize(n + 1);
    uf.resize(n + 1);
    vst.resize(n + 1);
    iota(uf.begin(), uf.end(), 0);
    while (m--)
    {
        int h1, h2, k;
        cin >> h1 >> h2 >> k;
        pq.emplace(k, h1, h2);
    }
    while (!pq.empty() && cnt != n - 1)
    {
        auto [cost, h1, h2] = pq.top();
        pq.pop();
        if (uni(h1, h2))
        {
            graph[h1].emplace_back(cost, h2);
            graph[h2].emplace_back(cost, h1);
            ++cnt;
        }
    }
    int ret = INF;
    vst[s] = true;
    dfs(ret);
    cout << (ret == INF ? 0 : ret);
    return 0;
}