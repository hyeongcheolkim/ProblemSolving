#include <bits/stdc++.h>
using namespace std;

int n, m, r, idx;
vector<vector<int>> graph;
vector<int> order;
vector<bool> vst;
queue<int> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> r;
    graph.resize(n + 1);
    order.resize(n + 1);
    vst.resize(n + 1);
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    for_each(graph.begin(), graph.end(), [](auto& e) {sort(e.begin(), e.end()); });
    q.push(r);
    vst[r] = true;
    order[r] = ++idx;
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (const auto& next : graph[now])
        {
            if (vst[next])
                continue;
            vst[next] = true;
            q.push(next);
            order[next] = ++idx;
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << order[i] << '\n';
    return 0;
}