#include <bits/stdc++.h>
using namespace std;

int n, m, maxi = -1;
vector<vector<int>> graph;
vector<bool> vst;
vector<int> res;

void solve(int& ret, int now)
{
    for (const auto& next : graph[now])
        if (!vst[next])
        {
            vst[next] = true;
            solve(ret, next);
            ++ret;
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1);
    while (m--)
    {
        int from, to;
        cin >> to >> from;
        graph[from].push_back(to);
    }
    for (int i = 1; i <= n; ++i)
    {
        int ret = 1;
        vst.assign(n + 1, false);
        vst[i] = true;
        solve(ret, i);
        if (ret > maxi)
        {
            maxi = ret;
            res.clear();
            res.push_back(i);
        }
        else if (ret == maxi)
            res.push_back(i);
    }
    for (const auto& e : res)
        cout << e << ' ';
    return 0;
}