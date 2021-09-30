#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxNM = 50;
int n, m, cnt, direction, terrain[mxNM][mxNM];
bool vst[mxNM][mxNM];
pos robot;
map<int, array<int, 4>>
    dr{
        {0, {0, +1, 0, -1}},
        {1, {-1, 0, +1, 0}},
        {2, {0, -1, 0, +1}},
        {3, {+1, 0, -1, 0}},
    },
    dc{
        {0, {-1, 0, +1, 0}},
        {1, {0, -1, 0, +1}},
        {2, {+1, 0, -1, 0}},
        {3, {0, +1, 0, -1}},
    };

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> robot.first >> robot.second >> direction;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> terrain[i][j];
    vst[robot.first][robot.second] = true;
    ++cnt;
    while (true)
    {
        auto [r, c] = robot;
        bool flag = false;
        for (int i = 0; i < 4; ++i)
        {
            int nr = r + dr[direction][i];
            int nc = c + dc[direction][i];
            if (!(0 <= nr && nr < n && 0 <= nc && nc < m) || terrain[nr][nc] == 1 || vst[nr][nc])
                continue;
            robot = {nr, nc};
            vst[nr][nc] = true;
            ++cnt;
            int turn = i + 1;
            while (turn--)
                if (--direction == -1)
                    direction = 3;
            flag = true;
            break;
        }
        if (!flag)
        {
            int nr = r + dr[direction][1];
            int nc = c + dc[direction][1];
            if (!(0 <= nr && nr < n && 0 <= nc && nc < m) || terrain[nr][nc] == 1)
                break;
            robot = {nr, nc};
        }
    }
    cout << cnt;
    return 0;
}