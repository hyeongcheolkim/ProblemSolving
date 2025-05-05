#include <bits/stdc++.h>
using namespace std;

int n, m;
const long long INF = numeric_limits<long long>::max() / 100;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));
    for (int i = 0; i <= n; ++i)
        dist[i][i] = 0;
    for (int i = 0; i < m; ++i)
    {
        int from, to;
        long long cost;
        cin >> from >> to >> cost;
        dist[from][to] = min(dist[from][to], cost);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (dist[i][j] == INF)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}