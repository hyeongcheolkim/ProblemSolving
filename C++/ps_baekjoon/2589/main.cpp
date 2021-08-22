#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxN = 5e1, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
constexpr char OUT_OF_BOUND = 0;
int n, m, res = 0, cache[mxN + 2][mxN + 2];
char terrain[mxN + 2][mxN + 2];
queue<pos> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    queue<pos> land;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> terrain[i][j];
            if (terrain[i][j] == 'L')
                land.emplace(i, j);
        }
    while (!land.empty())
    {
        auto [lr, lc] = land.front();
        land.pop();
        memset(cache, 0, sizeof(cache));
        q.emplace(lr, lc);
        while (!q.empty())
        {
            auto [r, c] = q.front();
            q.pop();
            res = max(res, cache[r][c]);
            for (int direction = 0; direction < 4; ++direction)
            {
                int nr = r + dr[direction];
                int nc = c + dc[direction];
                if (terrain[nr][nc] == OUT_OF_BOUND || terrain[nr][nc] == 'W' || (nr == lr && nc == lc))
                    continue;
                if (!cache[nr][nc] || cache[r][c] + 1 < cache[nr][nc])
                {
                    cache[nr][nc] = cache[r][c] + 1;
                    q.emplace(nr, nc);
                }
            }
        }
    }
    cout << res;
    return 0;
}