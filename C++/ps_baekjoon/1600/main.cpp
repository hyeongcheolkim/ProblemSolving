#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e2 * 2, mxK = 30;
constexpr int m_dr[]{0, 0, +1, -1}, m_dc[]{+1, -1, 0, 0};
constexpr int h_dr[]{+2, +2, +1, +1, -1, -1, -2, -2}, h_dc[]{+1, -1, +2, -2, +2, -2, +1, -1};
int k, w, h, terrain[mxN + 1][mxN + 1], vst[mxK + 1][mxN + 1][mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> w >> h;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j)
            cin >> terrain[i][j];
    queue<tuple<int, int, int, int>> q;
    q.emplace(0, 0, 1, 1);
    for (int i = 0; i <= k; ++i)
        vst[0][1][1] = true;
    while (!q.empty())
    {
        auto [ability, cnt, r, c] = q.front();
        if (r == h && c == w)
        {
            cout << static_cast<int>(cnt);
            exit(0);
        }
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + m_dr[direction];
            int nc = c + m_dc[direction];
            if (!(1 <= nr && nr <= h && 1 <= nc && nc <= w) || terrain[nr][nc] == 1 || vst[ability][nr][nc])
                continue;
            for (int i = ability; i <= k; ++i)
                vst[i][nr][nc] = true;
            q.emplace(ability, cnt + 1, nr, nc);
        }
        if (ability + 1 <= k)
            for (int direction = 0; direction < 8; ++direction)
            {
                int nr = r + h_dr[direction];
                int nc = c + h_dc[direction];
                if (!(1 <= nr && nr <= h && 1 <= nc && nc <= w) || terrain[nr][nc] == 1 || vst[ability + 1][nr][nc])
                    continue;
                for (int i = ability + 1; i <= k; ++i)
                    vst[i][nr][nc] = true;
                q.emplace(ability + 1, cnt + 1, nr, nc);
            }
    }
    cout << -1;
    return 0;
}