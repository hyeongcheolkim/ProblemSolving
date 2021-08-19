//baekjoon ps 2091

#include <bits/stdc++.h>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max() / 2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int x, a, b, c, d;
    cin >> x >> a >> b >> c >> d;
    vector<pair<int, int>> coin;
    coin.emplace_back(1, a);
    coin.emplace_back(5, b);
    coin.emplace_back(10, c);
    coin.emplace_back(25, d);
    vector<vector<int>> dp(x + 1, vector<int>(5));
    dp[0][0] = 0;
    for (int i = 1; i <= x; ++i)
        dp[i][0] = -INF;
    for (const auto &e : coin)
    {
        auto [cost, total] = e;
        for (int idx = x; idx >= 1; --idx)
            for (int ea = 1; ea <= total && idx - ea * cost >= 0; ++ea)
                if (dp[idx][0] < dp[idx - ea * cost][0] + ea)
                {
                    dp[idx][0] = dp[idx - ea * cost][0] + ea;
                    for (int i = 1; i <= 4; ++i)
                        dp[idx][i] = dp[idx - ea * cost][i];
                    switch (cost)
                    {
                    case 1:
                        dp[idx][1] += ea;
                        break;
                    case 5:
                        dp[idx][2] += ea;
                        break;
                    case 10:
                        dp[idx][3] += ea;
                        break;
                    case 25:
                        dp[idx][4] += ea;
                        break;
                    default:
                        break;
                    }
                }
    }
    if (dp[x][0] > 0)
        for (int i = 1; i <= 4; ++i)
            cout << dp[x][i] << ' ';
    else
        for (int i = 1; i <= 4; ++i)
            cout << 0 << ' ';
    return 0;
}