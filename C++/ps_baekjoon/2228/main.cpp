#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2, NOT_VST = numeric_limits<int>::min();
int n, m;
vector<int> arr;
vector<vector<int>> dp;

int solve(int max_idx = n, int section_ea = m)
{
    if (section_ea == 0)
        return 0;
    if (max_idx <= 0)
        return -INF;
    int& ret = dp[max_idx][section_ea];
    if (ret != NOT_VST)
        return ret;
    int acc_sum = 0;
    ret = solve(max_idx - 1, section_ea);
    for (int i = max_idx; i >= 1; --i)
    {
        acc_sum += arr[i];
        ret = max(ret, solve(i - 2, section_ea - 1) + acc_sum);
    }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    arr.resize(n + 1);
    dp.assign(n + 1, vector<int>(n / 2 + 1, NOT_VST));
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    cout << solve();
    return 0;
}