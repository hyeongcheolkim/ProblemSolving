#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, dr[]{0, 0, +1, -1, +1, +1, -1, -1}, dc[]{+1, -1, 0, 0, +1, -1, +1, -1};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int w, h;
    vector<vector<int>> terrain;
    vector<vector<bool>> vst;
    while (cin >> w >> h, !(w == 0 && h == 0))
    {
        int cnt = 0;
        terrain.assign(h + 2, vector<int>(w + 2, OUT_OF_BOUND));
        vst.assign(h + 2, vector<bool>(w + 2));
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                cin >> terrain[i][j];
        for (int i = 1; i <= h; ++i)
            for (int j = 1; j <= w; ++j)
                if (terrain[i][j] == 1 && !vst[i][j])
                {
                    ++cnt;
                    queue<pair<int, int>> q;
                    q.emplace(i, j);
                    vst[i][j] = true;
                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();
                        for (int direction = 0; direction < 8; ++direction)
                        {
                            int nr = r + dr[direction];
                            int nc = c + dc[direction];
                            if (vst[nr][nc] || terrain[nr][nc] == 0 || terrain[nr][nc] == OUT_OF_BOUND)
                                continue;
                            vst[nr][nc] = true;
                            q.emplace(nr, nc);
                        }
                    }
                }
        cout << cnt << '\n';
    }
    return 0;
}