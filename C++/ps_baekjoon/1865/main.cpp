//baekjoon ps 1865

#include <iostream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, w;
        cin >> n >> m >> w;
        vector<int> cost(n + 1, numeric_limits<int>::max()/3);
        vector<unordered_map<int, int>> edge(n + 1);
        while (m--)
        {
            int s, e, time;
            cin >> s >> e >> time;
            if (edge[s].find(e) != edge[s].end())
            {
                edge[e][s] = min(edge[e][s], time);
                edge[s][e] = min(edge[s][e], time);
            }
            else
            {
                edge[e][s] = time;
                edge[s][e] = time;
            }
        }
        while (w--)
        {
            int s, e, time;
            cin >> s >> e >> time;
            if (edge[s].find(e) != edge[s].end())
                edge[s][e] = min(edge[s][e], -time);
            else
                edge[s][e] = -time;
        }
        for (int x = 0; x < n - 1; x++)
            for (int i = 1; i <= n; i++)
            {
                int to = i;
                    for (const auto &e : edge[i])
                    {
                        int go = e.first;
                        int time = e.second;
                        cost[go] = min(cost[go], cost[to] + time);
                    }
            }
        auto temp(cost);
        for (int i = 1; i <= n; i++)
        {
            int to = i;
            if (temp[to] != numeric_limits<int>::max())
                for (const auto &e : edge[i])
                {
                    int go = e.first;
                    int time = e.second;
                    temp[go] = min(temp[go], temp[to] + time);
                }
        }
        if (temp == cost)
            cout << "NO" << '\n';
        else
            cout << "YES" << '\n';
    }
    return 0;
}