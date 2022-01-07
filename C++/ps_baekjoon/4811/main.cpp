#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 30;
long long dp[mxN][mxN * 2];
int input;

long long solve(int ea = 29, int half = 1)
{
    auto& ret = dp[ea][half];
    if (ea < 0 || half < 0)
        return 0;
    if (ea == 0 && half >= 1)
        return ret = 1;
    if (ret != 0)
        return ret;
    return ret += solve(ea - 1, half + 1) + solve(ea, half - 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    solve();
    while (cin >> input, input != 0)
        cout << solve(input - 1) << '\n';
    return 0;
}