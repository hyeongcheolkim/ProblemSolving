#include <bits/stdc++.h>
using namespace std;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m;
vector<vector<char>> board;
vector<vector<bool>> vst;
queue<pair<int, int>> q;
map<char, long long> total_power;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    board.resize(n + 2, vector<char>(m + 2));
    vst.resize(n + 2, vector<bool>(m + 2));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (!vst[i][j])
            {
                const char& color = board[i][j];
                int power = 1;
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
                        if (vst[nr][nc] || board[nr][nc] != color || board[nr][nc] == 0)
                            continue;
                        ++power;
                        vst[nr][nc] = true;
                        q.emplace(nr, nc);
                    }
                }
                total_power[color] += power * power;
            }
    cout << total_power['W'] << ' ' << total_power['B'];
    return 0;
}