#include <bits/stdc++.h>
using namespace std;

int n, r1, r2;
vector<vector<pair<int, int>>> graph;
vector<bool> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> r1 >> r2;
    graph.resize(n + 1);
    vst.resize(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int n1, n2, cost;
        cin >> n1 >> n2 >> cost;
        graph[n1].emplace_back(n2, cost);
        graph[n2].emplace_back(n1, cost);
    }

    int res = -1;
    function<void(int)> dfs = [&](int prev_node)
    {
        static vector<int> trace;
        if (res != -1)
            return;
        if (prev_node == r2)
        {
            int sum = reduce(trace.begin(), trace.end(), 0, [](int acc, int diff){ return acc + diff; });
            res = sum - reduce(trace.begin(), trace.end(), 0, [](int maxi, int e){ return max(maxi, e); });
            return;
        }
        for (const auto &[next_node, cost] : graph[prev_node])
        {
            if (vst[next_node])
                continue;
            vst[next_node] = true;
            trace.push_back(cost);
            dfs(next_node);
            trace.pop_back();
            vst[next_node] = false;
        }
    };
    vector<int> trace;
    vst[r1] = true;
    dfs(r1);
    vst[r1] = false;
    cout << res;
    return 0;
}