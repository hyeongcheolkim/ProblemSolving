#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 20, mxM = 1e4;
int coin[mxN + 1], dp[mxM + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0, sizeof(dp));
        int n, money;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> coin[i];
        cin >> money;
        dp[0] = 1;
        for (int idx = 0; idx < n; ++idx)
            for (int i = coin[idx]; i <= money; ++i)
                dp[i] += dp[i - coin[idx]];
        cout << dp[money] << '\n';
    }
    return 0;
}