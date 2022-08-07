#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m;
vector<vector<int>> board, dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(m + 2, -INF));
    dp.resize(n + 2, vector<int>(m + 2, -INF));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    dp[1][1] = board[1][1];
    for (int i = 1; i <= n; ++i)
    {
        vector<int> row_rt = dp[i];
        for (int j = 1; j <= m; ++j)
            row_rt[j] = max(row_rt[j], max(row_rt[j - 1], dp[i - 1][j]) + board[i][j]);
        vector<int> row_lt = dp[i];
        for (int j = m; j >= 1; --j)
            row_lt[j] = max(row_lt[j], max(row_lt[j + 1], dp[i - 1][j]) + board[i][j]);
        for (int j = 1; j <= m; ++j)
            dp[i][j] = max(row_rt[j], row_lt[j]);
    }
    cout << dp[n][m];
    return 0;
}