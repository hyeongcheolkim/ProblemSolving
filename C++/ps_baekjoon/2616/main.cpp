#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> acc;
vector<vector<int>> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    acc.resize(n + 1);
    dp.resize(3 + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
    {
        cin >> acc[i];
        acc[i] += acc[i - 1];
    }
    cin >> m;
    for (int i = 1; i <= 3; ++i)
        for (int j = i * m; j <= n; ++j)
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + acc[j] - acc[j - m]);
    cout << dp[3][n];
    return 0;
}