#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int r, c;
vector<vector<char>> board;
vector<pair<int, int>> sheep;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    board.resize(r + 2, decltype(board)::value_type(c + 2));
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'S')
                sheep.emplace_back(i, j);
        }
    for (const auto& [row, col] : sheep)
    {
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = row + dr[direction];
            int nc = col + dc[direction];
            if (board[nr][nc] == 0 || board[nr][nc] == 'S' || board[nr][nc] == 'D')
                continue;
            if (board[nr][nc] == 'W')
            {
                cout << 0;
                exit(0);
            }
            board[nr][nc] = 'D';
        }
    }
    cout << 1 << '\n';
    for (int i = 1; i <= r; ++i)
    {
        for (int j = 1; j <= c; ++j)
            cout << board[i][j];
        cout << '\n';
    }
    return 0;
}