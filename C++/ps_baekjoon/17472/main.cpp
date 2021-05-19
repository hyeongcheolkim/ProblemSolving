//baekjoon ps 17472

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

int *uf;
int find(int n)
{
    if (n == uf[n])
        return n;
    else
        return uf[n] = find(uf[n]);
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
    else
        return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int dx[] = {0, 0, -1, +1};
    constexpr int dy[] = {-1, +1, 0, 0};
    int n, m;
    int cnt = 0;
    int res = 0;
    cin >> n >> m;
    vector<vector<int>> map(n + 2, vector<int>(m + 2, 0));
    vector<vector<bool>> check(n + 2, vector<bool>(m + 2, true));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> map[i][j];
            check[i][j] = false;
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (!check[i][j] && map[i][j] != 0)
            {
                cnt++;
                check[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                while (!q.empty())
                {
                    auto front = q.front();
                    auto x = front.first;
                    auto y = front.second;
                    map[x][y] = cnt;
                    q.pop();
                    for (int i = 0; i < sizeof(dx) / sizeof(int); i++)
                    {
                        pair<int, int> temp = {x + dx[i], y + dy[i]};
                        if (map[temp.first][temp.second] != 0 && !check[temp.first][temp.second])
                            q.push(temp);
                        check[temp.first][temp.second] = true;
                    }
                }
            }
        }
    vector<vector<int>> dis(cnt + 1, vector<int>(cnt + 1, INT_MAX));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] != 0)
            {
                int island1 = map[i][j];
                for (int k = 1; k <= n; k++)
                {
                    int island2 = map[k][j];
                    if (island2 != 0 && island2 != island1)
                    {
                        bool flag = false;
                        for (int x = min(i, k) + 1; x < max(i,k); x++)
                            if (map[x][j] != 0)
                                flag = true;
                        if (flag)
                            continue;
                        if (abs(k - i) - 1 >= 2)
                            dis[island1][island2] = min(dis[island1][island2], abs(k - i) - 1);
                    }
                }
                for (int k = 1; k <= m; k++)
                {
                    int island2 = map[i][k];
                    if (island2 != 0 && island2 != island1)
                    {
                        bool flag = false;
                        for (int x = min(j, k) + 1; x < max(j, k); x++)
                            if (map[i][x] != 0)
                                flag = true;
                        if (flag)
                            continue;
                        if (abs(k - j) - 1 >= 2)
                            dis[island1][island2] = min(dis[island1][island2], abs(k - j) - 1);
                    }
                }
            }
    vector<tuple<int, int, int>> edge;
    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt; j++)
            if (dis[i][j] != INT_MAX)
                edge.push_back({dis[i][j], i, j});
    sort(edge.begin(), edge.end());
    uf = new int[cnt + 1];
    for (int i = 1; i <= cnt; i++)
        uf[i] = i;
    for (int i = 0; i < edge.size(); i++)
        if (uni(get<1>(edge[i]), get<2>(edge[i])))
            res += get<0>(edge[i]);
    for (int i = 1; i < cnt; i++)
        res *= !uni(i, i + 1);
    cout << (res != 0 ? res : -1);
    delete[] uf;
    return 0;
}