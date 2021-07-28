//baekjoon ps 10971

#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int INF = numeric_limits<int>::max();
    int n;
    int res = INF;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    vector<int> route(n + 1);
    for (int i = 1; i < n; i++)
        route[i] = i;
    do
    {
        int cost = 0;
        for (int i = 0; i < route.size() - 1; i++)
        {
            if (graph[route[i]][route[i + 1]] == 0)
            {
                cost = INF;
                break;
            }
            cost += graph[route[i]][route[i + 1]];
        }
        res = min(res, cost);
    } while (next_permutation(route.begin() + 1, route.end() - 1));
    cout << (res == INF ? -1 : res);
    return 0;
}