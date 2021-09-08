#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 5e2;
int n, m, res;
bool graph[mxN + 1][mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from][to] = true;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                graph[i][j] |= graph[i][k] && graph[k][j];
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
            if (graph[i][j] || graph[j][i])
                ++cnt;
        if (cnt == n - 1)
            ++res;
    }
    cout << res;
    return 0;
}