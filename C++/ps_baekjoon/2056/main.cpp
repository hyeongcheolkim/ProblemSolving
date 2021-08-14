//baekjoon ps 2056

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
        int num;
        cin >> time[to] >> num;
        while (num--)
        {
            int from;
            cin >> from;
            graph[from].emplace_back(to);
            ++degree[to];
        }
    }
    for (int i = 1; i <= n; ++i)
        if (degree[i] == 0)
        {
            q.emplace(i);
            dp[i] = time[i];
        }
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0, s = graph[now].size(); i < s; ++i)
        {
            int next = graph[now][i];
            dp[next] = max(dp[next], dp[now] + time[next]);
            if (--degree[next] == 0)
                q.push(next);
        }
    }
    cout << *max_element(dp.begin() + 1, dp.end());
    return 0;
}