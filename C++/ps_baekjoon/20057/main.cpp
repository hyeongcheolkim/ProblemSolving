#include <bits/stdc++.h>
using namespace std;

int n, direction, res;
vector<vector<int>> board;
pair<int, int> tornado;
map<int, pair<int, int>> diff{
    {0, {0, -1}},
    {1, {+1, 0}},
    {2, {0, +1}},
    {3, {-1, 0}},
};

bool move_tornado()
{
    static int step = 1, move_cnt = 0, direct_cnt = 0;
    auto& [r, c] = tornado;
    const auto& [dr, dc] = diff[direction];
    if (step >= n)
        return false;
    r += dr;
    c += dc;
    if (++move_cnt == step)
    {
        move_cnt = 0;
        if (++direction > 3)
            direction = 0;
        ++direct_cnt;
        if (step < n - 1 && direct_cnt == 2)
        {
            direct_cnt = 0;
            ++step;
        }
        else if (step == n - 1 && direct_cnt == 3)
        {
            direct_cnt = 0;
            ++step;
        }
    }
    return true;
}

int put_sand(int row, int col, int ea)
{
    if (!(0 <= row && row < n && 0 <= col && col < n))
        return ea;
    board[row][col] += ea;
    return 0;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> board[i][j];
    tornado = {n / 2, n / 2};
    int prev_direction;
    while (prev_direction = direction, move_tornado())
    {
        const auto& [dr, dc] = diff[prev_direction];
        const auto& [r, c] = tornado;
        const auto& total_sand = board[tornado.first][tornado.second];
        int away_sand = 0;
        int sand1 = total_sand * 1 / 100;
        int sand2 = total_sand * 2 / 100;
        int sand5 = total_sand * 5 / 100;
        int sand7 = total_sand * 7 / 100;
        int sand10 = total_sand * 10 / 100;
        away_sand += put_sand(r + dr * 2, c + dc * 2, sand5);
        away_sand += put_sand(r + dr + dc, c + dc + dr, sand10);
        away_sand += put_sand(r + dr - dc, c + dc - dr, sand10);
        away_sand += put_sand(r + dc, c + dr, sand7);
        away_sand += put_sand(r - dc, c - dr, sand7);
        away_sand += put_sand(r + 2 * dc, c + 2 * dr, sand2);
        away_sand += put_sand(r - 2 * dc, c - 2 * dr, sand2);
        away_sand += put_sand(r - dr + dc, c - dc + dr, sand1);
        away_sand += put_sand(r - dr - dc, c - dc - dr, sand1);
        away_sand += put_sand(r + dr, c + dc, total_sand - sand5 - (sand10 + sand7 + sand2 + sand1) * 2);
        res += away_sand;
        board[r][c] = 0;
    }
    cout << res;
    return 0;
}