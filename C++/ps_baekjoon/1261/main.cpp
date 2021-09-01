#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxN = 1e2, OUT_OF_BOUND = -1, NOT_VISIT = -1;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int board[mxN + 2][mxN + 2], vst[mxN + 2][mxN + 2];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(board, OUT_OF_BOUND, sizeof(board));
    memset(vst, NOT_VISIT, sizeof(vst));
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char num;
            cin >> num;
            board[i][j] = num - '0';
        }
    queue<pos> q;
    q.emplace(1, 1);
    vst[1][1] = 0;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (board[nr][nc] == 0 && (vst[nr][nc] == NOT_VISIT || vst[r][c] < vst[nr][nc]))
            {
                vst[nr][nc] = vst[r][c];
                q.emplace(nr, nc);
            }
            if (board[nr][nc] == 1 && (vst[nr][nc] == NOT_VISIT || vst[r][c] + 1 < vst[nr][nc]))
            {
                vst[nr][nc] = vst[r][c] + 1;
                q.emplace(nr, nc);
            }
        }
    }
    cout << vst[n][m];
    return 0;
}