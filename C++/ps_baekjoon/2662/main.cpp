#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 3e2, mxM = 20;
int n, m, company[mxM + 1][mxN + 1], dp[mxM + 1][mxN + 1], path[mxM + 1][mxN + 1];
vector<int> route;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        int invest;
        cin >> invest;
        for (int j = 1; j <= m; ++j)
            cin >> company[j][invest];
    }
    for (int i = 1; i <= m; ++i)
        for (int cost = 1; cost <= n; ++cost)
            for (int j = 0; j <= cost; ++j)
                if (int val = dp[i - 1][cost - j] + company[i][j]; dp[i][cost] < val)
                {
                    dp[i][cost] = val;
                    path[i][cost] = j;
                }
    int curr = m;
    int cost = n;
    while (curr > 0)
    {
        int invest = path[curr][cost];
        route.push_back(invest);
        cost -= invest;
        --curr;
    }
    reverse(route.begin(), route.end());
    cout << dp[m][n] << '\n';
    for (const auto& e : route)
        cout << e << ' ';
    return 0;
}