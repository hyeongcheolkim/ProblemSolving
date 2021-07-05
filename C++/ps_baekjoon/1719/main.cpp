//baekjoon ps 1719

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int INF = numeric_limits<int>::max() / 2;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> route(n + 1, vector<int>(n + 1));
    vector<vector<int>> res(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
        map[i][i] = 0;
    while (m--)
    {
        int to, go, cost;
        cin >> to >> go >> cost;
        map[to][go] = map[go][to] = cost;
        route[to][go] = to;
        route[go][to] = go;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (map[i][j] > map[i][k] + map[k][j])
                {
                    map[i][j] = map[i][k] + map[k][j];
                    route[i][j] = route[k][j];
                }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j)
            {
                function<int(int, int)> recursion = [&](int row, int col) -> int
                {
                    if (route[row][col] == row)
                        return col;
                    else
                        return recursion(row, route[row][col]);
                };
                res[i][j] = recursion(i, j);
            }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (res[i][j] == -1)
                cout << '-'<<' ';
            else
                cout << res[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}