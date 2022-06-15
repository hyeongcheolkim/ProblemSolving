#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2;
int n, m;
vector<vector<int>> graph;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    while (m--)
    {
        int from, to, time;
        cin >> from >> to >> time;
        if (graph[from][to] <= time)
            cout << "Enjoy other party\n";
        else
            cout << "Stay here\n";
    }
    return 0;
}