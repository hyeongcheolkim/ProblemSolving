#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        bool flag = false;
        cin >> n >> m;
        vector<vector<char>> board(n + 2, vector<char>(m + 2));
        vector<vector<pair<int, int>>> dp(n + 2, vector<pair<int, int>>(m + 2));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
            {
                cin >> board[i][j];
                if (board[i][j] == '1')
                    flag = true;
            }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (board[i][j] == '1')
                {
                    dp[i][j].first = dp[i - 1][j].first + 1;
                    dp[i][j].second = dp[i][j - 1].second + 1;
                }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                if (dp[i][j] != pair{0, 0})
                {
                    auto [dr, dc] = dp[i][j];
                    dr = -(dr - 1);
                    dc = -(dc - 1);
                    if (dp[i + dr][j + dc] != pair{1, 1})
                    {
                        cout << "NO" << '\n';
                        goto breakloop;
                    }
                }
        cout << (flag ? "YES" : "NO") << '\n';
    breakloop:
        continue;
    }
    return 0;
}
