#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int m, n, k, cnt;
vector<vector<bool>> is_square, vst;
vector<int> area;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n >> k;
    is_square.resize(m + 2, vector<bool>(n + 2));
    vst.resize(m + 2, vector<bool>(n + 2));
    while (k--)
    {
        int c1, r1, c2, r2;
        cin >> c1 >> r1 >> c2 >> r2;
        for (int row = r1 + 1; row <= r2; ++row)
            for (int col = c1 + 1; col <= c2; ++col)
                is_square[row][col] = true;
    }
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (!is_square[i][j] && !vst[i][j])
            {
                ++cnt;
                int s = 1;
                vst[i][j] = true;
                queue<pair<int, int>> q;
                q.emplace(i, j);
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (!(1 <= nr && nr <= m && 1 <= nc && nc <= n))
                            continue;
                        if (vst[nr][nc] || is_square[nr][nc])
                            continue;
                        ++s;
                        vst[nr][nc] = true;
                        q.emplace(nr, nc);
                    }
                }
                area.push_back(s);
            }
    cout << cnt << '\n';
    sort(area.begin(), area.end());
    for (const auto& e : area)
        cout << e << ' ';
    return 0;
}