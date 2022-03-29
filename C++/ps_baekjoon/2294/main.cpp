#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, k;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    dp.resize(k + 1, INF);
    dp[0] = 0;
    while (n--)
    {
        int cost;
        cin >> cost;
        for (int idx = cost; idx <= k; ++idx)
            dp[idx] = min(dp[idx], dp[idx - cost] + 1);
    }
    cout << (dp.back() == INF ? -1 : dp.back());
    return 0;
}