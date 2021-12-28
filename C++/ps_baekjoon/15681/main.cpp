#include <bits/stdc++.h>
using namespace std;

int n, r, q;
vector<vector<int>> tree;
vector<int> dp;

int query(int node)
{
    auto& ret = dp[node];
    if (ret)
        return ret;
    ret = 1;
    for (const auto& e : tree[node])
        if (!dp[e])
            ret += query(e);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r >> q;
    tree.resize(n + 1);
    dp.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int from, to;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    query(r);
    while (q--)
    {
        int num;
        cin >> num;
        cout << query(num) << '\n';
    }
    return 0;
}