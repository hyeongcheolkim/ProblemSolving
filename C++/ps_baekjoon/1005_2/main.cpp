#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> time(n + 1);
    vector<int> acc(n + 1);
    vector<int> degree(n + 1);
    vector<vector<int>> graph(n + 1);
    queue<int> q;

    for (int i = 1; i <= n; ++i)
        cin >> time[i];

    while (k--)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        ++degree[to];
    }

    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
        {
            q.push(i);
            acc[i] = time[i];
        }

    while (!q.empty())
    {
        int from = q.front();
        q.pop();
        for (const int &to : graph[from])
        {
            if (--degree[to] == 0)
                q.push(to);
            acc[to] = max(acc[to], acc[from] + time[to]);
        }
    }

    int w;
    cin >> w;
    cout << acc[w] << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}