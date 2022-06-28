#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int m, n;
vector<vector<int>> board;
vector<vector<vector<int>>> vst;
int start_direct, finish_direct;
int start_row, start_col, finish_row, finish_col;
queue<tuple<int, int, int, int>> q;
map<int, int> direction_correcter{
    {1, 1},
    {4, 2},
    {2, 3},
    {3, 4},
};
map<int, pair<int, int>> diff{
    {1, {0, +1}},
    {2, {-1, 0}},
    {3, {0, -1}},
    {4, {+1, 0}},
};

int turn_clock(int direct)
{
    int ret = --direct;
    if (ret <= 0)
        ret = 4;
    return ret;
}

int turn_conuter_clock(int direct)
{
    int ret = ++direct;
    if (ret >= 5)
        ret = 1;
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    board.resize(m + 2, vector<int>(n + 2));
    vst.resize(m + 2, vector<vector<int>>(n + 2, vector<int>(4 + 1, INF)));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    cin >> start_row >> start_col >> start_direct;
    cin >> finish_row >> finish_col >> finish_direct;
    start_direct = direction_correcter[start_direct];
    finish_direct = direction_correcter[finish_direct];
    q.emplace(start_row, start_col, start_direct, 0);
    vst[start_row][start_col][start_direct] = 0;
    while (!q.empty())
    {
        auto [r, c, direct, cnt] = q.front();
        q.pop();
        auto turn_clock_direct = turn_clock(direct);
        auto turn_counter_clock_direct = turn_conuter_clock(direct);
        if (vst[r][c][turn_clock_direct] > cnt + 1)
        {
            vst[r][c][turn_clock_direct] = cnt + 1;
            q.emplace(r, c, turn_clock_direct, cnt + 1);
        }
        if (vst[r][c][turn_counter_clock_direct] > cnt + 1)
        {
            vst[r][c][turn_counter_clock_direct] = cnt + 1;
            q.emplace(r, c, turn_counter_clock_direct, cnt + 1);
        }
        auto [dr, dc] = diff[direct];
        for (int weight = 1; weight <= 3; ++weight)
        {
            int nr = r + weight * dr;
            int nc = c + weight * dc;
            if (!(1 <= nr && nr <= m && 1 <= nc && nc <= n))
                continue;
            if ([&]()->bool {
                for (int i = 1; i <= weight; ++i)
                {
                    int ir = r + i * dr;
                    int ic = c + i * dc;
                    if (board[ir][ic] != 0)
                        return true;
                }
                return false;
            }()) continue;
            if (board[nr][nc] == 1)
                continue;
            if (vst[nr][nc][direct] > cnt + 1)
            {
                vst[nr][nc][direct] = cnt + 1;
                q.emplace(nr, nc, direct, cnt + 1);
            }
        }
    }
    cout << vst[finish_row][finish_col][finish_direct];
    return 0;
}