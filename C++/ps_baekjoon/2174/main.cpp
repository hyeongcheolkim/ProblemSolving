#include <bits/stdc++.h>
using namespace std;

constexpr pair<int, int> OUT_OF_BOUND = {-3, -3}, EMPTY = {-4, -4};
int row_size, col_size, n, m;
vector<pair<int, int>> robot_pos;
vector<vector<pair<int, int>>> board;
map<char, int> direct_code{
    {'N', 0},
    {'E', 1},
    {'S', 2},
    {'W', 3},
};
map<int, pair<int, int>> diff{
    {0, {-1, 0}},
    {1, {0, +1}},
    {2, {+1, 0}},
    {3, {0, -1}},
};

int rotate_counter_clock(int direct, int cnt)
{
    cnt %= 4;
    while (cnt--)
        if (--direct < 0)
            direct = 3;
    return direct;
}

int rotate_clock(int direct, int cnt)
{
    cnt %= 4;
    while (cnt--)
        if (++direct > 3)
            direct = 0;
    return direct;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> col_size >> row_size >> n >> m;
    board.resize(row_size + 2, vector<pair<int, int>>(col_size + 2, OUT_OF_BOUND));
    for (int row = 1; row <= row_size; ++row)
        for (int col = 1; col <= col_size; ++col)
            board[row][col] = EMPTY;
    robot_pos.resize(n + 1);
    for (int num = 1; num <= n; ++num)
    {
        int x, y;
        char direct;
        cin >> x >> y;
        int row = row_size + 1 - y;
        int col = x;
        robot_pos[num] = {row, col};
        cin >> direct;
        board[row][col] = {num, direct_code[direct]};
    }
    while (m--)
    {
        int num, cnt;
        char oper;
        cin >> num >> oper >> cnt;
        auto [r, c] = robot_pos[num];
        auto [ignore, direct] = board[r][c];
        switch (oper)
        {
            case 'L':
            {
                direct = rotate_counter_clock(direct, cnt);
                board[r][c] = {num, direct};
                break;
            }
            case 'R':
            {
                direct = rotate_clock(direct, cnt);
                board[r][c] = {num, direct};
                break;
            }
            case 'F':
            {
                board[r][c] = EMPTY;
                auto [dr, dc] = diff[direct];
                while (cnt--)
                {
                    r += dr;
                    c += dc;
                    if (board[r][c] == OUT_OF_BOUND)
                    {
                        cout << "Robot " << num << " crashes into the wall";
                        exit(0);
                    }
                    if (board[r][c] != EMPTY)
                    {
                        cout << "Robot " << num << " crashes into robot " << board[r][c].first;
                        exit(0);
                    }
                }
                board[r][c] = {num, direct};
                robot_pos[num] = {r, c};
                break;
            }
            default:
                break;
        }

    }
    cout << "OK";
    return 0;
}