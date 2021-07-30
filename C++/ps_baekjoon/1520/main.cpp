//baekjoon ps 1520

#include <iostream>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
using pos = pair<int, int>;

int main()
{
    constexpr int OUT_OF_BOUND = -1;
    constexpr int dr[] = {0, 0, +1, -1};
    constexpr int dc[] = {+1, -1, 0, 0};
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int row, col;
    cin >> row >> col;
    vector<vector<int>> map(row + 2, vector<int>(col + 2, OUT_OF_BOUND));
    vector<vector<int>> dp(row + 2, vector<int>(col + 2, -1));
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> map[i][j];
    function<int(int, int)> recursion = [&](int now_row, int now_col)
    {
        if (now_row == 1 && now_col == 1)
            return 1;
        if (dp[now_row][now_col] >= 0)
            return dp[now_row][now_col];
        else
            dp[now_row][now_col] = 0;
        int now_cost = map[now_row][now_col];
        for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
        {
            int next_row = now_row + dr[i];
            int next_col = now_col + dc[i];
            int next_cost = map[next_row][next_col];
            if (map[next_row][next_col] == OUT_OF_BOUND)
                continue;
            if (now_cost < next_cost)
                dp[now_row][now_col] += recursion(next_row, next_col);
        }
        return dp[now_row][now_col];
    };
    cout << recursion(row, col);
    return 0;
}