//baekjoon ps 1956

#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int INF = numeric_limits<int>::max() / 3;
    int v, e;
    int res = INF;
    cin >> v >> e;
    vector<vector<int>> map(v + 1, vector<int>(v + 1, INF));
    for (int i = 1; i <= v; i++)
        map[i][i] = 0;
    while (e--)
    {
        int to, go, cost;
        cin >> to >> go >> cost;
        map[to][go] = cost;
    }
    for (int k = 1; k <= v; k++)
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    for (int i = 1; i <= v; i++)
        for (int j = 1; j <= v; j++)
            if (i != j)
                res = min(res, map[i][j] + map[j][i]);
    if (res == INF)
        cout << -1;
    else
        cout << res;
    return 0;
}