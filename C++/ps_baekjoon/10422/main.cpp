#include <bits/stdc++.h>
using namespace std;

constexpr long long mod = 1'000'000'007;
vector<long long> dp(5000 + 1, 0);

void build_dp()
{
    dp[0] = 1L;
    for (int i = 2; i <= 5000; i += 2)
        for (int j = 2; j <= i; j += 2)
        {
            dp[i] = (dp[i] + (dp[j - 2] * dp[i - j]) % mod) % mod;
        }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);

    build_dp();

    int t;
    cin >> t;
    while (t--)
    {
        int len;
        cin >> len;
        cout << dp[len] << '\n';
    }
    return 0;
}