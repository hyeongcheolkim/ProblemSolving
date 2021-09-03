#include <bits/stdc++.h>
using namespace std;
using pos = tuple<int, int, int>;

constexpr char out_of_bound = 0;
constexpr int not_visit = -1, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0}, INF = numeric_limits<int>::max() / 2;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> terrain(n + 2, vector<char>(m + 2, out_of_bound));
    vector<vector<vector<int>>> vst(n + 2, vector<vector<int>>(m + 2, vector<int>(k + 1, not_visit)));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> terrain[i][j];
    queue<pos> q;
    vst[1][1][0] = 1;
    q.emplace(1, 1, 0);
    while (!q.empty())
    {
        auto [r, c, wall] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (terrain[nr][nc] == out_of_bound)
                continue;
            if (terrain[nr][nc] == '0' && (vst[nr][nc][wall] == not_visit || vst[r][c][wall] + 1 < vst[nr][nc][wall]))
            {
                vst[nr][nc][wall] = vst[r][c][wall] + 1;
                q.emplace(nr, nc, wall);
            }
            if (wall >= k)
                continue;
            if (terrain[nr][nc] == '1' && (vst[nr][nc][wall + 1] == not_visit || vst[r][c][wall] + 1 < vst[nr][nc][wall + 1]))
            {
                vst[nr][nc][wall + 1] = vst[r][c][wall] + 1;
                q.emplace(nr, nc, wall + 1);
            }
        }
    }
    int res = INF;
    for (const auto &e : vst[n][m])
        if (e >= 0)
            res = min(res, e);
    cout << (res == INF ? -1 : res);
    return 0;
}