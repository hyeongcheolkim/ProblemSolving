//baekjoon ps 2636

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

constexpr int dr[] = {0, 0, +1, -1};
constexpr int dc[] = {+1, -1, 0, 0};
vector<vector<char>> map;
vector<vector<bool>> check;
int res = -1;
int n, m, prv;

enum state
{
    Internal = 0,
    Cheese = 1,
    Air = 2,
    OutOfBound = 3,
};

void air(const pair<char, char> &pos)
{
    queue<pair<char, char>> q;
    q.push(pos);
    while (!q.empty())
    {
        char nowrow = q.front().first;
        char nowcol = q.front().second;
        q.pop();
        for (int i = 0; i < sizeof(dr) / sizeof(int); i++)
        {
            char nextrow = nowrow + dr[i];
            char nextcol = nowcol + dc[i];
            if (!check[nextrow][nextcol] && map[nextrow][nextcol] == Internal && map[nextrow][nextcol] != OutOfBound)
            {
                map[nextrow][nextcol] = Air;
                check[nextrow][nextcol] = true;
                q.push({nextrow, nextcol});
            }
        }
    }
}

bool melt()
{
    int cheese = 0;
    res++;
    vector<pair<int, int>> temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == Cheese)
            {
                int cnt = 0;
                cheese++;
                for (int d = 0; d < sizeof(dr) / sizeof(int); d++)
                    if (map[i + dr[d]][j + dc[d]] == Air)
                        cnt++;
                if (cnt >= 1)
                {
                    map[i][j] = Internal;
                    temp.push_back({i, j});
                }
            }
    for (int i = 0; i < temp.size(); i++)
        if (map[temp[i].first][temp[i].second] == Internal)
        {
            map[temp[i].first][temp[i].second] = Air;
            check[temp[i].first][temp[i].second] = true;
            air({temp[i].first, temp[i].second});
        }
    if (cheese)
    {
        prv = cheese;
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    map = vector<vector<char>>(n + 2, vector<char>(m + 2, OutOfBound));
    check = vector<vector<bool>>(n + 2, vector<bool>(m + 2, false));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            map[i][j] -= '0';
        }
    map[1][1] = Air;
    check[1][1] = true;
    air({1, 1});
    while (melt())
        continue;
    cout << res << '\n';
    cout << prv;
    return 0;
}