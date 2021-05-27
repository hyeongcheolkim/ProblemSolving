//baekjoon ps 1005

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
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, target;
        cin >> n >> k;
        vector<vector<int>> graph(n + 1);
        vector<int> degree(n + 1), time(n + 1), dp(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++)
            cin >> time[i];
        while (k--)
        {
            int to, go;
            cin >> to >> go;
            graph[to].push_back(go);
            degree[go]++;
        }
        cin >> target;
        for (int i = 1; i <= n; i++)
            if (degree[i] == 0)
                q.push(i);
        while (!q.empty())
        {
            int now = q.front();
            int cost = time[now];
            if (now == target)
            {
                dp[target] += time[target];
                break;
            }
            q.pop();
            for (int i = 0; i < graph[now].size(); i++)
            {
                int next = graph[now][i];
                degree[next]--;
                dp[next] = max(dp[next], dp[now] + cost);
                if (degree[next] == 0)
                    q.push(next);
            }
        }
        cout << dp[target] << '\n';
    }
    return 0;
}