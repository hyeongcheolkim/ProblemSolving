#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, k, s, x, y;
vector<vector<int>> board;
vector<queue<pair<int, int>>> q_vec;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    board.resize(n + 2, vector<int>(n + 2, OUT_OF_BOUND));
    q_vec.resize(k + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 0)
                continue;
            q_vec[board[i][j]].emplace(i, j);
        }
    cin >> s >> x >> y;
    while (s--)
    {
        for (int i = 1; i <= k; ++i)
        {
            auto& q = q_vec[i];
            queue<pair<int, int>> tmp;
            while (!q.empty())
            {
                auto [r, c] = q.front();
                q.pop();
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = r + dr[direction];
                    int nc = c + dc[direction];
                    if (board[nr][nc] == OUT_OF_BOUND || board[nr][nc] != 0)
                        continue;
                    board[nr][nc] = i;
                    tmp.emplace(nr, nc);
                }
            }
            q.swap(tmp);
        }
    }
    cout << board[x][y];
    return 0;
}