#include <bits/stdc++.h>
using namespace std;

int n, m, k, INF = numeric_limits<int>::max() / 2;
vector<vector<char>> board;
constexpr int dr[]{0, 0, +1, -1, 0}, dc[]{+1, -1, 0, 0, 0};
int vst[1000 + 2][1000 + 2][10 + 1][2];
queue<tuple<int, int, int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    board.resize(n + 2, vector<char>(m + 2, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];

    for (int i = 0; i < 1000 + 2; ++i)
        for (int j = 0; j < 1000 + 2; ++j)
            for (int k = 0; k < 10 + 1; ++k)
                vst[i][j][k][0] = vst[i][j][k][1] = INF;

    vst[1][1][0][0] = 1;
    q.emplace(1, 1, 0, 0);
    while (!q.empty())
    {
        auto [r, c, w, isNight] = q.front();
        q.pop();
        int ncnt = vst[r][c][w][isNight];
        int nNight = 1 ^ isNight;
        if (r == n && c == m)
        {
            cout << ncnt;
            return 0;
        }
        for (int direction = 0; direction < 5; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];

            if (board[nr][nc] == 0)
                continue;
            if (board[nr][nc] == '1' && w < k && isNight == 0 && ncnt + 1 < vst[nr][nc][w + 1][nNight])
            {
                vst[nr][nc][w + 1][nNight] = ncnt + 1;
                q.emplace(nr, nc, w + 1, nNight);
            }
            if ((board[nr][nc] == '0' || vst[nr][nc][w][isNight] != INF) && ncnt + 1 < vst[nr][nc][w][nNight])
            {
                vst[nr][nc][w][nNight] = ncnt + 1;
                q.emplace(nr, nc, w, nNight);
            }
        }
    }
    cout << -1;
    return 0;
}