#include <bits/stdc++.h>
using namespace std;

constexpr int DIV = 1'000'000'003, mxN = 1e3;
int n, k, dp[mxN + 1][mxN + 1];

int solve(int n, int k)
{
    int& ret = dp[n][k];
    if (k == 1)
        return ret = n;
    if (n <= 0 || n < 2 * k)
        return ret = 0;
    if (~ret)
        return ret;
    return ret = (solve(n - 2, k - 1) + solve(n - 1, k)) % DIV;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    cout << solve(n, k);
    return 0;
}