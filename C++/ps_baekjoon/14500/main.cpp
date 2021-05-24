//baekjoon ps 14500

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int dr[] = {0, 0, -1, +1};
constexpr int dc[] = {-1, +1, 0, 0};
vector<vector<int>> map;
vector<vector<bool>> check;
int res;

void dfs(int level, int row, int col, int sum)
{
    if (level == 3)
    {
        res = max(res, sum);
        return;
    }
    for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
    {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (check[nr][nc])
            continue;
        check[nr][nc] = true;
        dfs(level + 1, nr, nc, sum + map[nr][nc]);
        check[nr][nc] = false;
    }
}

void fnc(int row, int col)
{
    bool now = !check[row][col];
    bool up = !check[row - 1][col];
    bool down = !check[row + 1][col];
    bool left = !check[row][col - 1];
    bool right = !check[row][col + 1];
    int val_now = map[row][col];
    int val_up = map[row - 1][col];
    int val_down = map[row + 1][col];
    int val_left = map[row][col - 1];
    int val_right = map[row][col + 1];

    if (now && down && left && right)
        res = max(res, val_now + val_down + val_left + val_right);
    if (now && up && left && right)
        res = max(res, val_now + val_up + val_left + val_right);
    if (now && up && down & right)
        res = max(res, val_now + val_up + val_down + val_right);
    if (now && up && down && left)
        res = max(res, val_now + val_up + val_down + val_left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map = vector<vector<int>>(n + 2, vector<int>(m + 2));
    check = vector<vector<bool>>(n + 2, vector<bool>(m + 2, true));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            check[i][j] = false;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            check[i][j] = true;
            dfs(0, i, j, map[i][j]);
            check[i][j] = false;
            fnc(i, j);
        }
    cout << res;
    return 0;
}