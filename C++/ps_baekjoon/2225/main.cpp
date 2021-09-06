#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9, mxN = 2e2;
int n, k, dp[mxN + 1][mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 0; i <= n; ++i)
        dp[1][i] = 1;
    for (int h = 2; h <= k; ++h)
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= i; ++j)
            {
                dp[h][i] += dp[h - 1][j];
                dp[h][i] %= mod;
            }
    cout << dp[k][n];
    return 0;
}