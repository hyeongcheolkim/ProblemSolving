#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int c, n;
vector<int> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> c >> n;
    dp.resize(c + 1, INF);
    dp[0] = 0;
    while (n--)
    {
        int cost, ea;
        cin >> cost >> ea;
        for (int i = 0; i <= c; ++i)
            dp[min(c, i + ea)] = min(dp[min(c, i + ea)], dp[i] + cost);
    }
    cout << dp[c];
    return 0;
}