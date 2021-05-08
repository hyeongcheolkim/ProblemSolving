//baekjoon ps 1753

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define INF 264700000
using namespace std;

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

int main()
{
    ios_base::sync_with_stdio(false);
    int v, e, k;
    cin >> v >> e >> k;
    vector<vector<pos>> map(v + 1);
    vector<int> cost(v + 1, INF);
    priority_queue<pos> pq;
    for (int i = 0; i < e; i++)
    {
        static int to, go, cost;
        cin >> to >> go >> cost;
        map[to].push_back(pos(go, cost));
    }
    pq.push(pos(k, 0));
    cost[k] = 0;
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
    for (int i = 1; i <= v; i++)
        if (cost[i] != INF)
            cout << cost[i] << '\n';
        else
            cout << "INF" << '\n';
    return 0;
}