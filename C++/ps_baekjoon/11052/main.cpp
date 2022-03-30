#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1);
    for (int ea = 1; ea <= n; ++ea)
    {
        int cost;
        cin >> cost;
        for (int idx = ea; idx <= n; ++idx)
            dp[idx] = max(dp[idx], dp[idx - ea] + cost);
    }
    cout << dp.back();
    return 0;
}