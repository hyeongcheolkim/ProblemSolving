// cpp algorithm ps number 79

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct edge
{
    int vertex, cost;
    bool operator<(const edge &a)const
    {
        return cost > a.cost;
    }
    edge(const int a, const int b)
    {
        this->vertex = a;
        cost = b;
    }
} edge;

int main()
{
    int v, e;
    int total = 0;
    int cnt = 0;
    cin >> v >> e;
    vector<vector<edge>> edges(v + 1);
    vector<int> trace(v + 1, 0);
    priority_queue<edge> Q;
    for (int i = 0; i < e; i++)
    {
        static int to, go, cost;
        cin >> to >> go >> cost;
        edges[to].push_back(edge(go, cost));
        edges[go].push_back(edge(to, cost));
    }
    Q.push(edge(1, 0));

    while (cnt!=v)
    {
        static edge temp(0,0);
        while(trace[Q.top().vertex]!=0)
            Q.pop();
        temp = Q.top();
        Q.pop();
        
        trace[temp.vertex] = 1;
        cnt++;
        total += temp.cost;
        for (int i = 0; i < edges[temp.vertex].size(); i++)
            Q.push(edges[temp.vertex][i]);
    }

    cout << total;
    return 0;
}