#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

int solve(int idx)
{
    int& ret = dp[idx];
    if (ret != -1)
        return ret;
    if (idx == 0)
        return ret = 1;
    if (idx == 2)
        return ret = 3;
    if (idx % 2 == 1)
        return ret = 0;
    ret = 0;
    ret += solve(idx - 2) * 3;
    for (int i = idx; i >= 4; i -= 2)
        ret += solve(i - 4) * 2;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.assign(n + 1, -1);
    cout << solve(n);
    return 0;
}