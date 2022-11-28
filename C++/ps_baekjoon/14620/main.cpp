#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, 0, +1, -1}, dc[]{0, +1, -1, 0, 0};
int n, res = numeric_limits<int>::max() / 2;
vector<vector<int>> cost;
vector<vector<bool>> vst;
vector<pair<int, int>> candidate;

bool check_vst(const pair<int, int>& pos)
{
    const auto& [row, col] = pos;
    for (int direction = 0; direction < 5; ++direction)
    {
        int nr = row + dr[direction];
        int nc = col + dc[direction];
        if (cost[nr][nc] == -1 || vst[nr][nc])
            return false;
    }
    for (int direction = 0; direction < 5; ++direction)
    {
        int nr = row + dr[direction];
        int nc = col + dc[direction];
        vst[nr][nc] = true;
    }
    return true;
}

void uncheck_vst(const pair<int, int>& pos)
{
    const auto& [row, col] = pos;
    for (int direction = 0; direction < 5; ++direction)
    {
        int nr = row + dr[direction];
        int nc = col + dc[direction];
        vst[nr][nc] = false;
    }
}

int calculate_cost(const pair<int, int>& pos)
{
    int ret = 0;
    const auto& [row, col] = pos;
    for (int direction = 0; direction < 5; ++direction)
    {
        int nr = row + dr[direction];
        int nc = col + dc[direction];
        ret += cost[nr][nc];
    }
    return ret;
}

void solve(int idx = 0)
{
    static decltype(candidate) pos;
    if (idx > candidate.size())
        return;
    const auto& now_pos = candidate[idx];
    if (pos.size() == 3)
    {
        int sum = 0;
        for (const auto& p : pos)
            sum += calculate_cost(p);
        res = min(res, sum);
        return;
    }
    if (check_vst(now_pos))
    {
        pos.push_back(now_pos);
        solve(idx + 1);
        pos.pop_back();
        uncheck_vst(now_pos);
    }
    solve(idx + 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    cost.resize(n + 2, decltype(cost)::value_type(n + 2, -1));
    vst.resize(n + 2, decltype(vst)::value_type(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> cost[i][j];
            candidate.emplace_back(i, j);
        }
    solve();
    cout << res;
    return 0;
}