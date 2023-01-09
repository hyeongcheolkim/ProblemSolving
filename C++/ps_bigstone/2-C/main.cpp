#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, maxi, mini = INF, res;
vector<vector<int>> board;

int solve(int h)
{
    static constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
    vector<vector<bool>> vst(n + 2, vector<bool>(n + 2));
    int ret = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (board[i][j] <= h)
                continue;
            if (vst[i][j])
                continue;
            queue<pair<int, int>> q;
            vst[i][j] = true;
            q.emplace(i, j);
            ++ret;
            while (!q.empty())
            {
                auto [r, c] = q.front();
                q.pop();
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = r + dr[direction];
                    int nc = c + dc[direction];
                    if (board[nr][nc] == 0)
                        continue;
                    if (board[nr][nc] <= h)
                        continue;
                    if (vst[nr][nc])
                        continue;
                    vst[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 2, decltype(board)::value_type(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            maxi = max(maxi, board[i][j]);
            mini = min(mini, board[i][j]);
        }
    for (int i = mini - 1; i <= maxi + 1; ++i)
        res = max(res, solve(i));
    cout << res;
    return 0;
}