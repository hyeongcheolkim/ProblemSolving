#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxRC = 1e3, ESCAPE = 0, dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int row, col, cnt;
char maze[mxRC + 1][mxRC + 1];
bool vst[mxRC + 1][mxRC + 1];
queue<pos> qf, qs, temp;

void init()
{
    memset(vst, false, sizeof(vst));
    memset(maze, ESCAPE, sizeof(maze));
    for (const auto &e : {&qf, &qs, &temp})
        while (!e->empty())
            e->pop();
    cin >> col >> row;
    for (int i = 1; i <= row; ++i)
        for (int j = 1; j <= col; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '*')
                qf.emplace(i, j);
            if (maze[i][j] == '@')
            {
                maze[i][j] = '.';
                qs.emplace(i, j);
                vst[i][j] = true;
            }
        }
}

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
                maze[nr][nc] = '*';
                temp.emplace(nr, nc);
            }
        }
    }
    qf.swap(temp);
}

bool runaway()
{
    while (!qs.empty())
    {
        auto [r, c] = qs.front();
        qs.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (maze[nr][nc] == '*' || maze[nr][nc] == '#' || vst[nr][nc])
                continue;
            if (maze[nr][nc] == ESCAPE)
            {
                cout << cnt << '\n';
                return true;
            }
            vst[nr][nc] = true;
            temp.emplace(nr, nc);
        }
    }
    qs.swap(temp);
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    bool flag = false;
    while (t--)
    {
        init();
        for (cnt = 1; !qs.empty(); ++cnt)
        {
            fire_spread();
            if (flag = runaway())
                break;
        }
        if (!flag)
            cout << "IMPOSSIBLE" << '\n';
    }
    return 0;
}