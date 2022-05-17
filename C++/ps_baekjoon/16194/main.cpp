#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;
vector<int> price, dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    price.resize(n + 1);
    dp.resize(n + 1, INF);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i)
        cin >> price[i];
    for (int p = 1; p <= n; ++p)
        for (int i = p; i <= n; ++i)
            dp[i] = min(dp[i], dp[i - p] + price[p]);
    cout << dp.back();
    return 0;
}