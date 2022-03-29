#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> day, cost, dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (auto& e : vector<reference_wrapper<vector<int>>>{day, cost, dp})
        e.get().resize(n + 2);
    for (int i = 1; i <= n; ++i)
        cin >> day[i] >> cost[i];
    for (int i = n; i >= 1; --i)
        if (day[i] + i > n + 1)
            dp[i] = dp[i + 1];
        else
            dp[i] = max(dp[i + 1], dp[i + day[i]] + cost[i]);
    cout << dp[1];
    return 0;
}