#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

int n, m, k;
vector<vector<int>> board, dp;
pos waypoint = {1, 1};

int solve(int row, int col)
{
    int& ret = dp[row][col];
    if (ret != 0)
        return ret;
    if (row <= 1 || col <= 1)
        return ret = 1;
    return ret = solve(row - 1, col) + solve(row, col - 1);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    board.resize(n + 2, vector<int>(m + 2));
    dp.resize(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            board[i][j] = (i - 1) * m + j;
            if (board[i][j] == k)
                waypoint = {i, j};
        }
    cout << solve(waypoint.first, waypoint.second) * solve(n - waypoint.first + 1, m - waypoint.second + 1);
    return 0;
}