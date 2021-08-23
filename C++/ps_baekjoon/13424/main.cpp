#include <bits/stdc++.h>
using namespace std;

constexpr int INF = numeric_limits<int>::max() / 2, mxN = 1e2;
int fw[mxN + 1][mxN + 1], room[mxN + 1];

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
    {
        fill(&fw[0][0], &fw[mxN][mxN], INF);
        for (int i = 1; i < mxN; ++i)
            fw[i][i] = 0;
        int n, m, k;
        cin >> n >> m;
        while (m--)
        {
            int from, to, cost;
            cin >> from >> to >> cost;
            fw[from][to] = fw[to][from] = cost;
        }
        cin >> k;
        for (int i = 0; i < k; ++i)
            cin >> room[i];
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
        vector<pair<int, int>> dist;
        dist.reserve(n);
        for (int idx = 1; idx <= n; ++idx)
        {
            int temp = 0;
            for (int i = 0; i < k; ++i)
                temp += fw[room[i]][idx];
            dist.emplace_back(temp, idx);
        }
        sort(dist.begin(), dist.end());
        cout << dist[0].second << '\n';
    }
    return 0;
}