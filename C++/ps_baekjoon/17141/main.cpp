#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int OUT_OF_BOUND = -1, INF = numeric_limits<int>::max() / 2, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, blank;
vector<vector<int>> board;
vector<pos> candidate_virus, selected_virus;

int spread()
{
    static vector<vector<bool>> vst;
    queue<tuple<int, int, int>> q;
    vst.assign(n + 2, vector<bool>(n + 2));
    int ret = 0, temp_blank = blank;
    for (const auto& [row, col] : selected_virus)
    {
        q.emplace(row, col, 0);
        vst[row][col] = true;
        --temp_blank;
    }
    while (!q.empty() && temp_blank)
    {
        auto [r, c, cnt] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (board[nr][nc] == OUT_OF_BOUND || vst[nr][nc] || board[nr][nc] == 1)
                continue;
            vst[nr][nc] = true;
            --temp_blank;
            q.emplace(nr, nc, cnt + 1);
            ret = max(ret, cnt + 1);
        }
    }
    return temp_blank ? INF : ret;
}

void min_time(int& ret, int level = 0, int idx = 0)
{
    if (level == m)
    {
        ret = min(ret, spread());
        return;
    }
    for (int i = idx; i < candidate_virus.size(); ++i)
    {
        selected_virus.push_back(candidate_virus[i]);
        min_time(ret, level + 1, i + 1);
        selected_virus.pop_back();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.assign(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] != 1)
                ++blank;
            if (board[i][j] == 2)
            {
                board[i][j] = 0;
                candidate_virus.emplace_back(i, j);
            }
        }
    int ret = INF;
    min_time(ret);
    cout << (ret == INF ? -1 : ret);
    return 0;
}