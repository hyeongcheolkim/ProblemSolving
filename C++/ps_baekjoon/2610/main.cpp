//baekjoon ps 2610

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max() / 2;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> res;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));
    for (int i = 1; i <= n; ++i)
        graph[i][i] = 0;
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from][to] = graph[to][from] = 1;
    }
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    vector<bool> visit(n + 1);
    for (int num = 1; num <= n; ++num)
        if (!visit[num])
        {
            int mini = numeric_limits<int>::max();
            int representative = num;
            for (int iter = 1; iter <= n; ++iter)
                if (graph[num][iter] != INF)
                {
                    visit[iter] = true;
                    int maxi = 0;
                    for (const auto &e : graph[iter])
                        if (e != INF)
                            maxi = max(maxi, e);
                    if (mini > maxi)
                    {
                        mini = maxi;
                        representative = iter;
                    }
                }
            res.push_back(representative);
        }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (const auto &e : res)
        cout << e << '\n';
    return 0;
}