#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> dp;
vector<bool> vip;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    dp.resize(n + 1, vector<int>(2));
    vip.resize(n + 1);
    while (m--)
    {
        int num;
        cin >> num;
        vip[num] = true;
    }
    dp[1][0] = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (vip[i])
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        else
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            if (!vip[i - 1])
                dp[i][1] = dp[i - 1][0];
        }
    }
    cout << dp[n][0] + dp[n][1];
    return 0;
}