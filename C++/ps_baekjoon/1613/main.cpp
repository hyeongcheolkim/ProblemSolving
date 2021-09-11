#include <bits/stdc++.h>
using namespace std;

constexpr int mxN = 4e2;
int n, k;
bool graph[mxN + 1][mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    while (k--)
    {
        int from, to;
        cin >> from >> to;
        graph[from][to] = true;
    }
    for (int h = 1; h <= n; ++h)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                graph[i][j] |= graph[i][h] & graph[h][j];
    int s;
    cin >> s;
    while (s--)
    {
        int from, to;
        cin >> from >> to;
        if (graph[from][to])
            cout << -1 << '\n';
        else if (graph[to][from])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
    return 0;
}