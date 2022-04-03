#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 9901;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = 1;
    dp[1][1] = 2;
    for (int i = 2; i <= n; ++i)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][1] = (dp[i - 1][0] * 2 + dp[i - 1][1]) % MOD;
    }
    cout << (dp[n][0] + dp[n][1]) % MOD;
    return 0;
}