//baekjoon ps 2098

#include <iostream>
#include <vector>
#include <limits>
#include <functional>
#include <unordered_map>

using namespace std;

int main()
{
    constexpr int INF = numeric_limits<int>::max()/4;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    vector<unordered_map<int, int>> dp(n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    function<int(int, int)> dfs = [&](int now, int visited)
    {
        int res = dp[now][visited];
        if (res != 0)
            return res;
        if (visited == ((1 << n) - 1))
        {
            if (graph[now][0] == 0)
                return INF;
            return graph[now][0];
        }
        res = INF;
        for (int next = 0; next < n; next++)
            if (graph[now][next] != 0)
                if ((visited & (1 << next)) == 0)
                    res = min(res, graph[now][next] + dfs(next, visited | 1 << next));
        dp[now][visited] = res;
        return res;
    };
    cout << dfs(0, 1);
    return 0;
}