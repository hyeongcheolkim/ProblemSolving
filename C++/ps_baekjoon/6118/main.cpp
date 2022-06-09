#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> vst;
vector<int> res;
queue<int> q, tq;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1); vst.resize(n + 1);
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    vst[1] = true;
    q.push(1);
    while (!q.empty())
    {
        static int dist = 0;
        res.clear();
        res.reserve(q.size());
        while (!q.empty())
        {
            int now = q.front();
            res.push_back(now);
            q.pop();
            for (const auto& next : graph[now])
            {
                if (vst[next])
                    continue;
                vst[next] = true;
                tq.push(next);
            }
        }
        if (tq.empty())
        {
            sort(res.begin(), res.end());
            cout << res.front() << ' ' << dist << ' ' << res.size();
        }
        else
        {
            ++dist;
            q.swap(tq);
        }
    }
    return 0;
}