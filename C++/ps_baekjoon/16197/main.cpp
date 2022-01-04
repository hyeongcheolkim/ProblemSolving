#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr char OUT_OF_BOUND = 0;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m;
vector<vector<char>> board;
vector<pos> coins;
queue<tuple<pos, pos, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.assign(n + 2, vector<char>(m + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'o')
                coins.emplace_back(i, j);
        }
    q.emplace(coins[0], coins[1], 0);
    while (!q.empty())
    {
        auto [pos1, pos2, cnt] = q.front();
        auto [r1, c1] = pos1;
        auto [r2, c2] = pos2;
        if (cnt >= 10)
            break;
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr1 = r1 + dr[direction];
            int nc1 = c1 + dc[direction];
            int nr2 = r2 + dr[direction];
            int nc2 = c2 + dc[direction];
            if (board[nr1][nc1] == '#')
            {
                nr1 = r1;
                nc1 = c1;
            }
            if (board[nr2][nc2] == '#')
            {
                nr2 = r2;
                nc2 = c2;
            }
            if (board[nr1][nc1] == OUT_OF_BOUND && board[nr2][nc2] == OUT_OF_BOUND)
                continue;
            if (board[nr1][nc1] == OUT_OF_BOUND ^ board[nr2][nc2] == OUT_OF_BOUND)
            {
                cout << cnt + 1;
                exit(0);
            }
            q.emplace(pos{nr1, nc1}, pos{nr2, nc2}, cnt + 1);
        }
    }
    cout << -1;
    return 0;
}