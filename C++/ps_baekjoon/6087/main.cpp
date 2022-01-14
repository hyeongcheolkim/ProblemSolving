#include <bits/stdc++.h>
using namespace std;

enum class direction { not_set, up, right, down, left };
map<direction, pair<int, int>> diff
{
    {direction::up, {-1, 0}},
    {direction::right, {0, +1}},
    {direction::down, {+1, 0}},
    {direction::left, {0, -1}},
};
constexpr char OUT_OF_BOUND = 0;
constexpr int INF = numeric_limits<int>::max() / 2;
int w, h;
vector<vector<char>> board;
vector<vector<int>> vst;
vector<pair<int, int>> target;
queue <tuple<int, int, direction, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> w >> h;
    board.resize(h + 2, vector<char>(w + 2, OUT_OF_BOUND));
    vst.resize(h + 2, vector<int>(w + 2, INF));
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'C')
            {
                target.emplace_back(i, j);
                board[i][j] = '.';
            }
        }
    const auto& start = target.front();
    const auto& end = target.back();
    vst[start.first][start.second] = 0;
    q.emplace(start.first, start.second, direction::not_set, 0);
    while (!q.empty())
    {
        auto [r, c, now_direction, cnt] = q.front();
        q.pop();
        if (pair{r, c} == end)
            continue;
        for (const auto& next_direction : {direction::up, direction::right, direction::left, direction::down})
        {
            auto [dr, dc] = diff[next_direction];
            int nr = r + dr;
            int nc = c + dc;
            if (board[nr][nc] == OUT_OF_BOUND || board[nr][nc] == '*' || vst[nr][nc] <= cnt)
                continue;
            if (now_direction == direction::not_set || now_direction == next_direction)
            {
                q.emplace(nr, nc, next_direction, cnt);
                vst[nr][nc] = cnt;
            }
            else
            {
                q.emplace(nr, nc, next_direction, cnt + 1);
                vst[nr][nc] = cnt + 1;
            }
        }
    }
    cout << vst[end.first][end.second];
    return 0;
}