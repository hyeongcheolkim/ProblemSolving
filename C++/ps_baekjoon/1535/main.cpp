#include <bits/stdc++.h>
using namespace std;

int n, maxi;
vector<int> hp, mp;
array<int, 100> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    hp.resize(n + 1), mp.resize(n + 1);
    dp.fill(-1);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> hp[i];
    for (int i = 1; i <= n; ++i)
        cin >> mp[i];
    for (int idx = 1; idx <= n; ++idx)
    {
        for (int i = 99; i >= hp[idx]; --i)
            if (dp[i - hp[idx]] != -1)
            {
                dp[i] = max(dp[i], dp[i - hp[idx]] + mp[idx]);
                maxi = max(maxi, dp[i]);
            }
    }
    cout << maxi;
    return 0;
}