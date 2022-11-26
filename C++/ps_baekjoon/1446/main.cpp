#include <bits/stdc++.h>
using namespace std;

int n, d, res = numeric_limits<int>::max() / 2;
unordered_map<int, vector<pair<int, int>>> graph;

void dfs(int now = 0, int acc = 0)
{
    if (now > d)
        return;
    if (now == d)
    {
        res = min(res, acc);
        return;
    }
    for (const auto& [next, cost] : graph[now])
        dfs(next, acc + cost);
    dfs(now + 1, acc + 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> d;
    while (n--)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].emplace_back(to, cost);
    }
    dfs();
    cout << res;
}