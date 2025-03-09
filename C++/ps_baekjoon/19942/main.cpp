#include <bits/stdc++.h>
using namespace std;

int n, mp, mf, ms, mv;
vector<tuple<int, int, int, int, int>> arr;
int answer = numeric_limits<int>::max() / 2;
vector<int> trace;

void dfs(int level = 0, int acc_p = 0, int acc_f = 0, int acc_s = 0, int acc_v = 0, int acc_cost = 0)
{
    static vector<int> mem;
    if (level == arr.size())
    {
        if (!(acc_p >= mp && acc_f >= mf && acc_s >= ms && acc_v >= mv))
            return;
        if (answer <= acc_cost)
            return;
        answer = min(answer, acc_cost);
        trace = mem;
        return;
    }
    auto [p, f, s, v, cost] = arr[level];
    if (!(p == 0 && f == 0 && s == 0 && v == 0))
    {
        mem.push_back(level + 1);
        dfs(level + 1, acc_p + p, acc_f + f, acc_s + s, acc_v + v, acc_cost + cost);
        mem.pop_back();
    }
    dfs(level + 1, acc_p, acc_f, acc_s, acc_v, acc_cost);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cin >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; ++i)
    {
        int p, f, s, v, cost;
        cin >> p >> f >> s >> v >> cost;
        arr.emplace_back(p, f, s, v, cost);
    }
    dfs();
    if (trace.empty())
    {
        cout << -1;
        return 0;
    }
    cout << answer << '\n';
    for (const auto &e : trace)
        cout << e << ' ';
    return 0;
}