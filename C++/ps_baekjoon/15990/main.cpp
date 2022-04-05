#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e5, MOD = 1'000'000'009;

int dp[mxN + 1][3 + 1];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    dp[1][1] = dp[2][2] = dp[3][1] = dp[3][2] = dp[3][3] = 1;
    for (int i = 4; i <= mxN; ++i)
    {
        dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
        dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
        dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << ((dp[n][1] + dp[n][2]) % MOD + dp[n][3]) % MOD << '\n';
    }
    return 0;
}