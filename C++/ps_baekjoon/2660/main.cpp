#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 5e1, INF = numeric_limits<int>::max() / 2;
int graph[mxN + 1][mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    fill(&graph[0][0], &graph[mxN][mxN], INF);
    for (int i = 1; i <= mxN; ++i)
        graph[i][i] = 0;
    vector<int> res;
    int n, from, to, mini = INF;
    cin >> n;
    while (cin >> from >> to, !(from == -1 && to == -1))
        graph[from][to] = graph[to][from] = 1;
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    for (int i = 1; i <= n; ++i)
    {
        int maxi = 0;
        for (int j = 1; j <= n; ++j)
            if (graph[i][j] != INF)
                maxi = max(maxi, graph[i][j]);
        if (maxi < mini)
        {
            mini = maxi;
            res.resize(0);
            res.push_back(i);
        }
        else if (maxi == mini)
            res.push_back(i);
    }
    cout << mini << ' ' << res.size() << '\n';
    for (int i = 0; i < res.size(); ++i)
        cout << res[i] << ' ';
    return 0;
}