#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int t, w;
vector<int> tree;
vector<vector<int>> dp;

int solve(int turn, int move_cnt)
{
    if (turn < 0)
        return 0;
    if (move_cnt < 0)
        return -INF;
    int& ret = dp[turn][move_cnt];
    const int& now_tree = tree[turn];
    if (turn == 0)
        return ret = 0;
    if (ret != -1)
        return ret;
    int move_val = solve(turn - 1, move_cnt - 1);
    int not_move_val = solve(turn - 1, move_cnt);
    ret = not_move_val;
    if (move_cnt % 2 != now_tree % 2)
        ret = max(ret, not_move_val + 1);
    else
        ret = max(ret, move_val + 1);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> t >> w;
    tree.resize(t + 1);
    dp.resize(t + 1, decltype(dp)::value_type(w + 2, -1));
    for (int i = 1; i <= t; ++i)
        cin >> tree[i];
    cout << solve(t, w);
    return 0;
}