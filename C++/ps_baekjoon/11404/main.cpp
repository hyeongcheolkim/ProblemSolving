//baekjoon ps 11404

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    constexpr long long INF = 21740000000;
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> map(n + 1, vector<long long>(n + 1, INF));
    for (int i = 1; i <= n; i++)
        map[i][i] = 0;
    while (m--)
    {
        static int to, go;
        static long long cost;
        cin >> to >> go >> cost;
        map[to][go] = min(map[to][go], cost);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << (map[i][j] == INF ? 0 : map[i][j]) << " ";
        cout << '\n';
    }
    return 0;
}