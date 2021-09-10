#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, res = -INF;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[0][0] = dp[0][1] = -INF;
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = max(arr[i] + dp[i - 1][0], arr[i]);
        dp[i][1] = max(arr[i] + dp[i - 1][1], dp[i - 1][0]);
        res = max({res, dp[i][0], dp[i][1]});
    }
    cout << res;
    return 0;
}