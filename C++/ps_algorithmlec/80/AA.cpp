// cpp algorithm ps number 80

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

typedef struct edge
{
    int vex, dis;
    edge(const int &vex, const int &dis)
    {
        this->vex = vex;
        this->dis = dis;
    }
    bool operator<(const edge &obj) const
    {
        return this->dis > obj.dis;
    }
} edge;

int main()
{
    int n, m;
    cin >> n >> m;
    priority_queue<edge> Q;
    vector<int> dist(n + 1, INT_MAX);
    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        static int to, go, cost;
        cin >> to >> go >> cost;
        graph[to].push_back(make_pair(go, cost));
    }
    Q.push(edge(1, 0));
    dist[1] = 0;
    while (!Q.empty())
    {
        int now = Q.top().vex;
        int cost = Q.top().dis;
        Q.pop();
        if (cost > dist[now])
            continue;
        for (int i = 0; i < graph[now].size(); i++)
        {
            int next = graph[now][i].first;
            int nextDis = cost + graph[now][i].second;
            if (dist[next] > nextDis)
            {
                dist[next] = nextDis;
                Q.push(edge(next, nextDis));
            }
        }
    }
    for (int i = 2; i <= n; i++)
        if (dist[i] != INT_MAX)
            cout << i << " : " << dist[i] << '\n';
        else
            cout << i << " : impossible" << '\n';
    return 0;
}