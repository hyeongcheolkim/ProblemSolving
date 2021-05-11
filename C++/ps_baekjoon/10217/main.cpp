//baekjoon ps 10217

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    constexpr int INF = 200000000;
    int t;
    cin >> t;
    while (t--)
    {
        static int n, m, k;
        static int res;
        res = INF;
        cin >> n >> m >> k;
        vector<vector<tuple<int, int, int>>> map(n + 1);
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INF));
        while (k--)
        {
            static int u, v, c, d;
            cin >> u >> v >> c >> d;
            map[u].push_back({d, v, c});
        }
        pq.push({0, 1, 0});
        dp[1][0] = 0;
        while (!pq.empty())
        {
            int time = get<0>(pq.top());
            int now = get<1>(pq.top());
            int cost = get<2>(pq.top());
            pq.pop();
            if (dp[now][cost] < time)
                continue;
            for (int i = 0; i < map[now].size(); i++)
            {
                int next_time = time + get<0>(map[now][i]);
                int next = get<1>(map[now][i]);
                int next_cost = cost + get<2>(map[now][i]);

                if (next_cost > m)
                    continue;
                if (dp[next][next_cost] <= next_time)
                    continue;
                for (int j = next_cost; j <= m; j++)
                    if (dp[next][j] > next_time)
                        dp[next][j] = next_time;
                pq.push({next_time, next, next_cost});
            }
        }

        res = *min_element(dp[n].begin()+1, dp[n].end());
        if (res == INF)
            cout
                << "Poor KCM" << '\n';
        else cout << res << '\n';
    }
    return 0;
}