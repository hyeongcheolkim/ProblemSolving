#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, INF = numeric_limits<int>::max() / 2;
constexpr int dr[]{+1, -1, 0, 0, +1, +1, -1, -1}, dc[]{0, 0, +1, -1, +1, -1, +1, -1};
int n, m, maxi = 0;
vector<vector<int>> board, dist;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(m + 2, OUT_OF_BOUND));
    dist.resize(n + 2, vector<int>(m + 2, INF));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (board[i][j] == 1)
            {
                vector<vector<bool>> vst(n + 2, vector<bool>(m + 2));
                queue<pair<int, int>> q, tmp;
                q.emplace(i, j);
                vst[i][j] = true;
                int distance = 0;
                while (!q.empty())
                {
                    ++distance;
                    while (!q.empty())
                    {
                        auto [r, c] = q.front();
                        q.pop();
                        for (int direction = 0; direction < 8; ++direction)
                        {
                            int nr = r + dr[direction];
                            int nc = c + dc[direction];
                            if (board[nr][nc] == OUT_OF_BOUND || vst[nr][nc] || board[nr][nc] == 1)
                                continue;
                            if (dist[nr][nc] <= distance)
                                continue;
                            dist[nr][nc] = distance;
                            tmp.emplace(nr, nc);
                        }
                    }
                    q.swap(tmp);
                }
            }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (dist[i][j] != INF)
                maxi = max(maxi, dist[i][j]);
    cout << maxi;
    return 0;
}