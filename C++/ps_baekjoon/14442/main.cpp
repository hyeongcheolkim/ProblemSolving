#include <bits/stdc++.h>
using namespace std;
using pos = tuple<int, int, int>;

constexpr char out_of_bound = 0;
constexpr int mxN = 1e3, mxK = 1e1, not_visit = -1;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0}, INF = numeric_limits<int>::max() / 2;
char terrain[mxN + 2][mxN + 2];
int n, m, k, vst[mxN + 2][mxN + 2][mxK + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    memset(terrain, out_of_bound, sizeof(terrain));
    memset(vst, not_visit, sizeof(vst));
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