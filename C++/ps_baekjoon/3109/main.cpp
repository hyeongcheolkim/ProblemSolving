#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{-1, 0, +1}, dc[]{+1, +1, +1};
int r, c, cnt;
vector<vector<char>> board;
vector<vector<bool>> vst;

bool dfs(int row, int col = 1)
{
    if (col == c)
    {
        ++cnt;
        return true;
    }
    for (int direction = 0; direction < 3; ++direction)
    {
        int nr = row + dr[direction];
        int nc = col + dc[direction];
        if (vst[nr][nc] || board[nr][nc] == 0 || board[nr][nc] == 'x')
            continue;
        vst[nr][nc] = true;
        if (dfs(nr, nc))
            return true;
    }
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    board.resize(r + 2, vector<char>(c + 2));
    vst.resize(r + 2, vector<bool>(c + 2));
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= r; ++i)
        dfs(i);
    cout << cnt;
    return 0;
}