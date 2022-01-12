#include <bits/stdc++.h>
using namespace std;

constexpr char OUT_OF_BOUND = 0;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0}, INF = numeric_limits<int>::max() / 2;
int n, m, res = INF;
vector<vector<char>> maze;
vector<vector<vector<bool>>> vst;
queue<tuple<int, int, int, int>> q;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    maze.assign(n + 2, vector<char>(m + 2, OUT_OF_BOUND));
    vst.assign(n + 2, vector<vector<bool>>(m + 2, vector<bool>(1 << 6)));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == '0')
            {
                maze[i][j] = '.';
                q.emplace(i, j, 0, 0);
                vst[i][j][0] = true;
            }
        }
    while (!q.empty())
    {
        auto [r, c, cnt, key] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            bitset<6> temp_key{key};
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            const char& next = maze[nr][nc];
            if (next == OUT_OF_BOUND || vst[nr][nc][temp_key.to_ulong()] || next == '#')
                continue;
            if ('A' <= next && next <= 'F' && !temp_key.test(next - 'A'))
                continue;
            if (next == '1')
            {
                res = min(res, cnt + 1);
                continue;
            }
            if ('a' <= next && next <= 'f')
                temp_key.set(next - 'a');
            vst[nr][nc][temp_key.to_ulong()] = true;
            q.emplace(nr, nc, cnt + 1, temp_key.to_ulong());
        }
    }
    cout << (res == INF ? -1 : res);
    return 0;
}