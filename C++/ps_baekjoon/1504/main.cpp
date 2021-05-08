//baekjoon ps 1504

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define INF 204700000

using namespace std;

int v, e;

struct pos
{
    int vertex;
    int cost;
    pos() {}
    pos(const int &vertex, const int &cost)
    {
        this->vertex = vertex;
        this->cost = cost;
    }
    bool operator<(const pos &obj) const
    {
        return this->cost > obj.cost;
    }
};

int fnc(const int &to, const int &go, const vector<vector<pos>> &map)
{
    vector<int> cost(v + 1, INF);
    priority_queue<pos> pq;
    pq.push(pos(to, 0));
    cost[to] = 0;
    while (!pq.empty())
    {
        static pos top;
        top = pq.top();
        pq.pop();
        for (int i = 0; i < map[top.vertex].size(); i++)
            if (cost[map[top.vertex][i].vertex] > top.cost + map[top.vertex][i].cost)
            {
                cost[map[top.vertex][i].vertex] = top.cost + map[top.vertex][i].cost;
                pq.push(pos(map[top.vertex][i].vertex, top.cost + map[top.vertex][i].cost));
            }
    }
    return (cost[go] >= INF ? -1 : cost[go]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> v >> e;
    vector<vector<pos>> map(v + 1);
    for (int i = 0; i < e; i++)
    {
        static int to, go, cost;
        cin >> to >> go >> cost;
        map[to].push_back(pos(go, cost));
        map[go].push_back(pos(to, cost));
    }
    int v1, v2, res;
    cin >> v1 >> v2;

    res = min(fnc(1, v1, map) + fnc(v1, v2, map) + fnc(v2, v, map), fnc(1, v2, map) + fnc(v2, v1, map) + fnc(v1, v, map));
    if(fnc(1, v1, map)!=-1 && fnc(v1, v2, map)!=-1 && fnc(v2, v, map)!=-1)
        cout << res;
    else
        cout << -1;
}