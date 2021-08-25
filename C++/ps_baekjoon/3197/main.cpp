#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxN = 1.5e3;
constexpr int dr[]{0, 0, +1, -1}, dc[]{+1, -1, 0, 0};
constexpr char OUT_OF_BOUND = 0;
char terrain[mxN + 2][mxN + 2];
int group[mxN + 2][mxN + 2];
bool vst[mxN + 2][mxN + 2];
int r, c, id = 0;
vector<pos> swan;
vector<int> uf;

int find(int num)
{
    if (uf[num] == num)
        return num;
    else
        return uf[num] = find(uf[num]);
}

void uni(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
        uf[b] = a;
}

bool isUnited(int a, int b)
{
    a = find(a);
    b = find(b);
    return a == b;
}

void grouping(const int &row, const int &col)
{
    ++id;
    queue<pos> q;
    q.emplace(row, col);
    group[row][col] = id;
    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (terrain[nr][nc] == 'X' || terrain[nr][nc] == OUT_OF_BOUND || group[nr][nc] != 0)
                continue;
            q.emplace(nr, nc);
            group[nr][nc] = id;
        }
    }
}

void melt()
{
    queue<pair<pos, int>> water, ice;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (terrain[i][j] == '.' && !vst[i][j])
            {
                water.emplace(pos{i, j}, group[i][j]);
                vst[i][j] = true;
            }
    while (!water.empty())
    {
        auto [now_pos, now_id] = water.front();
        auto [r, c] = now_pos;
        water.pop();
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (terrain[nr][nc] == OUT_OF_BOUND || group[nr][nc] == now_id || vst[nr][nc])
                continue;
            ice.emplace(pos{nr, nc}, now_id);
            group[nr][nc] = now_id;
        }
    }
    while (!ice.empty())
    {
        auto [now_pos, now_id] = ice.front();
        auto [r, c] = now_pos;
        ice.pop();
        uni(now_id, group[r][c]);
        terrain[r][c] = '.';
        for (int direction = 0; direction < 4; ++direction)
        {
            int nr = r + dr[direction];
            int nc = c + dc[direction];
            if (terrain[nr][nc] == OUT_OF_BOUND || group[nr][nc] == now_id || group[nr][nc] == 0)
                continue;
            uni(group[r][c], group[nr][nc]);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
        {
            cin >> terrain[i][j];
            if (terrain[i][j] == 'L')
            {
                swan.emplace_back(i, j);
                terrain[i][j] = '.';
            }
        }
    for (int i = 1; i <= r; ++i)
        for (int j = 1; j <= c; ++j)
            if (terrain[i][j] == '.' && group[i][j] == 0)
                grouping(i, j);
    uf.resize(id + 1);
    for (int i = 1; i <= id; ++i)
        uf[i] = i;
    auto [r0, c0] = swan[0];
    auto [r1, c1] = swan[1];
    int cnt;
    for (cnt = 0; !isUnited(group[r0][c0], group[r1][c1]); ++cnt)
        melt();
    cout << cnt;
    return 0;
}