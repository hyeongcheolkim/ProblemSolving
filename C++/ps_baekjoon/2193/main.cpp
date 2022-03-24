#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> dp;

long long solve(int idx)
{
    auto& ret = dp[idx];
    if (idx == 1)
        return ret = 1;
    if (idx == 2)
        return ret = 1;
    if (ret != 0)
        return ret;
    ret += solve(idx - 1) + solve(idx - 2);
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1);
    cout << solve(n);
    return 0;
}