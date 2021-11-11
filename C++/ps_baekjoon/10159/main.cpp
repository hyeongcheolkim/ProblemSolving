#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 100;
bool graph1[mxN + 1][mxN + 1], graph2[mxN + 1][mxN + 1];
int n, m;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph1[from][to] = true;
        graph2[to][from] = true;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
            {
                graph1[i][j] |= graph1[i][k] & graph1[k][j];
                graph2[i][j] |= graph2[i][k] & graph2[k][j];
            }
    for (int i = 1; i <= n; ++i)
    {
        int cnt = 0;
        for (int j = 1; j <= n; ++j)
        {
            if (i == j)
                continue;
            if (!(graph1[i][j] | graph2[i][j]))
                ++cnt;
        }
        cout << cnt << '\n';
    }
    return 0;
}