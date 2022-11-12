#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -11111;
int n, m, k, res = -numeric_limits<int>::max() / 2;
vector<vector<int>> board;
vector<vector<bool>> vst;
vector<pair<int, int>> pos;

bool is_valid_space(int row, int col)
{
    constexpr static int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
    for (int direction = 0; direction < 4; ++direction)
    {
        int nr = row + dr[direction];
        int nc = col + dc[direction];
        if (board[nr][nc] == OUT_OF_BOUND)
            continue;
        if (vst[nr][nc])
            return false;
    }
    return true;
}

void solve(int pos_idx = 0, int acc = 0, int cnt = 0)
{
    if (cnt == k)
    {
        res = max(res, acc);
        return;
    }
    if (pos_idx >= n * m)
        return;
    const auto& [row, col] = pos[pos_idx];
    solve(pos_idx + 1, acc, cnt);
    if (is_valid_space(row, col))
    {
        vst[row][col] = true;
        solve(pos_idx + 1, acc + board[row][col], cnt + 1);
        vst[row][col] = false;
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    board.resize(n + 2, vector<int>(m + 2, OUT_OF_BOUND));
    vst.resize(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> board[i][j];
            pos.emplace_back(i, j);
        }
    solve();
    cout << res;
    return 0;
}