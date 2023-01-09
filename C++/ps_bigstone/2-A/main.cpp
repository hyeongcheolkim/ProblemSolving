#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m;
vector<vector<char>> board;
vector<vector<int>> vst;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, decltype(board)::value_type(m + 2));
    vst.resize(n + 2, decltype(vst)::value_type(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    vst[1][1] = 1;
    q.emplace(1, 1);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (board[nr][nc] == '0' || board[nr][nc] == 0)
                continue;
            if (vst[nr][nc])
                continue;
            vst[nr][nc] = vst[r][c] + 1;
            q.emplace(nr, nc);
        }
    }
    cout << vst[n][m];
    return 0;
}