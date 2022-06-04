#include <bits/stdc++.h>
using namespace std;

constexpr int SIZE = 5, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
vector<vector<int>> board(SIZE + 2, vector<int>(SIZE + 2, -1));
set<int> s;

void dfs(int r, int c, int num, int level = 1)
{
    if (level == 6)
    {
        s.insert(num);
        return;
    }
    for (int direction = 0; direction < 4; ++direction)
    {
        int nr = r + dr[direction];
        int nc = c + dc[direction];
        if (board[nr][nc] == -1)
            continue;
        dfs(nr, nc, num * 10 + board[nr][nc], level + 1);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= SIZE; ++i)
        for (int j = 1; j <= SIZE; ++j)
            dfs(i, j, board[i][j]);
    cout << s.size();
    return 0;
}