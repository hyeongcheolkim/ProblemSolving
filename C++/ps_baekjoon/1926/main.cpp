#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, maxi = 0, cnt = 0;
vector<vector<char>> paint;
vector<vector<bool>> vst;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    paint.resize(n + 2, vector<char>(m + 2));
    vst.resize(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> paint[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!vst[i][j] && paint[i][j] == '1')
            {
                ++cnt;
                int area = 1;
                vst[i][j] = true;
                q.emplace(i, j);
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (vst[nr][nc] || paint[nr][nc] == '0' || paint[nr][nc] == 0)
                            continue;
                        vst[nr][nc] = true;
                        q.emplace(nr, nc);
                        ++area;
                    }
                }
                maxi = max(maxi, area);
            }
    cout << cnt << '\n' << maxi;
    return 0;
}