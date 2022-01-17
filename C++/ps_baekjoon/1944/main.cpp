#include <bits/stdc++.h>
using namespace std;
using node = tuple<int, int, int>;

constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
int n, m, res;
vector<vector<char>> maze;
vector<vector<bool>> vst;
map<int, map<int, int>> loc;
vector<pair<int, int>> keys;
priority_queue<node, vector<node>, greater<node>> pq;
vector<int> uf;

int find(int);
bool uni(int, int);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    maze.assign(n + 1, vector<char>(n + 1));
    keys.reserve(m + 1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            static int idx = 0;
            cin >> maze[i][j];
            if (maze[i][j] == 'K')
            {
                keys.emplace_back(i, j);
                loc[i][j] = idx++;
            }
            if (maze[i][j] == 'S')
            {
                keys.emplace_back(i, j);
                maze[i][j] = 'K';
                loc[i][j] = idx++;
            }
        }
    for (int idx = 0; idx <= m; ++idx)
    {
        const auto& [now_row, now_col] = keys[idx];
        queue<tuple<int, int, int>> q;
        vst.assign(n + 1, vector<bool>(n + 1));
        vst[now_row][now_col] = true;
        q.emplace(now_row, now_col, 0);
        while (!q.empty())
        {
            auto [r, c, cnt] = q.front();
            q.pop();
            for (int direction = 0; direction < 4; ++direction)
            {
                int nr = r + dr[direction];
                int nc = c + dc[direction];
                if (maze[nr][nc] == '1' || vst[nr][nc])
                    continue;
                if (maze[nr][nc] == 'K')
                    pq.emplace(cnt + 1, idx, loc[nr][nc]);
                vst[nr][nc] = true;
                q.emplace(nr, nc, cnt + 1);
            }
        }
    }
    uf.resize(m + 1);
    iota(uf.begin(), uf.end(), 0);
    while (!pq.empty() && m)
    {
        auto [cost, r, c] = pq.top();
        pq.pop();
        if (uni(r, c))
        {
            res += cost;
            --m;
        }
    }
    cout << (m ? -1 : res);
    return 0;
}

int find(int num)
{
    if (num == uf[num])
        return num;
    return uf[num] = find(uf[num]);
}

bool uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        uf[a] = b;
        return true;
    }
    return false;
}