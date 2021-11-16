#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m, l;
set<int> res;
queue<int> q;
vector<int> node;
vector<vector<pair<int, int>>> graph;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> l;
    graph.resize(m + 1);
    node.assign(m + 1, -1);
    while (n--)
    {
        int num;
        cin >> num;
        res.insert(num);
        node[num] = INF;
        q.emplace(num);
    }
    while (l--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c);
        graph[b].emplace_back(a, c);
    }
    while (!q.empty())
    {
        auto now = q.front();
        q.pop();
        for (const auto& e : graph[now])
        {
            auto [next, next_time] = e;
            if (next_time <= node[next] || node[now] < next_time)
                continue;
            node[next] = next_time;
            q.emplace(next);
            res.insert(next);
        }
    }
    for (const auto& e : res)
        cout << e << '\n';
    return 0;
}