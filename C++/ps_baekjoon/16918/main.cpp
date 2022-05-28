#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1, 0}, dc[]{+1, -1, 0, 0, 0};
int r, c, n;
vector<vector<char>> board;
queue<pair<int, int>> target;

void set_target()
{
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (board[i][j] == 'O')
                target.emplace(i, j);
}

void put_bomb()
{
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (board[i][j] == '.')
                board[i][j] = 'O';
}

void explosion()
{
    while (!target.empty())
    {
        auto [r, c] = target.front();
        target.pop();
        for (int direction = 0; direction < 5; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            board[nr][nc] = '.';
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> n;
    board.resize(r + 2, vector<char>(c + 2));
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            cin >> board[i][j];
    for (int i = 0; i < n - 1; ++i)
    {
        if (i % 2 == 0)
        {
            set_target();
            put_bomb();
        }
        if (i % 2 == 1)
            explosion();
    }
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}