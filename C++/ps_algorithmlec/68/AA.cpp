// cpp algorithm ps number 68

#include <iostream>
#include <vector>
#include <utility>
#include <limits>

using namespace std;

int cnt = 0;
int minimum = INT_MAX;

void dfs(int n, const int &vertex, const int &edge, const vector<vector<pair<int, int>>> &map)
{
    static auto trace = new bool[vertex + 1]{false};
    static int sum=0;
    trace[n] = true;

    if(n==vertex)
    {
        if(minimum>sum)
            minimum = sum;
        return;
    }
    for (int i = 0; i < map[n].size(); i++)
        if (!trace[map[n][i].first])
        {
            sum += map[n][i].second;
            dfs(map[n][i].first, vertex, edge, map);
            trace[map[n][i].first] = false;
            sum -= map[n][i].second;
        }
}

int main()
{
    int vertex, edge;
    cin >> vertex >> edge;
    vector<vector<pair<int, int>>> map(vertex + 1);

    for (int i = 0; i < edge; i++)
    {
        static int to, go, cost;
        cin >> to >> go >> cost;
        map[to].push_back(make_pair(go, cost));
    }
    dfs(1, vertex, edge, map);
    cout << minimum;
    return 0;
}