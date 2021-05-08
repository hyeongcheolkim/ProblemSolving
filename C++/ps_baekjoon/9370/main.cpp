//baekjoon ps 9370

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
#define INF 204700000

using namespace std;

int v, e, t, s, g, h;

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
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> v >> e >> t >> s >> g >> h;
        vector<vector<pos>> map(v + 1);
        vector<int> res(t);
        for (int i = 0; i < e; i++)
        {
            static int to, go, cost;
            cin >> to >> go >> cost;
            map[to].push_back(pos(go, cost));
            map[go].push_back(pos(to, cost));
        }
        for (int i = 0; i < t;i++)
        {
            static int x;
            cin >> x;
            int res1, res2;
            res1 = fnc(s, x,map);
            res2 = min(fnc(s,g,map)+fnc(g,h,map)+fnc(h,x,map),fnc(s,h,map)+fnc(h,g,map)+fnc(g,x,map));
            if(res1 == res2)
                res[i] = x;
        }
        sort(res.begin(), res.end());
        for(const auto &e:res)
            if(e!=0)
                cout << e << " ";
        cout << '\n';
    }
}