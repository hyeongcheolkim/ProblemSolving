#include <bits/stdc++.h>
using namespace std;

constexpr char OUT_OF_BOUND = 0;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m;
vector<vector<char>> board;
vector<vector<bool>> vst;

void solve(bool& ret, int cnt, int start_row, int start_col, int next_row, int next_col)
{
    if (ret)
        return;
    const char& start = board[start_row][start_col];
    for (int direction = 0; direction < 4; ++direction)
    {
        int nr = next_row + dr[direction];
        int nc = next_col + dc[direction];
        if (board[nr][nc] == OUT_OF_BOUND || board[nr][nc] != start)
            continue;
        if (nr == start_row && nc == start_col && cnt + 1 >= 4)
        {
            ret = true;
            return;
        }
        if (vst[nr][nc])
            continue;
        vst[nr][nc] = true;
        solve(ret, cnt + 1, start_row, start_col, nr, nc);
        vst[nr][nc] = false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.assign(n + 2, vector<char>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            bool ret = false;
            vst.assign(n + 2, vector<bool>(m + 2));
            vst[i][j] = true;
            solve(ret, 0, i, j, i, j);
            if (ret)
            {
                cout << "Yes";
                return 0;
            }
        }
    cout << "No";
    return 0;
}