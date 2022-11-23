#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; ++i)
    {
        dp[i] = max(dp[i], dp[i - 1] + 1);
        for (int buff_idx = i - 1; buff_idx >= 2; --buff_idx)
        {
            const auto& buff = dp[buff_idx - 2];
            dp[i] = max(dp[i], (i - buff_idx + 1) * buff);
        }
    }
    cout << dp[n];
    return 0;
}