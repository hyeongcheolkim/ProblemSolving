#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int OUT_OF_BOUND = -1;
constexpr int INF = numeric_limits<int>::max() / 2, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, blank, res = INF;
vector<vector<int>> board;
vector<pos> viruses, active_viruses;

int spread();
void dfs(int = 0, int = 0);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.assign(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 2)
                viruses.emplace_back(i, j);
            if (board[i][j] == 0)
                ++blank;
        }
    dfs();
    cout << (res == INF ? -1 : res);
    return 0;
}

void dfs(int level, int idx)
{
    if (level == m)
    {
        res = min(res, spread());
        return;
    }
    for (int i = idx; i < viruses.size(); ++i)
    {
        active_viruses.push_back(viruses[i]);
        dfs(level + 1, i + 1);
        active_viruses.pop_back();
    }
}

int spread()
{
    static vector<vector<bool>> vst;
    int maxi = 0;
    int temp_blank = blank;
    queue<tuple<int, int, int>> q;
    vst.assign(n + 2, vector<bool>(n + 2, false));
    for (const auto& [r, c] : active_viruses)
    {
        q.emplace(r, c, 0);
        vst[r][c] = true;
    }
    while (!q.empty() && temp_blank)
    {
        auto [r, c, cnt] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (vst[nr][nc] || board[nr][nc] == OUT_OF_BOUND || board[nr][nc] == 1)
                continue;
            if (board[nr][nc] == 0)
                --temp_blank;
            vst[nr][nc] = true;
            q.emplace(nr, nc, cnt + 1);
            maxi = max(maxi, cnt + 1);
        }
    }
    return (temp_blank == 0 ? maxi : INF);
}