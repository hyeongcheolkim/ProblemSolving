#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int r, c, wolf_total, lamb_total;
vector<vector<char>> board;
vector<vector<bool>> vst;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    board.resize(r + 2, vector<char>(c + 2));
    vst.resize(r + 2, vector<bool>(c + 2));
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'o')
                ++lamb_total;
            if (board[i][j] == 'v')
                ++wolf_total;
        }
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (!vst[i][j] && board[i][j] == 'v')
            {
                q.emplace(i, j);
                vst[i][j] = true;
                int wolf_cnt = 1;
                int lamb_cnt = 0;
                while (!q.empty())
                {
                    auto [row, col] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = row + dr[direction];
                        int nc = col + dc[direction];
                        if (vst[nr][nc] || board[nr][nc] == '#' || board[nr][nc] == 0)
                            continue;
                        vst[nr][nc] = true;
                        if (board[nr][nc] == 'v')
                            ++wolf_cnt;
                        if (board[nr][nc] == 'o')
                            ++lamb_cnt;
                        q.emplace(nr, nc);
                    }
                }
                if (lamb_cnt > wolf_cnt)
                    wolf_total -= wolf_cnt;
                else
                    lamb_total -= lamb_cnt;
            }
    cout << lamb_total << ' ' << wolf_total;
    return 0;
}