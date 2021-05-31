//baekjoon ps 11779

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <limits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> map(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, numeric_limits<int>::max());
    vector<int> trace(n + 1);
    vector<int> res;
    res.reserve(n);
    while (m--)
    {
        int to, go, cost;
        cin >> to >> go >> cost;
        map[to].push_back({cost, go});
    }
    int from, where;
    cin >> from >> where;
    dist[from] = 0;
    pq.push({0, from});
    while (!pq.empty())
    {
        int nowcost = pq.top().first;
        int now = pq.top().second;
        pq.pop();
        if (nowcost > dist[now])
            continue;
        for (int i = 0; i < map[now].size(); i++)
        {
            int nextcost = nowcost + map[now][i].first;
            int next = map[now][i].second;
            if (nextcost < dist[next])
            {
                trace[next] = now;
                dist[next] = nextcost;
                pq.push({nextcost, next});
            }
        }
    }
    int temp = where;
    while (temp)
    {
        res.push_back(temp);
        temp = trace[temp];
    }
    cout << dist[where] << '\n';
    cout << res.size() << '\n';
    for (int i = res.size() - 1; i >= 0; i--)
        cout << res[i] << ' ';
    return 0;
}