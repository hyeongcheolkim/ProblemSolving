#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{+1, 0}, dc[]{0, +1};
int n, cnt;
vector<vector<int>> board;
vector<vector<long long>> dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 1, vector<int>(n + 1));
    dp.resize(n + 1, vector<long long>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    dp[1][1] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            for (int direction = 0; direction < 2; ++direction)
            {
                int nr = i + dr[direction] * board[i][j];
                int nc = j + dc[direction] * board[i][j];
                if (board[i][j] == 0)
                    continue;
                if (!(1 <= nr && nr <= n && 1 <= nc && nc <= n))
                    continue;
                dp[nr][nc] += dp[i][j];
            }
    cout << dp[n][n];
    return 0;
}