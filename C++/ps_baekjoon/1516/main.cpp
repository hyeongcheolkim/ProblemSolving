//baekjoon ps 1516

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> degree(n + 1), time(n + 1), dp(n + 1);
    vector<vector<int>> graph(n + 1);
    queue<int> q;
    for (int to = 1; to <= n; ++to)
    {
        cin >> time[to];
        int from;
        while (cin >> from, from != -1)
        {
            ++degree[to];
            graph[from].push_back(to);
        }
    }
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
        {
            q.push(i);
            dp[i] = time[i];
        }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0, s = graph[now].size(); i < s; ++i)
        {
            int next = graph[now][i];
            dp[next] = max(dp[next], time[next] + dp[now]);
            if (--degree[next] == 0)
                q.push(next);
        }
    }
    for (int i = 1; i <= n; ++i)
        cout << dp[i] << '\n';
    return 0;
}