#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e3, MOD = 10'007;
int n;
array<array<int, 10>, mxN + 1 + 1> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    fill(dp[1].begin(), dp[1].end(), 1);
    for (int i = 2; i <= n + 1; ++i)
    {
        dp[i][0] = dp[i - 1][0];
        for (int num = 1; num <= 9; ++num)
            dp[i][num] = (dp[i][num - 1] + dp[i - 1][num]) % MOD;
    }
    cout << dp[n + 1][9];
    return 0;
}