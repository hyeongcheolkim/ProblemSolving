#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n;
vector<vector<int>> board;
vector<vector<int>> dp;

int solve(int row, int col)
{
    int& ret = dp[row][col];
    if (ret != INF)
        return ret;
    if (row == 1 && col == 1)
        return INF;
    if (row == 1 && col == 2)
        return ret = board[row][col];
    if (board[row][col] == INF)
        return ret = INF;
    ret = min({
        solve(row - 1, col - 1),
        solve(row - 1, col),
        solve(row - 1, col + 1),
        solve(row, col - 1)}) + board[row][col];
    return ret;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int idx = 0;
    while (cin >> n, n != 0)
    {
        board.assign(n + 2, vector<int>(3 + 2, INF));
        dp.assign(n + 2, vector<int>(3 + 2, INF));
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= 3; ++j)
                cin >> board[i][j];
        cout << ++idx << ". " << solve(n, 2) << '\n';
    }
    return 0;
}