#include <bits/stdc++.h>
using namespace std;
using pos = tuple<int, int, int>;

constexpr int mxN = 100, mxM = 100, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0}, INF = numeric_limits<int>::max() / 2;
int n, m, t, cnt1 = INF, cnt2 = INF, maze[mxN + 1][mxM + 1];
bool vst[mxN + 1][mxM + 1];
queue<pos> q;
pos gram;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> t;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 2)
                gram = pos{i, j, 0};
        }
    vst[1][1] = true;
    q.emplace(1, 1, 0);
    while (!q.empty())
    {
        auto [r, c, cnt] = q.front();
        q.pop();
        if (pos{r, c, 0} == gram)
            cnt1 = cnt + (n - r) + (m - c);
        if (pos{r, c, 0} == pos{n, m, 0})
            cnt2 = cnt;
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (!(1 <= nr && nr <= n && 1 <= nc && nc <= m) || maze[nr][nc] == 1 || vst[nr][nc])
                continue;
            vst[nr][nc] = true;
            q.emplace(nr, nc, cnt + 1);
        }
    }
    int res = min(cnt1, cnt2);
    if (res > t)
        cout << "Fail";
    else
        cout << res;
    return 0;
}