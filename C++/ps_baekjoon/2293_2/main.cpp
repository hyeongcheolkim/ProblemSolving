#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    dp.resize(k + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i)
    {
        int coin;
        cin >> coin;
        for (int x = coin; x <= k; ++x)
            dp[x] += dp[x - coin];
    }
    cout << dp[k];
    return 0;
}