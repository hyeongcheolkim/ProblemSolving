#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 20, MAX_MOVE_CNT = 5;
int n, res = 0;
vector<vector<int>> board;
bool is_uni[mxN + 2][mxN + 2];

int move_block(int, int, int, int);
int left();
int right();
int up();
int down();

void dfs(int level = 0, int maxi = 0)
{
    if (level == MAX_MOVE_CNT)
    {
        res = max(res, maxi);
        return;
    }
    for (int(*e)() : {left, right, up, down})
    {
        auto tmp = board;
        int ret = (*e)();
        dfs(level + 1, max(maxi, ret));
        board.swap(tmp);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 2, vector<int>(n + 2, -1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> board[i][j];
    dfs();
    cout << res;
    return 0;
}

int move_block(int row, int col, int dr, int dc)
{
    int value = board[row][col];
    board[row][col] = 0;
    while (board[row + dr][col + dc] == 0)
    {
        row += dr;
        col += dc;
    }
    board[row][col] = value;
    if (board[row + dr][col + dc] == value && !is_uni[row + dr][col + dc])
    {
        board[row][col] = 0;
        row += dr;
        col += dc;
        board[row][col] *= 2;
        is_uni[row][col] = true;
    }
    return board[row][col];
}

int left()
{
    memset(is_uni, 0, sizeof(is_uni));
    int maxi = 0;
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            maxi = max(maxi, move_block(i, j, 0, -1));
    return maxi;
}

int right()
{
    memset(is_uni, 0, sizeof(is_uni));
    int maxi = 0;
    for (int j = n; j >= 1; --j)
        for (int i = 1; i <= n; ++i)
            maxi = max(maxi, move_block(i, j, 0, +1));
    return maxi;
}

int up()
{
    memset(is_uni, 0, sizeof(is_uni));
    int maxi = 0;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            maxi = max(maxi, move_block(i, j, -1, 0));
    return maxi;
}

int down()
{
    memset(is_uni, 0, sizeof(is_uni));
    int maxi = 0;
    for (int i = n; i >= 1; --i)
        for (int j = 1; j <= n; ++j)
            maxi = max(maxi, move_block(i, j, +1, 0));
    return maxi;
}