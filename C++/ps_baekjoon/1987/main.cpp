//baekjoon ps 1987

#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int idx(char c) { return c - 'A'; }

int main()
{
    constexpr int dr[] = {0, 0, +1, -1};
    constexpr int dc[] = {+1, -1, 0, 0};
    constexpr char OUT_OF_BOUND = 0;
    ios_base::sync_with_stdio(false);
    int row, col;
    int res = 0;
    cin >> row >> col;
    vector<vector<char>> map(row + 2, vector<char>(col + 2, OUT_OF_BOUND));
    for (int i = 1; i <= row; i++)
        for (int j = 1; j <= col; j++)
            cin >> map[i][j];
    vector<vector<bool>> visited(row + 2, vector<bool>(col + 2, 0));
    vector<bool> check('Z' - 'A' + 1);
    visited[1][1] = true;
    check[idx(map[1][1])] = true;
    function<void(int, int, int)> dfs = [&](int now_row, int now_col, int sum)
    {
        for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
        {
            int next_row = now_row + dr[i];
            int next_col = now_col + dc[i];
            if (map[next_row][next_col] == OUT_OF_BOUND || visited[next_row][next_col] || check[idx(map[next_row][next_col])])
                continue;
            visited[next_row][next_col] = true;
            check[idx(map[next_row][next_col])] = true;
            dfs(next_row, next_col, sum + 1);
            visited[next_row][next_col] = false;
            check[idx(map[next_row][next_col])] = false;
        }
        res = max(res, sum);
    };
    dfs(1, 1, 1);
    cout << res;
    return 0;
}