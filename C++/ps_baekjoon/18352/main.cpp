//baekjoon ps 18352

#include <iostream>
#include <limits>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    constexpr int INF = numeric_limits<int>::max();
    int n, m, k, x;
    cin >> n >> m >> k >> x;
    string res;
    vector<int> dist(n + 1, INF);
    vector<vector<pair<int, int>>> map(n + 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    while (m--)
    {
        int to, go;
        cin >> to >> go;
        map[to].push_back({1, go});
    }
    dist[x] = 0;
    pq.push({0, x});
    while (!pq.empty())
    {
        int nowdist = pq.top().first;
        int nowvertex = pq.top().second;
        pq.pop();
        if (nowdist > dist[nowvertex])
            continue;
        for (int i = 0; i < map[nowvertex].size(); i++)
        {
            int nextdist = nowdist + map[nowvertex][i].first;
            int nextvertex = map[nowvertex][i].second;
            if (dist[nextvertex] > nextdist)
            {
                dist[nextvertex] = nextdist;
                pq.push({nextdist, nextvertex});
            }
        }
    }
    for (int i = 1; i < dist.size(); i++)
        if (dist[i] == k)
            res.append(to_string(i)+'\n');
    if (res.empty())
        cout << -1;
    else
        cout << res;
    return 0;
}