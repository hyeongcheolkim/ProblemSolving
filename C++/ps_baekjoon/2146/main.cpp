#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int OUT_OF_BOUND = -1, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0}, INF = numeric_limits<int>::max() / 2, mxN = 100;
int n, idx = 2, mini = INF, board[mxN + 2][mxN + 2];
bool vst[mxN + 2][mxN + 2];

int distance(const int& row, const int& col)
{
    memset(vst, false, sizeof(vst));
    queue<pos> q;
    vst[row][col] = true;
    q.emplace(row, col);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (board[nr][nc] == OUT_OF_BOUND || vst[nr][nc] || board[nr][nc] == board[row][col])
                continue;
            if (board[nr][nc] != 0)
                return abs(row - nr) + abs(col - nc) - 1;
            vst[nr][nc] = true;
            q.emplace(nr, nc);
        }
    }
    return INF;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(board, OUT_OF_BOUND, sizeof(board));
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (++idx; board[i][j] == 1)
            {
                queue<pos> q;
                q.emplace(i, j);
                board[i][j] = idx;
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (board[nr][nc] != 1)
                            continue;
                        board[nr][nc] = idx;
                        q.emplace(nr, nc);
                    }
                }
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (board[i][j] != 0)
                mini = min(mini, distance(i, j));
    cout << mini;
    return 0;
}