#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 5e2, mxM = 5e2, out_of_bound = 0, not_visit = -1;
int n, m, cnt, cache[mxN + 2][mxM + 2];
char maze[mxN + 2][mxM + 2];
unordered_map<char, pair<int, int>> direction{{'U', {-1, 0}}, {'R', {0, +1}}, {'D', {+1, 0}}, {'L', {0, -1}}};

bool dfs(int row, int col)
{
    auto &ret = cache[row][col];
    if (maze[row][col] == out_of_bound)
        return true;
    if (ret != not_visit)
        return ret;
    ret = false;
    auto [dr, dc] = direction[maze[row][col]];
    return ret = dfs(row + dr, col + dc);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    memset(cache, not_visit, sizeof(cache));
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> maze[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (dfs(i, j))
                ++cnt;
    cout << cnt;
    return 0;
}