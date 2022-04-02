#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{+1, +1, 0}, dc[]{+1, 0, +1};
int n, m;
vector<vector<int>> maze, dp;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    maze.resize(n + 2, vector<int>(m + 2, -1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> maze[i][j];
    dp.assign(maze.begin(), maze.end());
    dp[1][1] = maze[1][1];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            for (int direction = 0; direction < 3; ++direction)
            {
                int nr = i + dr[direction];
                int nc = j + dc[direction];
                if (maze[nr][nc] == -1)
                    continue;
                dp[nr][nc] = max(dp[nr][nc], dp[i][j] + maze[nr][nc]);
            }
    cout << dp[n][m];
    return 0;
}