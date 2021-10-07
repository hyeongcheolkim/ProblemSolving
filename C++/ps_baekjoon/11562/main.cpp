#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 250, INF = numeric_limits<int>::max() / 2;
int n, m, k, graph[mxN + 1][mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            graph[i][j] = (i == j ? 0 : INF);
    while (m--)
    {
        int u, v, b;
        cin >> u >> v >> b;
        graph[u][v] = 0;
        graph[v][u] = (b ? 0 : 1);
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    cin >> k;
    while (k--)
    {
        int s, e;
        cin >> s >> e;
        cout << graph[s][e] << '\n';
    }
    return 0;
}