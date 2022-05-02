#include <bits/stdc++.h>
using namespace std;

int n;
vector<unsigned long long> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1);
    dp[1] = 4;
    dp[2] = 6;
    for (int i = 3; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n];
    return 0;
}