#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n;
vector<vector<char>> board;
vector<pair<int, int>> empty_space, teacher;

bool check()
{
    for (const auto& [row, col] : teacher)
        for (int direction = 0; direction < 4; ++direction)
        {
            int r = row;
            int c = col;
            while (board[r][c] != 'O' && board[r][c] != 0)
            {
                if (board[r][c] == 'S')
                    return false;
                r += dr[direction];
                c += dc[direction];
            }
        }
    return true;
}

void dfs(int idx = 0, int level = 0)
{
    if (level == 3)
    {
        if (check())
        {
            cout << "YES";
            exit(0);
        }
        return;
    }
    for (int i = idx; i < empty_space.size(); ++i)
    {
        auto [r, c] = empty_space[i];
        board[r][c] = 'O';
        dfs(i + 1, level + 1);
        board[r][c] = 'X';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    board.resize(n + 2, vector<char>(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'X')
                empty_space.emplace_back(i, j);
            if (board[i][j] == 'T')
                teacher.emplace_back(i, j);
        }
    dfs();
    cout << "NO";
    return 0;
}