#include <bits/stdc++.h>
using namespace std;

int n, m;
queue<int> q;
vector<vector<int>> graph;
vector<int> degree;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    graph.resize(n + 1);
    degree.resize(n + 1, 0);
    while (m--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        ++degree[to];
    }
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        cout << f << ' ';

        for (const int &to : graph[f])
            if(--degree[to] == 0)
                q.push(to);
    }
    return 0;
}