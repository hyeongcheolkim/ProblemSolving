#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxRC = 1e3, ESCAPE = 0, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int row, col, cnt;
char maze[mxRC + 1][mxRC + 1];
bool vst[mxRC + 1][mxRC + 1];
queue<pos> qf, qj, temp;

void fire_spread()
{
    while (!qf.empty())
    {
        auto [r, c] = qf.front();
        qf.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (maze[nr][nc] == '.')
            {
                maze[nr][nc] = 'F';
                temp.emplace(nr, nc);
            }
        }
    }
    qf.swap(temp);
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> row >> col;
    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= col; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'F')
                qf.emplace(i, j);
            if (maze[i][j] == 'J')
            {
                maze[i][j] = '.';
                qj.emplace(i, j);
                vst[i][j] = true;
            }
        }
    for (cnt = 1; !qj.empty(); ++cnt)
    {
        fire_spread();
        while (!qj.empty())
        {
            auto [r, c] = qj.front();
            qj.pop();
            for (int direction = 0; direction < 4; ++direction)
            {
                int nr = r + dr[direction];
                int nc = c + dc[direction];
                if (maze[nr][nc] == 'F' || maze[nr][nc] == '#' || vst[nr][nc])
                    continue;
                if (maze[nr][nc] == ESCAPE)
                {
                    cout << cnt;
                    exit(0);
                }
                vst[nr][nc] = true;
                temp.emplace(nr, nc);
            }
        }
        qj.swap(temp);
    }
    cout << "IMPOSSIBLE";
    return 0;
}