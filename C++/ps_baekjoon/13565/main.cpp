#include <bits/stdc++.h>
using namespace std;

constexpr int OUT_OF_BOUND = -1, INNER_SIDE = -2, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m;
vector<vector<int>> board;
vector<vector<bool>> vst;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    board.resize(n + 2, vector<int>(m + 2, OUT_OF_BOUND));
    vst.resize(n + 2, vector<bool>(m + 2));
    for (int j = 1; j <= m; ++j)
        board[n + 1][j] = INNER_SIDE;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            char buff;
            cin >> buff;
            board[i][j] = buff - '0';
        }
    for (int j = 1; j <= m; ++j)
        if (board[1][j] == 0 && !vst[1][j])
        {
            queue<pair<int, int>> q;
            q.emplace(1, j);
            vst[1][j] = true;
            while (!q.empty())
            {
                auto [r, c] = q.front();
                q.pop();
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = r + dr[direction];
                    int nc = c + dc[direction];
                    if (vst[nr][nc])
                        continue;
                    if (board[nr][nc] == OUT_OF_BOUND || board[nr][nc] == 1)
                        continue;
                    if (board[nr][nc] == INNER_SIDE)
                    {
                        cout << "YES";
                        exit(0);
                    }
                    vst[nr][nc] = true;
                    q.emplace(nr, nc);
                }
            }
        }
    cout << "NO";
    return 0;
}