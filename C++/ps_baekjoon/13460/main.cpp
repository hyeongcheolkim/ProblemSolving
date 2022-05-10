#include <bits/stdc++.h>
using namespace std;
using pos = pair<int, int>;

constexpr int mxNM = 10;
int n, m;
vector<vector<char>> maze;
queue<pair<pos, pos>> q, tmp;
pos red, blue, hole;
bool vst[mxNM + 1][mxNM + 1][mxNM + 1][mxNM + 1];

pair<pos, pos> transfer(pos, pos, int, int, bool);
pair<pos, pos> right(pos, pos);
pair<pos, pos> left(pos, pos);
pair<pos, pos> down(pos, pos);
pair<pos, pos> up(pos, pos);

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    maze.resize(n + 1, vector<char>(m + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
        {
            cin >> maze[i][j];
            if (maze[i][j] == 'R')
            {
                red = {i, j};
                maze[i][j] = '.';
            }
            if (maze[i][j] == 'B')
            {
                blue = {i, j};
                maze[i][j] = '.';
            }
            if (maze[i][j] == 'O')
            {
                hole = {i, j};
                maze[i][j] = '.';
            }
        }
    vst[red.first][red.second][blue.first][blue.second] = true;
    q.emplace(red, blue);
    for (int cnt = 0; cnt < 10; ++cnt)
    {
        while (!q.empty())
        {
            auto [r, b] = q.front();
            q.pop();
            if (r == pos{0, 0} || b == pos{0, 0})
                continue;
            for (pair<pos, pos>(*e)(pos, pos) : {&left, & right, & down, & up})
            {
                auto [nr, nb] = (*e)(r, b);
                if (nr == pos{0, 0} && nb != pos{0, 0})
                {
                    cout << cnt + 1;
                    exit(0);
                }
                if (vst[nr.first][nr.second][nb.first][nb.second])
                    continue;
                vst[nr.first][nr.second][nb.first][nb.second] = true;
                tmp.emplace(nr, nb);
            }
        }
        q.swap(tmp);
    }
    cout << -1;
    return 0;
}

pair<pos, pos> transfer(pos p1, pos p2, int dr, int dc, bool reverse = false)
{
    if (reverse)
        swap(p1, p2);
    while (maze[p1.first + dr][p1.second + dc] == '.')
    {
        p1.first += dr;
        p1.second += dc;
        if (p1 == hole)
        {
            p1 = {0, 0};
            break;
        }
    }
    while (maze[p2.first + dr][p2.second + dc] == '.' && (pos{p2.first + dr, p2.second + dc} != p1))
    {
        p2.first += dr;
        p2.second += dc;
        if (p2 == hole)
        {
            p2 = {0, 0};
            break;
        }
    }
    if (reverse)
        swap(p1, p2);
    return {p1, p2};
}

pair<pos, pos> right(pos r, pos b)
{
    if (r.second < b.second)
        return transfer(r, b, 0, +1, true);
    else
        return transfer(r, b, 0, +1);
}

pair<pos, pos> left(pos r, pos b)
{
    if (r.second < b.second)
        return transfer(r, b, 0, -1);
    else
        return transfer(r, b, 0, -1, true);
}

pair<pos, pos> down(pos r, pos b)
{
    if (r.first < b.first)
        return transfer(r, b, +1, 0, true);
    else
        return transfer(r, b, +1, 0);
}

pair<pos, pos> up(pos r, pos b)
{
    if (r.first < b.first)
        return transfer(r, b, -1, 0);
    else
        return transfer(r, b, -1, 0, true);
}