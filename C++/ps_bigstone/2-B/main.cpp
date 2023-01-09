#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k, res = 0;
        cin >> m >> n >> k;
        vector<vector<bool>> board(m, vector<bool>(n, false));
        auto vst = board;
        while (k--)
        {
            int r, c;
            cin >> r >> c;
            board[r][c] = true;
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] == 0)
                    continue;
                if (vst[i][j])
                    continue;
                queue<pair<int, int>> q;
                vst[i][j] = true;
                ++res;
                q.emplace(i, j);
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (!(0 <= nr && nr < m && 0 <= nc && nc < n))
                            continue;
                        if (board[nr][nc] == 0)
                            continue;
                        if (vst[nr][nc])
                            continue;
                        vst[nr][nc] = true;
                        q.emplace(nr, nc);
                    }
                }
            }
        cout << res << '\n';
    }
    return 0;
}