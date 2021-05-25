//baekjoon ps 1916

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> map(n + 1);
    vector<int> dist(n + 1, numeric_limits<int>::max());
    for (int i = 0; i < m; i++)
    {
        int to, go, cost;
        cin >> to >> go >> cost;
        map[to].push_back({cost, go});
    }
    int from, where;
    cin >> from >> where;
    pq.push({0, from});
    dist[from] = 0;
    while (!pq.empty())
    {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (cost > dist[now])
            continue;
        for (int i = 0; i < map[now].size(); i++)
        {
            int nextDis = cost + map[now][i].first;
            int next = map[now][i].second;
            if (dist[next] > nextDis)
            {
                dist[next] = nextDis;
                pq.push({nextDis, next});
            }
        }
    }
    cout << dist[where];
    return 0;
}