//baekjoon ps 1937

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
    constexpr int dr[] = {+1, -1, 0, 0};
    constexpr int dc[] = {0, 0, +1, -1};
    constexpr int OUT_OF_BOUND = -1;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, res = 0;
    cin >> n;
    vector<vector<int>> map(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> map[i][j];
    function<int(int, int)> dfs = [&](int now_row, int now_col)
    {
        int &ret = dp[now_row][now_col];
        if (ret != 0)
            return ret;
        ret = 1;
        for (int direction = 0; direction < 4; ++direction)
        {
            int next_row = now_row + dr[direction];
            int next_col = now_col + dc[direction];
            if (map[next_row][next_col] == OUT_OF_BOUND)
                continue;
            if (map[now_row][now_col] < map[next_row][next_col])
                ret = max(ret, dfs(next_row, next_col) + 1);
        }
        return ret;
    };
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (dp[i][j] == 0)
                res = max(res, dfs(i, j));
    cout << res;
    return 0;
}