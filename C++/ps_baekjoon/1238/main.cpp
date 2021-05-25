//baekjoon ps 1238

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, x;
    int res = 0;
    cin >> n >> m >> x;
    vector<vector<int>> map(n + 1, vector<int>(n + 1, numeric_limits<int>::max() / 3));
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            map[i][i] = 0;
    while (m--)
    {
        int to, go, time;
        cin >> to >> go >> time;
        map[to][go] = time;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    for (int i = 1; i <= n; i++)
        res = max(res, map[i][x] + map[x][i]);
    cout << res;
    return 0;
}