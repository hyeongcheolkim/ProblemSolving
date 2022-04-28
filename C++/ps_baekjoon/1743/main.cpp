#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, k, maxi;
vector<vector<bool>> board, vst;
queue<pair<int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    board.resize(n + 1, vector<bool>(m + 1));
    vst.resize(n + 1, vector<bool>(m + 1));
    while (k--)
    {
        int r, c;
        cin >> r >> c;
        board[r][c] = true;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (board[i][j] && !vst[i][j])
            {
                vst[i][j] = true;
                q.emplace(i, j);
                int area = 1;
                while (!q.empty())
                {
                    auto [r, c] = q.front();
                    q.pop();
                    for (int direction = 0; direction < 4; ++direction)
                    {
                        int nr = r + dr[direction];
                        int nc = c + dc[direction];
                        if (!(1 <= nr && nr <= n && 1 <= nc && nc <= m))
                            continue;
                        if (vst[nr][nc] || !board[nr][nc])
                            continue;
                        vst[nr][nc] = true;
                        ++area;
                        q.emplace(nr, nc);
                    }
                }
                maxi = max(maxi, area);
            }
    cout << maxi;
    return 0;
}