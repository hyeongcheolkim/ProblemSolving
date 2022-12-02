#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, INF = numeric_limits<int>::max() / 2;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, res;
int hx, hy, ex, ey;
vector<vector<int>> board;
vector<vector<vector<int>>> vst;
queue<pair<int, int>> q0, q1;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> hx >> hy >> ex >> ey;
    board.resize(n + 2, decltype(board)::value_type(m + 2, OUT_OF_BOUND));
    vst.resize(n + 2, decltype(vst)::value_type(m + 2, decltype(vst)::value_type::value_type(2, INF)));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    q0.emplace(hx, hy);
    vst[hx][hy][0] = 0;
    while (!q0.empty())
    {
        auto [r, c] = q0.front();
        const auto& now_cnt = vst[r][c][0];
        q0.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (vst[nr][nc][0] > now_cnt + 1 && board[nr][nc] == 0)
            {
                vst[nr][nc][0] = now_cnt + 1;
                q0.emplace(nr, nc);
            }
            if (vst[nr][nc][1] > now_cnt + 1 && board[nr][nc] == 1)
            {
                vst[nr][nc][1] = now_cnt + 1;
                q1.emplace(nr, nc);
            }
        }
    }
    while (!q1.empty())
    {
        auto [r, c] = q1.front();
        const auto& now_cnt = vst[r][c][1];
        q1.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (vst[nr][nc][1] > now_cnt + 1 && board[nr][nc] == 0)
            {
                vst[nr][nc][1] = now_cnt + 1;
                q1.emplace(nr, nc);
            }
        }
    }
    res = min(vst[ex][ey][0], vst[ex][ey][1]);
    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}