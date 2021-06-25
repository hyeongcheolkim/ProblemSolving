//baekjoon ps 14938

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m, r;
    int res = -1;
    cin >> n >> m >> r;
    vector<int> item(n + 1);
    vector<vector<int>> map(n + 1, vector<int>(n + 1, numeric_limits<int>::max() / 2));
    for (int i = 1; i <= n; i++)
        map[i][i] = 0;
    for (int i = 1; i <= n; i++)
        cin >> item[i];
    while (r--)
    {
        int to, go, cost;
        cin >> to >> go >> cost;
        map[to][go] = cost;
        map[go][to] = cost;
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
            if (map[i][j] <= m)
                sum += item[j];
        res = max(res, sum);
    }
    cout << res;
    return 0;
}