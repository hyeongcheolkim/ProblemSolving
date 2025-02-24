#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> scores;
vector<vector<int>> graph;
queue<int> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    scores.resize(n + 1);
    graph.resize(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int val;
        cin >> val;
        if (val <= 0)
            continue;
        graph[val].emplace_back(i);
    }
    while (m--)
    {
        int i, w;
        cin >> i >> w;
        scores[i] += w;
    }
    q.push(1);
    while (!q.empty())
    {
        int now_node = q.front();
        q.pop();
        for (const auto &next_node : graph[now_node])
        {
            scores[next_node] += scores[now_node];
            q.push(next_node);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << scores[i] << ' ';
    return 0;
}