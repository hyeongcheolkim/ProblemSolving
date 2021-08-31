#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxN = 5e1, OUT_OF_BOUND = -1, NOT_VISIT = -1;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, board[mxN + 2][mxN + 2], dp[mxN + 2][mxN + 2];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(board, OUT_OF_BOUND, sizeof(board));
    memset(dp, NOT_VISIT, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            char num;
            cin >> num;
            board[i][j] = num - '0';
        }
    queue<pos> q;
    dp[1][1] = 0;
    q.emplace(1, 1);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (board[nr][nc] == 1 && (dp[nr][nc] == NOT_VISIT || dp[r][c] < dp[nr][nc]))
            {
                dp[nr][nc] = dp[r][c];
                q.emplace(nr, nc);
            }
            else if (board[nr][nc] == 0 && (dp[nr][nc] == NOT_VISIT || dp[r][c] + 1 < dp[nr][nc]))
            {
                dp[nr][nc] = dp[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
    cout << dp[n][n];
    return 0;
}