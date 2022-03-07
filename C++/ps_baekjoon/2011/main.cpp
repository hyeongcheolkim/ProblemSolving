#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1'000'000;
string pw;
vector<int> dp;

int solve(int idx)
{
    int& ret = dp[idx];
    if (idx == 0)
        return ret = 1;
    if (ret != -1)
        return ret;
    ret = 0;
    int pre_val = pw[idx - 1] - '0';
    int now_val = pw[idx] - '0';
    if (now_val != 0)
        ret = (ret + solve(idx - 1)) % MOD;
    if (auto num = pre_val * 10 + now_val; 10 <= num && num <= 26)
        ret = (ret + solve(idx - 2)) % MOD;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> pw;
    pw = "0" + pw;
    dp.assign(pw.length() + 1, -1);
    cout << solve(pw.length() - 1);
    return 0;
}