#include <bits/stdc++.h>
using namespace std;

constexpr long long mxN = 10, MOD = 1e9 + 7;
long long v, e, t, res, packet[mxN + 1], d[mxN + 1];
vector<vector<long long>> graph;
set<long long> s, ts;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> v >> e >> t;
    graph.resize(v + 1);
    while (e--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    packet[1] = 1;
    s.insert(1);
    while (t--)
    {
        for (const auto& now : s)
        {
            d[now] -= packet[now] % MOD;
            for (const auto& next : graph[now])
            {
                d[next] += packet[now] % MOD;
                d[next] %= MOD;
                ts.insert(next);
            }
        }
        for (int i = 1; i <= v; ++i)
        {
            packet[i] += d[i] % MOD;
            packet[i] %= MOD;
        }
        s.swap(ts);
        ts.clear();
        for (int i = 1; i <= v; ++i)
            d[i] = 0;
    }
    for (int i = 1; i <= v; ++i)
    {
        res += packet[i] % MOD;
        res %= MOD;
    }
    cout << res;
    return 0;
}