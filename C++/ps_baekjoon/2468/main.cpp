//baekjoon ps 2468

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <utility>

using namespace std;

int main()
{
    constexpr int dr[] = {+1, -1, 0, 0};
    constexpr int dc[] = {0, 0, +1, -1};
    ios_base::sync_with_stdio(false);
    int n, maxi = -1, mini = numeric_limits<int>::max(), res = 1;
    cin >> n;
    vector<vector<int>> map(n + 2, vector<int>(n + 2, -1));
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
            maxi = max(maxi, map[i][j]);
            mini = min(mini, map[i][j]);
        }
    for (int height = mini; height <= maxi; height++)
    {
        int cnt = 0;
        auto check = vector<vector<bool>>(n + 2, vector<bool>(n + 2, false));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (map[i][j] == height)
                    map[i][j] = -1;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (!check[i][j] && map[i][j] != -1)
                {
                    cnt++;
                    q.push({i, j});
                    check[i][j] = true;
                    while (!q.empty())
                    {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        for (int d = 0; d < sizeof(dr) / sizeof(int); d++)
                        {
                            int nextrow = row + dr[d];
                            int nextcol = col + dc[d];
                            if (!check[nextrow][nextcol] && map[nextrow][nextcol] != -1)
                            {
                                check[nextrow][nextcol] = true;
                                q.push({nextrow, nextcol});
                            }
                        }
                    }
                }
        res = max(res, cnt);
    }
    cout << res;
    return 0;
}