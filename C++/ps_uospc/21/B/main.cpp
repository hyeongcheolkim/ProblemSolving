#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 1e2, mxM = 1e2, dr[]{0, 0, -1, +1}, dc[]{+1, -1, 0, 0};
int n, m, cnt = 0;
char board[mxN + 1][mxM + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> board[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (board[i][j] == 'C')
            {
                bool flag = true;
                for (int direction = 0; direction < 4; ++direction)
                {
                    int nr = i + dr[direction];
                    int nc = j + dc[direction];
                    if (board[nr][nc] == 'P')
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    ++cnt;
            }
    cout << cnt;
    return 0;
}