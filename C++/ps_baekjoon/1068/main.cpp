#include <bits/stdc++.h>
using namespace std;

int n, root, target;
vector<vector<int>> graph;
vector<int> tree, dp;

int solve(int node)
{
    int& ret = dp[node];
    if (ret != -1)
        return ret;
    if (graph[node].empty())
        return ret = 1;
    ret = 0;
    for (const auto& child : graph[node])
        ret += solve(child);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    graph.resize(n);
    tree.resize(n);
    dp.resize(n, -1);
    for (int node = 0; node < n; ++node)
    {
        cin >> tree[node];
        if (tree[node] == -1)
        {
            root = node;
            continue;
        }
        graph[tree[node]].push_back(node);
    }
    cin >> target;
    int res = solve(root) - solve(target);
    if (graph[tree[target]].size() == 1)
        ++res;
    cout << res;
    return 0;
}