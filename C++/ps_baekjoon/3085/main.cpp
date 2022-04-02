#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, +1}, dc[]{+1, 0};
int n, res;
vector<vector<char>> board;

int get_max()
{
    static vector<vector<pair<int, int>>> dp;
    dp.assign(n + 2, vector<pair<int, int>>(n + 2));
    int ret = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            dp[i][j] = {1, 1};
            if (board[i - 1][j] == board[i][j] || board[i - 1][j] == 0)
                dp[i][j].first = dp[i - 1][j].first + 1;
            if (board[i][j - 1] == board[i][j] || board[i][j - 1] == 0)
                dp[i][j].second = dp[i][j - 1].second + 1;
            ret = max({ret, dp[i][j].first, dp[i][j].second});
        }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 2, vector<char>(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            for (int direction = 0; direction < 2; ++direction)
            {
                int nr = i + dr[direction];
                int nc = j + dc[direction];
                if (board[nr][nc] == 0)
                    continue;
                swap(board[i][j], board[nr][nc]);
                int ret = get_max();
                res = max(res, ret);
                swap(board[i][j], board[nr][nc]);
            }
        }
    cout << res;
    return 0;
}