//baekjoon ps 14502

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct pos
{
    int row, col;
    pos(int row, int col)
    {
        this->row = row;
        this->col = col;
    }
};

int n, m;
int res = -1;
vector<vector<int>> map;
vector<pos> virus;
constexpr int NUM_WALL = 3;
constexpr int dr[] = {0, 0, +1, -1};
constexpr int dc[] = {+1, -1, 0, 0};

void dfs(int level, pos index)
{
    if (level == NUM_WALL)
    {
        int cnt = 0;
        auto tempmap = map;
        vector<vector<bool>> check(n + 2, vector<bool>(m + 2, false));
        queue<pos> q;
        for (int i = 0; i < virus.size(); i++)
        {
            q.push(virus[i]);
            check[virus[i].row][virus[i].col] = true;
        }
        while (!q.empty())
        {
            int row = q.front().row;
            int col = q.front().col;
            q.pop();
            for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
            {
                int nextrow = row + dr[i];
                int nextcol = col + dc[i];
                if (tempmap[nextrow][nextcol] == 0 && !check[nextrow][nextcol])
                {
                    q.push(pos(nextrow, nextcol));
                    tempmap[nextrow][nextcol] = 2;
                    check[nextrow][nextcol] = true;
                }
            }
        }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (tempmap[i][j] == 0)
                    cnt++;
        res = max(res, cnt);
        return;
    }
    for (int j = index.col; j <= m; j++)
        if (map[index.row][j] == 0)
        {
            map[index.row][j] = 1;
            dfs(level + 1, pos(index.row, j + 1));
            map[index.row][j] = 0;
        }
    for (int i = index.row + 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 0)
            {
                map[i][j] = 1;
                dfs(level + 1, pos(i, j + 1));
                map[i][j] = 0;
            }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    map = vector<vector<int>>(n + 2, vector<int>(m + 2, -1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
                virus.push_back(pos(i, j));
        }
    dfs(0, pos(1, 1));
    cout << res;
    return 0;
}