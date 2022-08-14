#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, k, score;
vector<vector<int>> board;
enum { EAST, SOUTH, WEST, NORTH };

struct Dice
{
    int row, col;
    int top, bot, left, right, up, down;
    int direct;
    Dice()
    {
        row = col = 1;
        top = 1;
        bot = 6;
        left = 4;
        right = 3;
        up = 2;
        down = 5;
        direct = EAST;
    }
    void rotate_clock()
    {
        if (++direct > 3)
            direct = EAST;
    }
    void rotate_counter_clock()
    {
        if (--direct < 0)
            direct = NORTH;
    }
    void move_east()
    {
        int tmp = top;
        top = left;
        left = bot;
        bot = right;
        right = tmp;
        ++col;
    }
    void move_west()
    {
        int tmp = top;
        top = right;
        right = bot;
        bot = left;
        left = tmp;
        --col;
    }
    void move_north()
    {
        int tmp = top;
        top = down;
        down = bot;
        bot = up;
        up = tmp;
        --row;
    }
    void move_south()
    {
        int tmp = top;
        top = up;
        up = bot;
        bot = down;
        down = tmp;
        ++row;
    }
    void move_dice()
    {
        if (direct == EAST)
            move_east();
        else if (direct == WEST)
            move_west();
        else if (direct == NORTH)
            move_north();
        else if (direct == SOUTH)
            move_south();
        if (board[row][col] == 0)
        {
            rotate_clock();
            rotate_clock();
            move_dice();
            move_dice();
        }
    }
};

int calculate_score(int row, int col)
{
    const int& now_num = board[row][col];
    queue<pair<int, int>> q;
    vector<vector<bool>> vst(n + 2, vector<bool>(m + 2));
    int cnt = 0;
    q.emplace(row, col);
    vst[row][col] = true;
    ++cnt;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (board[nr][nc] == 0 || vst[nr][nc] || board[nr][nc] != now_num)
                continue;
            q.emplace(nr, nc);
            vst[nr][nc] = true;
            ++cnt;
        }
    }
    return now_num * cnt;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    board.resize(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    Dice dice{};
    while (k--)
    {
        dice.move_dice();
        score += calculate_score(dice.row, dice.col);
        if (dice.bot > board[dice.row][dice.col])
            dice.rotate_clock();
        if (dice.bot < board[dice.row][dice.col])
            dice.rotate_counter_clock();
    }
    cout << score;
    return 0;
}