// cpp algorithm ps number 81

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

typedef struct edge
{
    int go;
    int cost;
    edge(int go, int cost)
    {
        this->go = go;
        this->cost = cost;
    }
} edge;

int main()
{
    int n, m;
    int start, destination;
    cin >> n >> m;
    vector<vector<edge>> map(n + 1);
    vector<vector<int>> cost(n, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i < m; i++)
    {
        int to, go, cost;
        cin >> to >> go >> cost;
        map[to].push_back(edge(go, cost));
    }
    cin >> start >> destination;
    for (int i = 0; i < n; i++)
        cost[i][start] = 0;
    for (int i = 1; i < n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (cost[i - 1][j] != INT_MAX)
                for (int x = 0; x < map[j].size(); x++)
                    if (cost[i][j] + map[j][x].cost < cost[i - 1][map[j][x].go])
                        cost[i][map[j][x].go] = cost[i][j] + map[j][x].cost;
                    else
                        cost[i][map[j][x].go] = cost[i - 1][map[j][x].go];
        }

    return 0;
}