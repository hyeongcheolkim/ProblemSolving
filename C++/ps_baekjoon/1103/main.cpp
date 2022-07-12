#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0}, HOLE = -1;
int n, m, maxi = 0;
vector<vector<int>> board;
vector<vector<int>> dp;
vector<vector<bool>> vst, cycle_checked;
queue<pos> q;

bool find_cycle(pos now = pos{1, 1})
{
    auto [r, c] = now;
    int weight = board[r][c];
    for (int direction = 0; direction < 4; ++direction)
    {
        int nr = r + weight * dr[direction];
        int nc = c + weight * dc[direction];
        if (!(1 <= nr && nr <= n && 1 <= nc && nc <= m) || board[nr][nc] == HOLE)
            continue;
        if (cycle_checked[nr][nc])
            continue;
        if (vst[nr][nc])
            return true;
        vst[nr][nc] = true;
        if (find_cycle(pos{nr, nc}))
            return true;
        vst[nr][nc] = false;
        cycle_checked[nr][nc] = true;
    }
    return false;
}

void bfs()
{
    q.emplace(1, 1);
    while (!q.empty())
    {
        auto [r, c] = q.front();
        int weight = board[r][c];
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + weight * dr[direction];
            int nc = c + weight * dc[direction];
            if (!(1 <= nr && nr <= n && 1 <= nc && nc <= m))
            {
                maxi = max(maxi, dp[r][c] + 1);
                continue;
            }
            if (dp[nr][nc] < dp[r][c] + 1)
            {
                dp[nr][nc] = dp[r][c] + 1;
                maxi = max(maxi, dp[nr][nc]);
                if (board[nr][nc] == HOLE)
                    continue;
                q.emplace(nr, nc);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(m + 2));
    dp.resize(n + 2, vector<int>(m + 2));
    vst.resize(n + 2, vector<bool>(m + 2));
    cycle_checked.resize(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char buff;
            cin >> buff;
            if (buff == 'H')
                board[i][j] = HOLE;
            else
                board[i][j] = buff - '0';
        }
    if (find_cycle())
    {
        cout << -1;
        exit(0);
    }
    bfs();
    cout << maxi;
    return 0;
}