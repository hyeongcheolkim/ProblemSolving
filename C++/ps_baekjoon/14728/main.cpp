#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> t;
    dp.resize(t + 1);
    while (n--)
    {
        int k, s;
        cin >> k >> s;
        for (int i = t; i >= k; --i)
            dp[i] = max(dp[i], dp[i - k] + s);
    }
    cout << dp[t];
    return 0;
}