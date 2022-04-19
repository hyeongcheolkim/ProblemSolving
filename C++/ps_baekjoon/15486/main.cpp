#include <bits/stdc++.h>
using namespace std;

int n, res;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 2);
    for (int i = 1; i <= n + 1; ++i)
    {
        res = max(res, dp[i]);
        if (i == n + 1)
            break;
        int t, p;
        cin >> t >> p;
        if (i + t > n + 1)
            continue;
        dp[i + t] = max(dp[i + t], res + p);
    }
    cout << res;
    return 0;
}